#include "learning.h"
using namespace std ;

ValueFeature::ValueFeature()
{
	rawX = NULL ;
	rawY = NULL ;
	X = NULL ;
	Y = NULL ;
}

ValueFeature::~ValueFeature()
{
	if ( this->rawX != NULL )
		gsl_matrix_free(this->rawX) ;
	if ( this->rawY != NULL )
		gsl_vector_free(this->rawY) ;
	if ( this->X != NULL )
		gsl_matrix_free(this->X) ;
	if ( this->Y != NULL )
		gsl_vector_free(this->Y) ;
}

bool ValueFeature::SetParameter( params p )
{
	this->param = p ;
	this->param.newFeatureNum = 1 + p.startNum + (p.leftBNum+p.rightBNum)*2 + (p.leftDNum+p.rightDNum)*2 ;
	p.newFeatureNum = param.newFeatureNum ;

	this->rawX = gsl_matrix_calloc(p.dataNum, p.featureNum) ;
	this->rawY = gsl_vector_calloc(p.dataNum) ;
	this->X = gsl_matrix_calloc(p.dataNum, p.newFeatureNum) ;
	this->Y = gsl_vector_calloc(p.dataNum) ;
    this->W = gsl_matrix_calloc(param.dataNum, param.dataNum) ;
    this->Beta = gsl_vector_calloc(param.newFeatureNum) ;
    this->Xtest = NULL ;

	return true ;
}

bool ValueFeature::ReadRawData()
{
    QString tmp = param.filePath+param.fileName;
    if ( (this->stream=fopen((tmp).toStdString().c_str(), "r")) == NULL )
	{
        qDebug() << "Error when read" << param.fileName ;
		return false ;
	}
	for ( size_t i = 0 ; i < param.dataNum ; i++ )
	{
		double tmp ;
		for ( size_t j = 0 ; j < param.featureNum ; j++ )
		{
			fscanf(this->stream, "%lf", &tmp) ;
			gsl_matrix_set(rawX, i, j, tmp) ;
		}
		fscanf(this->stream, "%lf", &tmp) ;
		gsl_vector_set(rawY, i, tmp) ;
	}
	fclose(stream) ;
	return true ;
}

bool ValueFeature::ProcessDataX( gsl_vector *s, gsl_vector **d )
{
	// 分配空间
	if ( s == NULL )
		return false ;
	if ( *d != NULL )
		return false ;
	*d = gsl_vector_calloc(param.newFeatureNum) ;

	// 设置第1列Feature
	gsl_vector_set(*d, 0, 1.0) ;
	// 设置start部分
	for ( size_t j = 0 ; j < param.startNum ; j++ )
    {
		gsl_vector_set(*d, j+1, gsl_vector_get(s, j)) ;
        gsl_vector_set(*d, j+1, 0) ;
    }
	// 设置Barrier部分
	gsl_vector * tmpVL = gsl_vector_calloc(param.featureNum) ;	// 临时变量
	gsl_vector * tmpDisVLeft = gsl_vector_calloc((param.barrierNum)/2) ;	// 存储左侧门距离
	gsl_vector * tmpDisVRight = gsl_vector_calloc((param.barrierNum)/2) ;	// 存储右侧们距离
	gsl_vector_memcpy(tmpVL, s) ;
	for ( size_t j = param.startNum ; j < param.startNum+param.barrierNum ; j+=2 )
	{
		// 滤掉后面的障碍
        if ( gsl_vector_get(tmpVL, j) < 0 )
		{
			gsl_vector_set(tmpVL, j, this->param.bigNum) ;
			gsl_vector_set(tmpVL, j+1, this->param.bigNum) ;
		}
		// 计算距离
		double x = gsl_vector_get(tmpVL, j) ;
		double y = gsl_vector_get(tmpVL, j+1) ;
		if ( y >= 0 )   // left
		{
			gsl_vector_set(tmpDisVLeft, (j-this->param.startNum)/2, x*x+y*y) ;
			gsl_vector_set(tmpDisVRight, (j-this->param.startNum)/2, this->param.bigNum*this->param.bigNum*2) ;
		}
		else    // right
		{
			gsl_vector_set(tmpDisVLeft, (j-this->param.startNum)/2, this->param.bigNum*this->param.bigNum*2) ;
			gsl_vector_set(tmpDisVRight, (j-this->param.startNum)/2, x*x+y*y) ;
		}
	}
	int begin = 1+param.startNum ;
	for ( int j = begin ; j < begin+param.leftBNum*2 ; j+=2 )
	{
		size_t idx = gsl_vector_min_index(tmpDisVLeft) ;
		double dis = gsl_vector_min(tmpDisVLeft) ;
		double x, y ;
		if ( dis == param.bigNum*param.bigNum*2 )
		{
			x = param.bigNum ;
			y = param.bigNum ;
		}
		else
		{
			x = gsl_vector_get(tmpVL, param.startNum+idx*2) ;
			y = gsl_vector_get(tmpVL, param.startNum+idx*2+1) ;
			gsl_vector_set(tmpVL, param.startNum+idx*2, param.bigNum) ;
			gsl_vector_set(tmpVL, param.startNum+idx*2+1, param.bigNum) ;
			gsl_vector_set(tmpDisVLeft, idx, param.bigNum*param.bigNum*2) ;
		}
        // 负指数处理
        gsl_vector_set(*d, j, exp(-x)) ;
        //gsl_vector_set(*d, j+1, y*exp(-abs(y))) ;
        //gsl_vector_set(*d, j, x) ;
        gsl_vector_set(*d, j+1, 0) ;
	}
	begin = 1 + param.startNum + param.leftBNum*2 ;
	for ( int j = begin ; j < begin+param.rightBNum*2 ; j+=2 )
	{
		size_t idx = gsl_vector_min_index(tmpDisVRight) ;
		double dis = gsl_vector_min(tmpDisVRight) ;
		double x, y ;
		if ( dis == param.bigNum*param.bigNum*2 )
		{
			x = param.bigNum ;
			y = param.bigNum ;
		}
		else
		{
			x = gsl_vector_get(tmpVL, param.startNum+idx*2) ;
			y = gsl_vector_get(tmpVL, param.startNum+idx*2+1) ;
			gsl_vector_set(tmpVL, param.startNum+idx*2, param.bigNum) ;
			gsl_vector_set(tmpVL, param.startNum+idx*2+1, param.bigNum) ;
			gsl_vector_set(tmpDisVRight, idx, param.bigNum*param.bigNum*2) ;
		}
        // 负指数处理
        gsl_vector_set(*d, j, exp(-x)) ;
        //gsl_vector_set(*d, j+1, y*exp(-abs(y))) ;
        //gsl_vector_set(*d, j, x) ;
        gsl_vector_set(*d, j+1, 0) ;
	}
	gsl_vector_free(tmpDisVLeft) ;
	gsl_vector_free(tmpDisVRight) ;

	// 设置Wall部分
	tmpDisVLeft = gsl_vector_calloc(param.wallNum/4) ;
	tmpDisVRight = gsl_vector_calloc(param.wallNum/4) ;
	begin = param.startNum+param.barrierNum ;
	for ( size_t j = begin ; j < begin+param.wallNum-2 ; j+=4 )
	{
		// 获取墙的端点
		double x1 = gsl_vector_get(tmpVL, j) ;
		if ( abs(x1-param.bigNum) < 100 )
		{
			gsl_vector_set(tmpDisVLeft, (j-begin)/4, param.bigNum*param.bigNum*2) ;
			gsl_vector_set(tmpDisVRight, (j-begin)/4, param.bigNum*param.bigNum*2) ;
			continue ;
		}
		double y1 = gsl_vector_get(tmpVL, j+1) ;
		double x2 = gsl_vector_get(tmpVL, j+2) ;
		double y2 = gsl_vector_get(tmpVL, j+3) ;
		// 计算车到墙的距离、垂足坐标
		double a = y2-y1 ;
		double b = x1-x2 ;
		double c = x2*y1-x1*y2 ;
		double d = abs(c)/sqrt(a*a+b*b) ;
		// 暂时不计算角度等。只计算垂直距离
		if ( y1 >= 0 ) // left
		{
			gsl_vector_set(tmpDisVLeft, (j-begin)/4, d) ;
			gsl_vector_set(tmpDisVRight, (j-begin)/4, param.bigNum*param.bigNum*2) ;
		}
		else // right
		{
			gsl_vector_set(tmpDisVLeft, (j-begin)/4, param.bigNum*param.bigNum*2) ;
			gsl_vector_set(tmpDisVRight, (j-begin)/4, d) ;
		}
	}
	begin = 1 + param.startNum + (param.leftBNum+param.rightBNum)*2 ;
	for ( int j = begin ; j < begin+param.leftDNum*2 ; j+=2 )
	{
		size_t idx = gsl_vector_min_index(tmpDisVLeft) ;
		double dis = gsl_vector_min(tmpDisVLeft) ;
		double theta ;
		if ( dis == param.bigNum*param.bigNum*2 )
		{
			theta = 0 ;
		}
		else
		{
			theta = 0 ;
			gsl_vector_set(tmpVL, param.startNum+param.barrierNum+idx*2, param.bigNum) ;
			gsl_vector_set(tmpVL, param.startNum+param.barrierNum+idx*2+1, param.bigNum) ;
			gsl_vector_set(tmpDisVLeft, idx, param.bigNum*param.bigNum*2) ;
		}
        //gsl_vector_set(*d, j, exp(-dis)) ;
        gsl_vector_set(*d, j, 0) ;
		gsl_vector_set(*d, j+1, theta) ;
	}
	begin = 1 + param.startNum + (param.leftBNum+param.rightBNum)*2 + param.leftDNum*2 ;
	for ( int j = begin ; j < begin+param.rightDNum*2 ; j+=2 )
	{
		size_t idx = gsl_vector_min_index(tmpDisVRight) ;
		double dis = gsl_vector_min(tmpDisVRight) ;
		double theta ;
		if ( dis == param.bigNum*param.bigNum*2 )
		{
			theta = 0 ;
		}
		else
		{
			theta = 0 ;
			gsl_vector_set(tmpVL, param.startNum+param.barrierNum+idx*2, param.bigNum) ;
			gsl_vector_set(tmpVL, param.startNum+param.barrierNum+idx*2+1, param.bigNum) ;
			gsl_vector_set(tmpDisVRight, idx, param.bigNum*param.bigNum*2) ;
		}
        //gsl_vector_set(*d, j, exp(-dis)) ;
        gsl_vector_set(*d, j, 0) ;
		gsl_vector_set(*d, j+1, theta) ;
	}

	gsl_vector_free(tmpDisVLeft) ;
	gsl_vector_free(tmpDisVRight) ;

	gsl_vector_free(tmpVL) ;
	return true ;
}

bool ValueFeature::ProcessRawData()
{
	// X部分
	gsl_vector *s = gsl_vector_calloc(param.featureNum) ;
	for ( size_t i = 0 ; i < param.dataNum ; i++ )
	{
		gsl_matrix_get_row(s, this->rawX, i) ;
		gsl_vector *d = NULL ;
		this->ProcessDataX(s, &d) ;
		//this->PrintDataX(s, param.featureNum) ;
		//this->PrintDataX(d, param.newFeatureNum) ;
		gsl_matrix_set_row(this->X, i, d) ;
	}
	gsl_vector_free(s) ;

	// Y部分
	gsl_vector_memcpy(this->Y, this->rawY) ;

	return true ;
}

double ValueFeature::valueFeature( _feature f )
{
	// 第一步：转换成rawXtest
	gsl_vector * rawXtest = gsl_vector_calloc(param.featureNum) ;
	for ( size_t j = 0 ; j < param.featureNum ; j++ )
		gsl_vector_set(rawXtest, j, f.data[j]) ;
	// 第二步：加工成Xtest
    if ( this->Xtest != NULL )
    {
        gsl_vector_free(Xtest) ;
        Xtest = NULL ;
    }
	this->ProcessDataX(rawXtest, &Xtest) ;
	// 第三步：计算W矩阵
	gsl_vector * disX = gsl_vector_calloc(param.newFeatureNum) ;
    gsl_vector * Wv = gsl_vector_calloc(10) ;
    for ( size_t i = 0 ; i < 10 ; i++ )
    {
        gsl_vector_set(Wv, i, -param.bigNum) ;
    }
    gsl_vector * WvIdx = gsl_vector_calloc(10) ;
	for ( size_t i = 0 ; i < param.dataNum ; i++ )
	{
		gsl_matrix_get_row(disX, this->X, i) ;
		gsl_vector_sub(disX, Xtest) ;
		double w = 1 ;
		gsl_blas_ddot(disX, disX, &w) ;
		w = exp(-w/(2*param.k*param.k)) ;
        gsl_matrix_set(W, i, i, 0) ;
        //gsl_vector_set(Wv, i, w) ;
        size_t minIdx = gsl_vector_min_index(Wv) ;
        double min = gsl_vector_min(Wv) ;
        if ( w > min )
        {
            gsl_vector_set(Wv, minIdx, w) ;
            gsl_vector_set(WvIdx, minIdx, i) ;
        }
	}
    for ( size_t i = 0 ; i < 10 ; i++ )
    {
        size_t k = gsl_vector_get(WvIdx, i) ;
        gsl_matrix_set(W, k, k, gsl_vector_get(Wv, i)) ;
    }
    gsl_vector_free(Wv) ;
    gsl_vector_free(WvIdx) ;

	gsl_vector_free(disX) ;
	// 第四步：计算Beta
	gsl_matrix * XtW = gsl_matrix_calloc(param.newFeatureNum, param.dataNum) ;
	gsl_vector * XtWY = gsl_vector_calloc(param.newFeatureNum) ;
	gsl_matrix * U = gsl_matrix_calloc(param.newFeatureNum, param.newFeatureNum) ;
	gsl_vector * S = gsl_vector_calloc(param.newFeatureNum) ;
	gsl_matrix * V = gsl_matrix_calloc(param.newFeatureNum, param.newFeatureNum) ;
	gsl_matrix * T = gsl_matrix_calloc(param.newFeatureNum, param.newFeatureNum) ;
	gsl_matrix * VT = gsl_matrix_calloc(param.newFeatureNum, param.newFeatureNum) ;
	gsl_matrix *VTUt = gsl_matrix_calloc(param.newFeatureNum, param.newFeatureNum) ;
	
	gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1.0, X, W, 0.0, XtW) ;
	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, XtW, X, 0.0, U) ;
    if ( gsl_linalg_SV_decomp_jacobi(U, V, S) != GSL_SUCCESS )
        return 0.5 ;
	for ( size_t j = 0 ; j < param.newFeatureNum ; j++ )
        if ( gsl_vector_get(S, j) != 0 )
            gsl_matrix_set(T, j, j, 1/gsl_vector_get(S, j)) ;
	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, V, T, 0.0, VT) ;
	gsl_blas_dgemm(CblasNoTrans, CblasTrans, 1.0, VT, U, 0.0, VTUt) ;
	gsl_blas_dgemv(CblasNoTrans, 1.0, XtW, Y, 0.0, XtWY) ;
    gsl_blas_dgemv(CblasNoTrans, 1.0, VTUt, XtWY, 0.0, Beta) ;
    gsl_blas_ddot(Beta, Xtest, &result) ;

    gsl_matrix_free(XtW) ;
    gsl_vector_free(XtWY) ;
    gsl_matrix_free(U) ;
    gsl_vector_free(S) ;
    gsl_matrix_free(V) ;
    gsl_matrix_free(T) ;
    gsl_matrix_free(VT) ;
    gsl_matrix_free(VTUt) ;

	return result ;
}

bool ValueFeature::OutputTestData( int TimeStamp )
{
    QString testFile = QString("%1.dat").arg(TimeStamp) ;
    QString tmp = param.filePath+QString("TestFile/")+testFile ;
    FILE * file ;
    if ( (file=fopen((tmp).toStdString().c_str(), "w")) == NULL )
    {
        return false ;
    }
    // output Xtest:
    fprintf(file, "Xtest:\n") ;
    for ( size_t i = 0 ; i < param.newFeatureNum ; i++ )
    {
        fprintf(file, "%f\t", gsl_vector_get(Xtest, i)) ;
    }
    fprintf(file, "\n") ;
    // output Beta:
    fprintf(file, "Beta:\n") ;
    for ( size_t i = 0 ; i < param.newFeatureNum ; i++ )
    {
        fprintf(file, "%f\t", gsl_vector_get(Beta, i)) ;
    }
    fprintf(file, "\n") ;
    // output result:
    fprintf(file, "Result:\t%f\n", result) ;
    // output X,Y,W:
    for ( size_t i = 0 ; i < param.dataNum ; i++ )
    {

        for ( size_t j = 0 ; j < param.newFeatureNum ; j++ )
        {
            fprintf(file, "%f\t", gsl_matrix_get(X, i, j)) ;
        }
        fprintf(file, "%f\t", gsl_vector_get(Y, i)) ;
        fprintf(file, "%f\n", gsl_matrix_get(W, i, i)) ;
    }

    return true ;
}

void ValueFeature::PrintDataX( gsl_vector *d, int len )
{
    for ( size_t j = 0 ; j < len ; j++ )
		cout << gsl_vector_get(d, j) << '\t' ;
	cout << endl ;
}

_feature ValueFeature::GetDataX( int i )
{
	_feature f ;
	gsl_vector * tmp = gsl_vector_calloc(param.featureNum) ;
	gsl_matrix_get_row(tmp, this->rawX, i) ;
	for ( size_t j = 0 ; j < param.featureNum ; j++ )
		f.data[j] = gsl_vector_get(tmp, j) ;
	return f ;
}


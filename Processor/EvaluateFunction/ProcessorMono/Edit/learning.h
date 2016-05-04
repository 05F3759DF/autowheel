#define GSL_DLL

#include <iostream>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>
#include <fstream>
#include <string>
#include <sstream>
#include <QString>
#include <QDebug>
#include "../../../FeatureExtract/ProcessorMulti/processormulti_processor_featureextract_ex.h"


struct params
{
    double k ;
	int dataNum ;		// 总共的样本容量
	int barrierNum ;	// 属于门的特征数量
	int wallNum ;		// 属于墙的特征数量
	int featureNum ;	// 总共的特征数量
	int startNum ;
	int leftBNum ;
	int rightBNum ;
	int leftDNum ;
	int rightDNum ;
	int newFeatureNum ;
	double bigNum ;
    QString filePath ;
    QString fileName ;
};

class ValueFeature
{
private:
	params param ;
	FILE * stream ;

	gsl_matrix * rawX ;
	gsl_vector * rawY ;
	gsl_matrix * X ;
	gsl_vector * Y ;
    gsl_vector * Xtest ;
    gsl_matrix * W ;
    gsl_vector * Beta ;
    double result ;

public:
	ValueFeature() ;
	~ValueFeature() ;
	bool SetParameter( params p ) ;
    bool ReadRawData() ;
	bool ProcessRawData() ;
	bool ProcessDataX( gsl_vector *s, gsl_vector **d ) ;
	double valueFeature( _feature f ) ;
    bool OutputTestData( int TimeStamp ) ;

	void PrintDataX( gsl_vector *d, int len ) ;
	_feature GetDataX( int i ) ;
} ;

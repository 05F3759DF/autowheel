#ifndef CONTROL
#define CONTROL

#include "ProcessorMulti/NoEdit/ProcessorMulti_Processor_Control_PrivFunc.h"

void generateControlCmd(ProcessorMulti_Processor_Control_Vars* vars,
                        double sx, double sy,
                        double hx, double hy,
                        double tx, double ty);

#endif // CONTROL


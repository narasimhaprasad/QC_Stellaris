

#ifndef QC_STELLARIS_H_
#define QC_STELLARIS_H_

//Standard C header files
#include "stdint-gcc.h"


//Stellarisware header files
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/i2c.h"
#include "driverlib/fpu.h"
#include "driverlib/ssi.h"

//Own header files
#include "QC_Data.h"

void ADS8361_DataInt(void);



#endif /* QC_STELLARIS_H_ */

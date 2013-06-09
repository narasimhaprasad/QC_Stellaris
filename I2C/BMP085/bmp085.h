/*
 * Local header file for all barometer variables
 */

#ifndef BMP085_H_
#define BMP085_H_

#include "I2C/QC_I2C.h"
#include "math.h"

#define BMP085_OSS                  0	//oversampling

#define I2C_ID_BMP085 0x77	//Device ID


//Variables
int16_t AC1, AC2, AC3, B1, B2, B3, B5, B6, MB, MC, MD;
uint16_t AC4, AC5, AC6;
int32_t UTemp, UPressure, UT, UP, X1, X2, X3, p, CP, CT, CA;
uint32_t B4, B7;

#endif /* BMP085_H_ */

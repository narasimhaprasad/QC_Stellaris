/*
 * Data variables.
 */

#ifndef QC_DATA_H_
#define QC_DATA_H_

#include "stdint.h"

typedef struct{
	uint32_t Cycle1;
	uint32_t Cycle2;
	uint32_t Cycle3;
	uint32_t Cycle4;
	uint32_t Period;
}Duty_t;	//Duty Cycle variables

typedef struct{
	int32_t Temperature;	//Temperature
	int32_t Pressure;	//Pressure
	int32_t Altitude;	//Altitude
}BMP085_t;	//Barometer variables

typedef struct{
	int16_t x;	//X axis
	int16_t y;	//Y axis
	int16_t z;	//Z axis
}HMC5883L_t;	//Digital compass variables

typedef struct{
	int16_t x;	//x axis
	int16_t y;	//y axis
	int16_t z;	//z axis
	int8_t Temperature;	// temperature
}L3G4200D_t;

typedef struct{
	uint32_t Period;
	uint32_t Pulse;
	uint32_t data[2];
}ADS8361_t;

Duty_t Duty;
BMP085_t BMP085;
HMC5883L_t HMC5883L;
L3G4200D_t L3G4200D;
#endif /* QC_DATA_H_ */

#include "bmp085.h"
#include "QC_BMP085.h"

/*
 * @brief: Read the co-efficients required for meaurement
 * @param[in]: none
 * @param[out]: none
 */
void bmp085_ReadCoeffs(void) {
	uint8_t b[22];
	i2c_ReadBuf(I2C_ID_BMP085, 0xAA, 22, b);

	AC1 = (int16_t) ((((uint16_t) b[0]) << 8) | (uint16_t) b[1]);
	AC2 = (int16_t) ((((uint16_t) b[2]) << 8) | (uint16_t) b[3]);
	AC3 = (int16_t) ((((uint16_t) b[4]) << 8) | (uint16_t) b[5]);

	AC4 = (((uint16_t) b[6]) << 8) | (uint16_t) b[7];
	AC5 = (((uint16_t) b[8]) << 8) | (uint16_t) b[9];
	AC6 = (((uint16_t) b[10]) << 8) | (uint16_t) b[11];

	B1 = (int16_t) ((((uint16_t) b[12]) << 8) | (uint16_t) b[13]);
	B2 = (int16_t) ((((uint16_t) b[14]) << 8) | (uint16_t) b[15]);
	MB = (int16_t) ((((uint16_t) b[16]) << 8) | (uint16_t) b[17]);
	MC = (int16_t) ((((uint16_t) b[18]) << 8) | (uint16_t) b[19]);
	MD = (int16_t) ((((uint16_t) b[20]) << 8) | (uint16_t) b[21]);
}

/*
 * @brief: Read uncompensated temperature
 * @param[in]: none
 * @param[out]: Uncompensated temperature
 */
int32_t bmp085_UTemp(void){
	uint8_t b[2];
	i2c_WriteByte(I2C_ID_BMP085,0xF4,0x2E);
	ROM_SysCtlDelay(5*(ROM_SysCtlClockGet()/3000));
	i2c_ReadBuf(I2C_ID_BMP085, 0xF6, 2, b);
	return UTemp = (uint32_t)b[0]<<8 | b[1] ;
}

/*
 * @brief: Read uncompensated pressure
 * @param[in]: none
 * @param[out]: uncompensated pressure
 */
int32_t bmp085_UPressure(void){
	uint8_t b[3];
	i2c_WriteByte(I2C_ID_BMP085, 0xF4, 0x34 + (BMP085_OSS << 6));
	ROM_SysCtlDelay(5*(ROM_SysCtlClockGet()/3000));
	i2c_ReadBuf(I2C_ID_BMP085, 0xF6, 3, b);
	return UPressure = ((b[0]<<16) | (b[1]<<8) | b[2])>>(8-BMP085_OSS);
}

/*
 * @brief: Read compensated temperature
 * @param[in]: none
 * @param[out]: compensated temperature
 */
int32_t bmp085_CTemp(void){
	X1 = ((UT-AC6)*AC5)>>15;
	X2 = (MC<<11)/(X1+MD);
	B5 = X1+X2;
	return CT = ((B5+8)>>4);
}

/*
 * @brief: Read compensated pressure
 * @param[in]: none
 * @param[out]: compensated pressure
 */
int32_t bmp085_CPressure(void){
	B6 = B5-4000;
	X1 = (B2*(B6*B6>>12))>>11;
	X2 = (AC2*B6)>>11;
	X3 = X1+X2;
	B3 = ((((AC1<<2)+X3)<<BMP085_OSS)+2)>>2;
	X1 = AC3*B6>>13;
	X2 = (B1*(B6*B6>>12))>>16;
	X3 = ((X1+X2)+2)>>2;
	B4 = AC4*(uint32_t)(X3+32768)>>15;
	B7 = (((uint32_t)UP-B3)*(50000>>BMP085_OSS));
	if(B7< 0x80000000)
		p = (B7*2)/B4;
	else
		p = (B7/B4)<<1;

	X1 = (p>>8)*(p>>8);
	X1 = (X1*3038)>>16;
	X2 = (-7357*p)>>16;
	return CP = ( p + ((X1+X2+3791)>>4));
}
/*
 * @brief: Calculate altitude
 * @param[in]: ptr to altitude
 * @param[out]: none
 */
void bmp085_CAltitude(int32_t *dataA){
	*dataA = (44330*(1-pow(((float)CP/101325),0.1902)));
}

/*
 * @brief: Get all the data from BMP085
 * @param[in]: ptr datamatrix. compensated pressure and temperature value is stored here
 * @parm[out]: none
 */
void bmp085_GetData(int32_t *dataT, int32_t *dataP){
	UT = bmp085_UTemp();
	UP = bmp085_UPressure();
	*dataT = bmp085_CTemp();
	*dataP = bmp085_CPressure();
}


#include "adxl345.h"

/*
 * @brief: Test ADXL345 module address
 * @param[in]: none
 * @param[out]: 1 if successful, 0 if not
 */
uint8_t adxl345_test(void){
	uint8_t temp;
	temp = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_DEVID);
	return temp == 0xE5 ? 1 : 0;
}

/*
 * @ brief: Read threshold value for tap interrupts
 * @ param[in]: ptr to variable
 * @ param[out]: none
 */
void  adxl345_ReadTapThresh(uint8_t *tap){
	*tap = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_TAP);
}

/*
 * @ brief: Write threshold value for tap interrupts
 * @ param[in]: Threshold value
 * @ param[out]: none
 */
void adxl345_WriteTapThresh(uint8_t tap){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_TAP, tap);
}

/*
 * @brief: Read X axis OffSet
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadXOffSet(int8_t *xoff){
	*xoff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_OFSX);
}

/*
 * @brief: Read Y axis offset
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadYOffSet(int8_t *yoff){
	*yoff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_OFSY);
}

/*
 * @brief: Read Z axis offset
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadZOffSet(int8_t *zoff){
	*zoff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_OFSZ);
}

/*
 * @brief: Read X, Y, Z axis offset
 * @param[in]: ptr to variables
 * @param[out]: none
 */
void adxl345_ReadXYZOffSet(int8_t *xoff, int8_t *yoff, int8_t *zoff){
	*xoff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_OFSX);
	*yoff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_OFSY);
	*zoff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_OFSZ);
}

/*
 * @brief: Set X axis OffSet
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteXOffSet(int8_t xoff){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_OFSX, xoff);
}

/*
 * @brief: Set Y axis OffSet
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteYOffSet(int8_t yoff){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_OFSY, yoff);
}

/*
 * @brief: Set  axis OffSet
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteZOffSet(int8_t zoff){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_OFSZ, zoff);
}

/*
 * @brief: Set X,Y,Z axis offset
 * @param[in]: X offset value , Y offset value, Z offset value
 * @param[out]: none
 */
void adxl_WriteXYZOffSet(int8_t *xoff, int8_t *yoff, int8_t *zoff){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_OFSX, *xoff);
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_OFSY, *yoff);
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_OFSZ, *zoff);
}

/*
 * @brief: Read the maximum time an event must be above Tap threshold to qualify as a tap
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadDur(uint8_t *dur){
	*dur = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_DUR);
}

/*
 * @brief: Write the maximum time an event must be above Tap threshold to qualify as a tap
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteDur(uint8_t dur){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_DUR, dur);
}

/*
 * @brief: Read the wait time from the detection of a tap event to the start of the window
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadLat(uint8_t *lat){
	*lat = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_LATENT);
}

/*
 * @brief: Read the wait time from the detection of a tap event to the start of the window
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteLat(uint8_t lat){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_LATENT, lat);
}

/*
 * @brief: Read the amount of time after expiration of the latency time during which a second tap can begin
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadWindow(uint8_t *win){
	*win = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_WINDOW);
}

/*
 * @brief: Read the amount of time after the expiration of the latency time during which a second time valid tap can begin
 * @param[in]: value
 * @param[out]: none
 */
void adxl345_WriteWindow(uint8_t win){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_WINDOW, win);
}

/*
 * @brief: Read the threshold value for detecting activity
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadAct(uint8_t *act){
	*act = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_ACT);
}

/*
 * @brief: Write the threshold value for detecting activity
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteAct(uint8_t act){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_ACT, act);
}

/*
 * @brief: Read the threshold value for detecting inactivity
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadThreshInact(int8_t *inact){
	*inact = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_INACT);
}

/*
 * @brief: Write the threshold value for detecting inactivity
 * @param[in]: value
 * @param[out]: none
 */
void adxl345_WriteThreshInact(int8_t inact){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_INACT, inact);
}

/*
 * @brief: Read the amount of time that acceleration must be less than, for inactivity to be declared
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadTimeInact(uint8_t *timinact){
	*timinact = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_TIME_INACT);
}

/*
 * @brief: Write the amount of time that acceleration must be less than, for inactivity to be declared
 * @param[in]: Value
 * @param[out]: none
 */
void adxl345_WriteTimeInact(uint8_t timinact){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_TIME_INACT, timinact);
}

/*
 * @brief: Control AC/DC coupled operation
 * @param[in]: Enable AC coupled operation for Activity
 * 					ADXL345_ACT_ACDC_ENABLE, ADXL345_ACT_ACDC_DISABLE
 * 			   Enable X axis for activity
 * 			   		ADXL345_ACTX_ENABLE, ADXL345_ACTX_DISABLE
 * 			   Enable Y axis for activity
 * 			   		ADXL345_ACTY_ENABLE, ADXL345_ACTY_DISABLE
 * 			   Enable Z axis for activity
 * 			   		ADXL345_ACTZ_ENABLE, ADXL345_ACTZ_DISABLE
 * 			   Enable AC coupled operation for Inactivity
 * 					ADXL345_INACT_ACDC_ENABLE, ADXL345_INACT_ACDC_DISABLE
 * 			   Enable X axis for inactivity
 * 			   		ADXL345_INACTX_ENABLE, ADXL345_INACTX_DISABLE
 * 			   Enable Y axis for inactivity
 * 			   		ADXL345_INACTY_ENABLE, ADXL345_INACTY_DISABLE
 * 			   Enable Z axis for inactivity
 * 			   		ADXL345_INACTZ_ENABLE, ADXL345_INACTZ_DISABLE
 * @param[out]: none
 */
void adxl345_WriteACDC(uint8_t ActEN, uint8_t ActX, uint8_t ActY, uint8_t ActZ, uint8_t InActEN, uint8_t InActX, uint8_t InActY, uint8_t InActZ){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_ACT_INACT_CTL, ActEN|ActX|ActY|ActZ|InActEN|InActX|InActY|InActZ);
}

/*
 * @brief: Read the configuration of the Activity Inactivity configuration register
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadACDC(uint8_t *acdc){
	*acdc = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_ACT_INACT_CTL);
}

/*
 * @brief: Read the FreeFall threshold value
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadThreshFF(uint8_t *threshff){
	*threshff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_FF);
}

/*
 * @brief: Write the FreeFall threshold value
 * @param[in]: value
 * @param[out]: none
 */
void adxl345_WriteThreshFF(uint8_t threshff){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_THRESH_FF, threshff);
}

/*
 * @brief: Read the FreeFall threshold time
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadTimeFF(uint8_t *timeff){
	*timeff = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_TIME_FF);
}

/*
 * @brief: Write the FreeFall time threshold
 * @param[in]: value
 * @param[out]: none
 */
void adxl345_WriteTimeFF(uint8_t timeff){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_TIME_FF, timeff);
}


/*
 * @brief: Read the suppress, tap x/y/z data
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadTapAxes(uint8_t *tap_axes){
	*tap_axes = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_TAP_AXES);
}

/*
 * @brief: Write to TAP_AXES register
 * @param[in]: Suppres bit
 * 				ADXL345_TAPAXES_SUP_ENABLE, ADXL345_TAPAXES_SUP_DISABLE
 * 			   TapX bit
 * 			   	ADXL345_TAPAXES_TAPX_ENABLE, ADXL345_TAPAXES_TAPX_DISABLE
 * 			   TapY bit
 * 			   	ADXL345_TAPAXES_TAPY_ENABLE, ADXL345_TAPAXES_TAPY_DISABLE
 * 			   TapZ bit
 * 			   	ADXL345_TAPAXES_TAPZ_ENABLE, ADXL345_TAPAXES_TAPZ_DISABLE
 *
 */
void adxl345_WriteTapAxes(uint8_t sup, uint8_t tapx, uint8_t tapy, uint8_t tapz){
	i2c_WriteByte(I2C_ID_ADXL345, ADXL345_RA_TAP_AXES , sup|tapx|tapy|tapz);
}

/*
 * @brief: Read Act/Tap status
 * @param[in]: ptr to variable
 * @param[out]: none
 */
void adxl345_ReadActTapStatus(uint8_t *status){
	*status = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_ACT_TAP_STATUS);
}

void adxl345_ReadBWRate(uint8_t *bw){
	*bw = i2c_ReadByte(I2C_ID_ADXL345, ADXL345_RA_BW_RATE);
}

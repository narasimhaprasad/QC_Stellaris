/*
 * hmc5883l.h
 *
 *  Created on: Apr 14, 2013
 *      Author: prasad
 */

#ifndef HMC5883L_H_
#define HMC5883L_H_

#include "I2C/QC_I2C.h"
#include "arm_math.h"


#define I2C_ID_HMC5883L			    0x1E


#define HMC5883L_RA_CONFIG_A	    0x00
#define HMC5883L_RA_CONFIG_B	    0x01
#define HMC5883L_RA_MODE		    0x02
#define HMC5883L_DATA			    0x03

#define HMC5883L_RA_STATUS          0x09
#define HMC5883L_RA_ID_A            0x0A
#define HMC5883L_RA_ID_B            0x0B
#define HMC5883L_RA_ID_C            0x0C

#define HMC5883L_AVERAGING_1        0x00<<5
#define HMC5883L_AVERAGING_2        0x01<<5
#define HMC5883L_AVERAGING_4        0x02<<5
#define HMC5883L_AVERAGING_8        0x03<<5

#define HMC5883L_RATE_0P75          0x00<<2
#define HMC5883L_RATE_1P5           0x01<<2
#define HMC5883L_RATE_3             0x02<<2
#define HMC5883L_RATE_7P5           0x03<<2
#define HMC5883L_RATE_15            0x04<<2
#define HMC5883L_RATE_30            0x05<<2
#define HMC5883L_RATE_75            0x06<<2

#define HMC5883L_BIAS_NORMAL        0x00
#define HMC5883L_BIAS_POSITIVE      0x01
#define HMC5883L_BIAS_NEGATIVE      0x02

#define HMC5883L_GAIN_1370          0x00<<5
#define HMC5883L_GAIN_1090          0x01<<5
#define HMC5883L_GAIN_820           0x02<<5
#define HMC5883L_GAIN_660           0x03<<5
#define HMC5883L_GAIN_440           0x04<<5
#define HMC5883L_GAIN_390           0x05<<5
#define HMC5883L_GAIN_330           0x06<<5
#define HMC5883L_GAIN_220           0x07<<5

#define HMC5883L_MODE_CONTINUOUS    0x00
#define HMC5883L_MODE_SINGLE        0x01
#define HMC5883L_MODE_IDLE          0x02

#define HMC5883L_STATUS_LOCK_BIT    1
#define HMC5883L_STATUS_READY_BIT   0

#define HMC5883L_MAX_5				575
#define HMC5883L_MIN_5				243
#define HMC5883L_MAX_6				487
#define HMC5883L_MIN_6				206
#define HMC5883L_MAX_7				339
#define HMC5883L_MIN_7				143


int16_t xyz[3], Testx, Testy, Testz, Testxyz[3], TestMax, TestMin, xyz_comp_num[3]={1,1,1}, xyz_comp_den[3]={1,1,1};
uint32_t TestMaxInd, TestMinInd;


#endif /* HMC5883L_H_ */

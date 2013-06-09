#include "hmc5883l.h"

/*
 * @brief: Configure the HMC5883L registers A,B
 * @param[in]: none
 * @param[out]: none
 */
void hmc5883l_Config(void){
	i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_CONFIG_A, HMC5883L_AVERAGING_8 | HMC5883L_RATE_15 | HMC5883L_BIAS_NORMAL);
	i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_CONFIG_B, HMC5883L_GAIN_1090);
}

/*
 * @brief: Read all 3 axes of HMC5883L
 * @param[in]: ptr output to individual axes
 * @param[out]: none
 */
void hmc5883l_ReadXYZ(int16_t *x, int16_t *y, int16_t *z){
	uint8_t b[6];
	i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_MODE, HMC5883L_MODE_SINGLE);
	ROM_SysCtlDelay(6*(ROM_SysCtlClockGet()/3000));
	i2c_ReadBuf(I2C_ID_HMC5883L, HMC5883L_DATA, 6, b);
	*x = ((int16_t)(((uint16_t)b[0]<<8) | (uint16_t)b[1]))*xyz_comp_num[0]/xyz_comp_den[0];
	*y = ((int16_t)(((uint16_t)b[2]<<8) | (uint16_t)b[3]))*xyz_comp_num[1]/xyz_comp_den[1];
	*z = ((int16_t)(((uint16_t)b[4]<<8) | (uint16_t)b[5]))*xyz_comp_num[2]/xyz_comp_den[2];
}

/*
 * @brief: Perform Selftest
 * @param[in]: none
 * @param[out]: Selftest success result. 1:Gain=5. 2:Gain=6. 3:Gain=7. 4:Test unsuccessful
 */
uint8_t hmc5883l_SelfTest(void){
	i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_CONFIG_A, HMC5883L_AVERAGING_8 | HMC5883L_RATE_15 | HMC5883L_BIAS_POSITIVE);
	i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_CONFIG_B, HMC5883L_GAIN_390);
	hmc5883l_ReadXYZ(&Testx, &Testy, &Testz);
	Testxyz[0] = Testx;
	Testxyz[1] = Testy;
	Testxyz[2] = Testz;
	arm_max_q15(Testxyz, 3, &TestMax, &TestMaxInd);
	arm_min_q15(Testxyz, 3, &TestMin, &TestMinInd);
	if(TestMax<HMC5883L_MAX_5 && TestMin>HMC5883L_MIN_5){
		hmc5883l_Config();
		return 1;
	}
	else{
		i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_CONFIG_B, HMC5883L_GAIN_330);
		hmc5883l_ReadXYZ(&Testx, &Testy, &Testz);
		Testxyz[0] = Testx;
		Testxyz[1] = Testy;
		Testxyz[2] = Testz;
		arm_max_q15(Testxyz, 3, &TestMax, &TestMaxInd);
		arm_min_q15(Testxyz, 3, &TestMin, &TestMinInd);
		if(TestMax<HMC5883L_MAX_6 && TestMin>HMC5883L_MIN_6){
			hmc5883l_Config();
			return 2;
		}
		else{
			i2c_WriteByte(I2C_ID_HMC5883L, HMC5883L_RA_CONFIG_B, HMC5883L_GAIN_330);
			hmc5883l_ReadXYZ(&Testx, &Testy, &Testz);
			Testxyz[0] = Testx;
			Testxyz[1] = Testy;
			Testxyz[2] = Testz;
			arm_max_q15(Testxyz, 3, &TestMax, &TestMaxInd);
			arm_min_q15(Testxyz, 3, &TestMin, &TestMinInd);
			if(TestMax<HMC5883L_MAX_7 && TestMin>HMC5883L_MIN_7){
				hmc5883l_Config();
				return 3;
			}
			else{
				hmc5883l_Config();
				return 4;
			}
		}
	}
}

/*
 * @brief: Perform temperature compensation
 * @param[in]: none
 * @param[out]: none
 */
void hmc5883l_TempComp(void){
	uint8_t i;
	for(i=0;i<3;i++){
		xyz_comp_num[i] = Testxyz[i];
	}
	i = hmc5883l_SelfTest();
	if(i != 4){
		for(i=0;i<3;i++){
			xyz_comp_den[i] = Testxyz[i];
		}
	}
	else{
		for(i=0;i<3;i++){
			xyz_comp_num[i] = 1;
			xyz_comp_den[i] = 1;
		}
	}
}



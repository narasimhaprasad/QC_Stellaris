
#include "l3g4200d.h"
#include "QC_L3G4200D.h"

/*
 * @brief: Test connection for l3g4200d
 * @param[in]: none
 * @param[out]: Test result, 1: Successful, 0: Not
 */
uint8_t l3g4200d_Test(void)
{
	uint8_t temp;
	temp = i2c_ReadByte(I2C_ID_L3G4200D, WHO_AM_I);
	return temp == 0xD3 ? 1 :  0;
}

/*
 * @brief: Configure data rate, bandwidth and enable axis measurement
 * @param[in]: Data rate and bandwidth
 * 				Acceptable values:
 * 			     ODR100FC12P5
 *			     ODR100FC25
 *			     ODR200FC12P5
 *			     ODR200FC25
 *			     ODR200FC50
 *			     ODR200FC70
 *			     ODR400FC20
 *			     ODR400FC25
 *			     ODR400FC50
 *			     ODR400FC110
 *			     ODR800FC30
 *			     ODR800FC35
 *			     ODR800FC50
 *			     ODR800FC110
 * @param[out]: None
 */
void l3g4200d_ConfigReg1(uint32_t odr)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG1, odr|Normal|Zen|Yen|Xen);

}

/*
 * @brief: Power down l3g4200d
 * @param[in]: none
 * @param[out]: none
 */
void l3g4200d_PowerDown(void)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG1, PD);
}

/*
 * @brief: Sleep l3g4200d
 * @param[in]: none
 * @param[out]: none
 */
void l3g4200d_Sleep(void)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG1, Sleep);
}

/*
 * @brief: Configure HPF behavior and cutoff frequency
 * @param[in]: HPF behavior.
 * 				RESET_FILTER
 *				REF_SIG_FILTER
 *				NORMAL_MODE
 *				AUTORESET
 *			   HPF Cut off Frequency ODRxxxHPFCy
 *				x : 100, 200, 400, 	800
 *				y : 30, 15, 8, 4, 2, 1, 0P5, 0P2, 0P1, 0P05, 0P02, 0P02
 *				For available refer Table 27 in the datasheet
 * @param[out]: none
 */
void l3g4200d_ConfigReg2(uint32_t bhr, uint32_t hpf)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG2, bhr|hpf);
}

/*
 * @brief: Configure interrupts on L3G4200D
 * @param[in]: Interrupts to enable. A combination of the followwing is possible
 * 				I1_Int1
 *              I1_BOOT
 *              H_LACTIVE
 *              PP_OD
 *              I2_DRDY
 *              I2_WTM
 *              I2_ORUN
 *              I2_EMPTY
 * @param[out]: None
 */
void l3g4200d_ConfigReg3(uint32_t intr)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG3, 0x00);
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG3, intr);
}

/*
 * @brief: Configure data O/P method
 * @param[in]: Data update:
 * 				CONTINOUS_UPDATE/BATCH_UPDATE
 * 			   Endian
 * 			    BIG_ENDIAN/LITTLE_ENDIAN
 * 			   Data resolution
 * 			    DPSx. x = 250, 500, 2000
 * @param[out]: none
 */
void l3g4200d_DataConfig(uint32_t upd, uint32_t end, uint32_t res)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG4, upd|end|res);
	switch (res){
	case 0x00<<4:
			DpsRes = 875;
	break;

	case 0x01<<4:
			DpsRes = 1750;
	break;

	case 0x02<<4:
			DpsRes = 7000;
	break;
	}


}

/*
 * @brief: Configure self test
 * @param[in]: Self test
 * 				DISABLE, POSITIVE_SELF_TEST, NEUTRAL_SELF_TEST, NEGATIVE_SELF_TEST
 * @param[out]: none
 */
void l3g4200d_SelfTest(uint32_t test)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG4, test);
}

/*
 * @brief: Configure SPI
 * @param[in]: WIRE_INT_4, WIRE_INT_3
 * @param[out]: none
 */
void l3g4200d_SPI(uint32_t spi)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG4, spi);
}

/*
 * @brief: Configure boot mode
 * @param[in]: BOOT_NORMAL, BOOT_MEM
 * @param[out]: none
 */
void l3g4200d_Boot(uint32_t boot)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG5, boot);
}

/*
 * @brief: Configure FIFO behaviour
 * @param[in]: FIFO_DISABLE, FIFO_ENABLE
 * @param[out]: none
 */
void l3g4200d_FIFO(uint32_t fifo)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG5, fifo);
}

/*
 * @brief: Enable HPF
 * @param[in]: HIGH_PASS_DISABLE, HIGH_PASS_ENABLE
 * @param[out]: none
 */
void l3g4200d_HPF(uint32_t hpf)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG5, hpf);
}

/*
 * @brief: Int1 selection configuration
 * @param[in]: NON_HPF_FILT_INT, HPF_FILT_INT, LPF_FILT_INT, HPF_LPF_INT
 * @param[out]: none
 */
void l3g4200d_INT1(uint32_t int1)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG5, int1);
}

/*
 * @brief: Out selection configuration
 * @param[in]: DATA_NON_HPF, , DATA_LPF, DATA_HPF_LPF
 * @param[out]: none
 */
void l3g4200d_OutSel(uint32_t out)
{
	i2c_WriteByte(I2C_ID_L3G4200D, CTRL_REG5, out);
}

/*
 * @brief: Read X,Y, Z  angular rates
 * @param[in]: ptr to x, y and z data points
 * @param[out]: none
 */
void l3g4200d_ReadXYZ(int16_t *x, int16_t *y, int16_t *z)
{
	uint8_t b[2];
	i2c_ReadBuf(I2C_ID_L3G4200D, OUT_X_L, 2, b);
	*x = (int16_t)((uint16_t)b[0]|(uint16_t)b[1]<<8);
	i2c_ReadBuf(I2C_ID_L3G4200D, OUT_Y_L, 2, b);
	*y = (int16_t)((uint16_t)b[0]|(uint16_t)b[1]<<8);
	i2c_ReadBuf(I2C_ID_L3G4200D, OUT_Z_L, 2, b);
	*z = (int16_t)((uint16_t)b[0]|(uint16_t)b[1]<<8);
}

/*
 * @brief: Read temperature
 * @param[in]: ptr to temp data
 * @param[out]: none
 */
void l3g4200d_ReadTemp(int8_t *temp)
{
	uint8_t b;
	b =  i2c_ReadByte(I2C_ID_L3G4200D, OUT_TEMP);
	*temp = (int8_t)(40 - b);
}

/*
 * @brief: Get calculated values
 * @param[in]: ptr to angle data
 * @param[out]: none
 */
void l3g4200d_ReadCalcXYZ(int16_t *x, int16_t *y, int16_t *z)
{
	int16_t tempx, tempy, tempz;
	l3g4200d_ReadXYZ(&tempx, &tempy, &tempz);
	*x = tempx*DpsRes/1000000;
	*y = tempy*DpsRes/1000000;
	*z = tempz*DpsRes/1000000;
}


//Main Includes
#include "QC_Stellaris.h"
#include "GPIO/QC_GPIO.h"
#include "I2C/QC_I2C.h"
#include "I2C/BMP085/QC_BMP085.h"
#include "I2C/HMC5883L/QC_HMC5883L.h"
#include "I2C/L3G4200D/QC_L3G4200D.h"


int main(void)
{
	ROM_FPUEnable();
	ROM_FPUStackingEnable();

	ROM_SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);	//Set processor at 40MHz
	QC_GPIO_Init();
	i2c_Config();	//Configure I2C0 Master
	bmp085_ReadCoeffs();


//Debug
//	hmc5883l_Config();	//Configure compass

//	temp = l3g4200d_Test();
//	l3g4200d_ConfigReg1(ODR100FC25);
//	l3g4200d_DataConfig(STREAM_MODE, BIG_ENDIAN, DPS500);
	while(1)
	{
				bmp085_GetData(&BMP085.Temperature, &BMP085.Pressure);
				bmp085_CAltitude(&BMP085.Altitude);
		//		l3g4200d_ReadCalcXYZ(&L3G4200D.x, &L3G4200D.y, &L3G4200D.z);
		//		l3g4200d_ReadTemp(&L3G4200D.Temperature);
		//		hmc5883l_ReadXYZ(&HMC5883L.x, &HMC5883L.y, &HMC5883L.z);	//Read compass data
	}
}

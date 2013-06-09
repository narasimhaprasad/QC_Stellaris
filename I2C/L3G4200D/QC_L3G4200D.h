
#ifndef QC_L3G4200D_H_
#define QC_L3G4200D_H_

#include "l3g4200d.h" // To allow for variable definitions

uint8_t l3g4200d_Test(void);
void l3g4200d_ConfigReg1(uint32_t odr);
void l3g4200d_PowerDown(void);
void l3g4200d_PowerDown(void);
void l3g4200d_Sleep(void);
void l3g4200d_ConfigReg2(uint32_t bhr, uint32_t hpf);
void l3g4200d_ConfigReg3(uint32_t intr);
void l3g4200d_DataConfig(uint32_t upd, uint32_t end, uint32_t res);
void l3g4200d_SelfTest(uint32_t test);
void l3g4200d_SelfTest(uint32_t test);
void l3g4200d_SPI(uint32_t spi);
void l3g4200d_Boot(uint32_t boot);
void l3g4200d_FIFO(uint32_t fifo);
void l3g4200d_HPF(uint32_t hpf);
void l3g4200d_INT1(uint32_t int1);
void l3g4200d_OutSel(uint32_t out);
void l3g4200d_ReadXYZ(int16_t *x, int16_t *y, int16_t *z);
void l3g4200d_ReadTemp(int8_t *temp);
void l3g4200d_ReadCalcXYZ(int16_t *x, int16_t *y, int16_t *z);



#endif /* QC_L3G4200D_H_ */

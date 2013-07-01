
#ifndef QC_L3G4200D_H_
#define QC_L3G4200D_H_

extern uint8_t l3g4200d_Test(void);
extern void l3g4200d_ConfigReg1(uint32_t odr);
extern void l3g4200d_PowerDown(void);
extern void l3g4200d_PowerDown(void);
extern void l3g4200d_Sleep(void);
extern void l3g4200d_ConfigReg2(uint32_t bhr, uint32_t hpf);
extern void l3g4200d_ConfigReg3(uint32_t intr);
extern void l3g4200d_DataConfig(uint32_t upd, uint32_t end, uint32_t res);
extern void l3g4200d_SelfTest(uint32_t test);
extern void l3g4200d_SelfTest(uint32_t test);
extern void l3g4200d_SPI(uint32_t spi);
extern void l3g4200d_Boot(uint32_t boot);
extern void l3g4200d_FIFO(uint32_t fifo);
extern void l3g4200d_HPF(uint32_t hpf);
extern void l3g4200d_INT1(uint32_t int1);
extern void l3g4200d_OutSel(uint32_t out);
extern void l3g4200d_ReadXYZ(int16_t *x, int16_t *y, int16_t *z);
extern void l3g4200d_ReadTemp(int8_t *temp);
extern void l3g4200d_ReadCalcXYZ(int16_t *x, int16_t *y, int16_t *z);



#endif /* QC_L3G4200D_H_ */

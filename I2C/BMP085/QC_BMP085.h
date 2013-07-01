#ifndef QC_BMP085_H_
#define QC_BMP085_H_

extern void bmp085_ReadCoeffs(void);
extern int32_t bmp085_UTemp(void);
extern int32_t bmp085_UPressure(void);
extern int32_t bmp085_CTemp(void);
extern int32_t bmp085_CPressure(void);
extern void bmp085_CAltitude(int32_t *dataA);
extern void bmp085_GetData(int32_t *dataT, int32_t *dataP);

#endif /* QC_BMP085_H_ */

#ifndef QC_BMP085_H_
#define QC_BMP085_H_

void bmp085_ReadCoeffs(void);
int32_t bmp085_UTemp(void);
int32_t bmp085_UPressure(void);
int32_t bmp085_CTemp(void);
int32_t bmp085_CPressure(void);
void bmp085_CAltitude(int32_t *dataA);
void bmp085_GetData(int32_t *dataT, int32_t *dataP);

#endif /* QC_BMP085_H_ */

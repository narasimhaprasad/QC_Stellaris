#ifndef QC_ADXL345_H_
#define QC_ADXL345_H_

extern uint8_t adxl345_test(void);
extern void  adxl345_ReadTapThresh(uint8_t *tap);
extern void adxl345_WriteTapThresh(uint8_t tap);
extern void adxl345_ReadXOffSet(int8_t *xoff);
extern void adxl345_ReadYOffSet(int8_t *yoff);
extern void adxl345_ReadZOffSet(int8_t *zoff);
extern void adxl345_ReadXYZOffSet(int8_t *xoff, int8_t *yoff, int8_t *zoff);
extern void adxl345_WriteXOffSet(int8_t xoff);
extern void adxl345_WriteYOffSet(int8_t yoff);
extern void adxl345_WriteZOffSet(int8_t zoff);
extern void adxl_WriteXYZOffSet(int8_t *xoff, int8_t *yoff, int8_t *zoff);
extern void adxl345_ReadDur(uint8_t *dur);
extern void adxl345_WriteDur(uint8_t dur);
extern void adxl345_ReadLat(uint8_t *lat);
extern void adxl345_WriteLat(uint8_t lat);
extern void adxl345_ReadWindow(uint8_t *win);
extern void adxl345_WriteWindow(uint8_t win);
extern void adxl345_ReadAct(uint8_t *act);
extern void adxl345_WriteAct(uint8_t act);
extern void adxl345_ReadThreshInact(int8_t *inact);
extern void adxl345_WriteThreshInact(int8_t inact);
extern void adxl345_ReadTimeInact(uint8_t *timinact);
extern void adxl345_WriteTimeInact(uint8_t timinact);
extern void adxl345_WriteACDC(uint8_t ActEN, uint8_t ActX, uint8_t ActY, uint8_t ActZ, uint8_t InActEN, uint8_t InActX, uint8_t InActY, uint8_t InActZ);
extern void adxl345_ReadACDC(uint8_t *acdc);
extern void adxl345_ReadThreshFF(uint8_t *threshff);
extern void adxl345_WriteThreshFF(uint8_t threshff);
extern void adxl345_ReadTimeFF(uint8_t *timeff);
extern void adxl345_WriteTimeFF(uint8_t timeff);
extern void adxl345_ReadTapAxes(uint8_t *tap_axes);
extern void adxl345_WriteTapAxes(uint8_t sup, uint8_t tapx, uint8_t tapy, uint8_t tapz);
extern void adxl345_ReadActTapStatus(uint8_t *status);
extern void adxl345_ReadBWRate(uint8_t *bw);

#endif /* QC_ADXL345_H_ */

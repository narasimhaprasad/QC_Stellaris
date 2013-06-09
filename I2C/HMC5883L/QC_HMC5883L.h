/*
 * QC_HMC5883L.h
 *
 *  Created on: Apr 14, 2013
 *      Author: prasad
 */

#ifndef QC_HMC5883L_H_
#define QC_HMC5883L_H_

void hmc5883l_Config(void);

void hmc5883l_ReadXYZ(int16_t *x, int16_t *y, int16_t *z);


#endif /* QC_HMC5883L_H_ */

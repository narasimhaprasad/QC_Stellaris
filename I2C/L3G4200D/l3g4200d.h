#ifndef L3G4200D_H_
#define L3G4200D_H_

#include "I2C/QC_I2C.h"

#define I2C_ID_L3G4200D		0x69

// Register address map
#define WHO_AM_I			0x0F
#define CTRL_REG1			0x20
#define CTRL_REG2			0x21
#define CTRL_REG3			0x22
#define CTRL_REG4			0x23
#define CTRL_REG5			0x24
#define REFERENCE			0x25
#define OUT_TEMP			0x26
#define STATUS_REG			0x27
#define OUT_X_L				0x28
#define OUT_X_H				0x29
#define OUT_Y_L				0x2A
#define OUT_Y_H				0x2B
#define OUT_Z_L				0x2C
#define	OUT_Z_H				0x2D
#define FIFO_CTRL_REG		0x2E
#define FIFO_SRC_REG		0x2F
#define INT1_CFG			0x30
#define INT1_SRC			0x31
#define INT1_TSH_XH			0x32
#define INT1_TSH_XL			0x33
#define INT1_TSH_YH			0x34
#define INT1_TSH_YL			0x35
#define INT1_TSH_ZH			0x36
#define INT1_TSH_ZL			0x37
#define INT1_DURATION		0x38

//Control Register 1
#define ODR100FC12P5		0x00<<4
#define ODR100FC25			0x01<<4
#define ODR200FC12P5		0x04<<4
#define ODR200FC25			0x05<<4
#define ODR200FC50			0x06<<4
#define ODR200FC70			0x07<<4
#define ODR400FC20			0x08<<4
#define ODR400FC25			0x09<<4
#define ODR400FC50			0x10<<4
#define ODR400FC110			0x11<<4
#define ODR800FC30			0x12<<4
#define ODR800FC35			0x13<<4
#define ODR800FC50			0x14<<4
#define ODR800FC110			0x15<<4

#define PD					0x00<<3
#define Sleep				0x08
#define Normal				0x01<<3

#define Zen					0x01<<2

#define Yen					0x01<<1

#define Xen					0x01

//Control Register 2
#define RESET_FILTER		0x00<<4
#define REF_SIG_FILTER		0x01<<4
#define NORMAL_MODE			0x02<<4
#define AUTORESET			0x03<<4

#define ODR100HPFC8			0x00
#define ODR100HPFC4			0x01
#define ODR100HPFC2			0x02
#define ODR100HPFC1			0x03
#define ODR100HPFC0P5		0x04
#define ODR100HPFC0P2		0x05
#define ODR100HPFC0P1		0x06
#define ODR100HPFC0P05		0x07
#define ODR100HPFC0P02		0x08
#define ODR100HPFC0P01		0x09

#define ODR200HPFC15		0x00
#define ODR200HPFC8			0x01
#define ODR200HPFC4			0x02
#define ODR200HPFC2			0x03
#define ODR200HPFC1			0x04
#define ODR200HPFC0P5		0x05
#define ODR200HPFC0P2		0x06
#define ODR200HPFC0P01		0x07
#define ODR200HPFC0P05		0x08
#define ODR200HPFC0P02		0x09

#define ODR400HPFC30		0x00
#define ODR400HPFC15		0x01
#define ODR400HPFC8			0x02
#define ODR400HPFC4			0x03
#define ODR400HPFC2			0x04
#define ODR400HPFC1			0x05
#define ODR400HPFC0P5		0x06
#define ODR400HPFC0P2		0x07
#define ODR400HPFC0P01		0x08
#define ODR400HPFC0P05		0x09

#define ODR800HPFC56		0x00
#define ODR800HPFC30		0x01
#define ODR800HPFC15		0x02
#define ODR800HPFC8			0x03
#define ODR800HPFC4			0x04
#define ODR800HPFC2			0x05
#define ODR800HPFC1			0x06
#define ODR800HPFC0P5		0x07
#define ODR800HPFC0P2		0x08
#define ODR800HPFC0P01		0x09

//Control Register 3
#define I1_Int1				0x01<<7
#define I1_BOOT				0x01<<6
#define H_LACTIVE			0x01<<5
#define PP_OD				0x01<<4
#define I2_DRDY				0x01<<3
#define I2_WTM				0x01<<2
#define I2_ORUN				0x01<<1
#define I2_EMPTY			0x01

//Control Register 4
#define CONTINUOUS_UPDATE	0x00<<7
#define BATCH_UPDATE		0x01<<7
#define BIG_ENDIAN			0x00<<6
#define LITTLE_ENDIAN		0x01<<6
#define DPS250				0x00<<4
#define DPS500				0x01<<4
#define DPS2000				0x02<<4
#define DISABLE_SELF_TEST	0x00<<2
#define POSITIVE_SELF_TEST	0x01<<2
#define NEUTRAL_SELF_TEST	0x02<<2
#define NEGATIVE_SELF_TEST	0x03<<2
#define WIRE_INT_4			0x00
#define WIRE_INT_3			0x01

//Control register 5
#define BOOT_NORMAL			0x00<<7
#define BOOT_MEM			0x01<<7
#define FIFO_DISABLE		0x00<6
#define FIFO_ENABLE			0x01<<6
#define HIGH_PASS_DISABLE	0x00<<5
#define HIGH_PASS_ENABLE	0x01<<5

#define NON_HPF_FILT_INT	0x00<<2
#define HPF_FILT_INT		0x01<<2
#define LPF_FILT_INT		0x02<<2
#define HPF_LPF_INT			0x06<<2

#define DATA_NON_HPF		0x00
#define DATA_HPF			0x01
#define DATA_LPF			0x02
#define DATA_HPF_LPF		0x06

//Status register
#define ZYXOR				0x01<<7
#define ZOR					0x01<<6
#define YOR					0x01<<5
#define XOR					0x01<<4
#define ZYXDA				0x01<<3
#define ZDA					0x01<<2
#define YDA					0x01<<1
#define XDA					0x01

//FIFO control register
#define BYPASS_MODE			0x00<<5
#define FIFO_MODE			0x01<<5
#define STREAM_MODE			0x02<<5
#define STREAM_FIFO_MODE	0x03<<5
#define BYPASS_STREAM_MODE	0x04<<5

//FIFO_SRC_REG
#define WTM_STATUS			0x01<<7
#define OVERRUN_STATUS		0x01<<6
#define FIFO_EMPTY			0x01<<5

int16_t DpsRes;

#endif /* L3G4200D_H_ */

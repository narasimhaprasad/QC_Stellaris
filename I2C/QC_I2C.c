#include "QC_I2C.h"

//*****************************************************************************
//
//! Initializes and enables the specified I2C block.
//!
//! \param I2C_PORT is the I2C peripheral to be used.
//! \param ulI2CSpeed defines the normal (100kbps) or fast (400kbps) I2C mode.
//!
//! This function enables the specified I2C block and sets it up to run at
//! the either 100kbps or 400kbps.  If the \e ulI2CSpeed is false, the I2C will
//! run at 100kbps and if true, then the I2C will run at 400kbps.  The
//! \e I2C_PORT parameter can be one of the following values:
//!
//! \return None.
//
//*****************************************************************************
void i2c_Config(void)
{

                    // I2C1 is used with PortA[7:6].
                    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

                    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
                    ROM_GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);

                    ROM_GPIOPinConfigure(GPIO_PA6_I2C1SCL);
                    ROM_GPIOPinConfigure(GPIO_PA7_I2C1SDA);

                        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);

                        ROM_I2CMasterInitExpClk(I2C_PORT, SysCtlClockGet(), 1); // 1 : 400Khz, 0 : 100Khz
}

//*****************************************************************************
//
//! Reads the I2C slave register.
//!
//! \param I2C_PORT is the base for the I2C module.
//! \param SlaveID is the 7-bit address of the slave to be addressed.
//! \param addr is the register to read from.
//!
//! This function initiates a read from the slave device.
//! The I2C_PORT parameter is the I2C modules master base address.
//! \e I2C_PORT parameter can be one of the following values:
//!
//! \return Register value in an unsigned long format.  Note that 0 will be
//! returned if there is ever an error, 1 if there was not.
//
//*****************************************************************************
uint8_t i2c_ReadByte( uint8_t SlaveID, uint8_t addr)
{
unsigned long ulRegValue = 0;

//      LED_TOGGLE(BLUE);

        // Wait until master module is done transferring.
        //
        while(ROM_I2CMasterBusy(I2C_PORT))
        {
        };

    //
    // Tell the master module what address it will place on the bus when
    // writing to the slave.
    //
    ROM_I2CMasterSlaveAddrSet(I2C_PORT, SlaveID, 0);

    //
    // Place the command to be sent in the data register.
    //
    ROM_I2CMasterDataPut(I2C_PORT, addr);

    //
    // Initiate send of data from the master.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_SINGLE_SEND);

    //
    // Wait until master module is done transferring.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }

    //
    // Tell the master module what address it will place on the bus when
    // reading from the slave.
    //
    ROM_I2CMasterSlaveAddrSet(I2C_PORT, SlaveID, 1);

    //
    // Tell the master to read data.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_SINGLE_RECEIVE);

    //
    // Wait until master module is done receiving.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }

    //
    // Read the data from the master.
    //
    ulRegValue = ROM_I2CMasterDataGet(I2C_PORT);

    //
    // Return the register value.
    //
    return ulRegValue;
}

//*****************************************************************************
//
//! Writes to the specified I2C slave register.
//!
//! \param I2C_PORT is the base for the I2C module.
//! \param SlaveID is the 7-bit address of the slave to be addressed.
//! \param addr is the register to write data to.
//! \param data is the 8-bit data to be written.
//!
//! This function initiates a read from the I2C slave device.
//! The I2C_PORT parameter is the I2C modules master base address.
//! \e I2C_PORT parameter can be one of the following values:
//!
//! \return Register value in an unsigned long format.  Note that 0 will be
//! returned if there is ever an error, 1 if there was not.
//
//int32_t  i2c_XmtByte(uint8_t SlaveID, uint8_t addr, uint8_t data);
//*****************************************************************************
int32_t i2c_WriteByte( uint8_t SlaveID, uint8_t addr, uint8_t data)
{

//      LED_TOGGLE(GREEN);

        //
        // Wait until master module is done transferring.
        //
        while(ROM_I2CMasterBusy(I2C_PORT))
        {
        };

    //
    // Tell the master module what address it will place on the bus when
    // writing to the slave.
    //
    ROM_I2CMasterSlaveAddrSet(I2C_PORT, SlaveID, 0);

    //
    // Place the command to be sent in the data register.
    //
    ROM_I2CMasterDataPut(I2C_PORT, addr);

    //
    // Initiate send of data from the master.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_BURST_SEND_START);

    //
    // Wait until master module is done transferring.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }

    //
    // Place the value to be sent in the data register.
    //
    ROM_I2CMasterDataPut(I2C_PORT, data);

    //
    // Initiate send of data from the master.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_BURST_SEND_CONT);

    //
    // Wait until master module is done transferring.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }

    //
    // Initiate send of data from the master.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_BURST_SEND_FINISH);

    //
    // Wait until master module is done transferring.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }

    //
    // Return 1 if there is no error.
    //
    return 1;
}


//*****************************************************************************
//
//! Reads one/multiple bytes of data from an I2C slave device.
//!
//! \param I2C_PORT is the base for the I2C module.
//! \param SlaveID is the 7-bit address of the slave to be addressed.
//! \param addr is the register to start reading from.
//! \param pBuf is a pointer to the array to store the data.
//! \param nBytes is the number of bytes to read from the slave.
//!
//! This function reads one/multiple bytes of data from an I2C slave device.
//! The I2C_PORT parameter is the I2C modules master base address.
//! \e I2C_PORT parameter can be one of the following values:
//!
//!
//! \return 0 if there was an error or 1 if there was not.
//
//int32_t  i2c_RcvBuf(uint8_t SlaveID, uint8_t addr, int32_t nBytes, uint8_t* pBuf);
//*****************************************************************************
int32_t i2c_ReadBuf(uint8_t SlaveID, uint8_t addr, int32_t nBytes , uint8_t* pBuf )
{
        uint8_t nBytesCount;            // local variable used for byte counting/state determination
        uint16_t MasterOptionCommand;           // used to assign the commands for ROM_I2CMasterControl() function

        //
        // Wait until master module is done transferring.
        //
        while(ROM_I2CMasterBusy(I2C_PORT))
        {
        };

    //
    // Tell the master module what address it will place on the bus when
    // writing to the slave.
    //
    ROM_I2CMasterSlaveAddrSet(I2C_PORT, SlaveID, 0);

    //
    // Place the command to be sent in the data register.
    //
    ROM_I2CMasterDataPut(I2C_PORT, addr);

    //
    // Initiate send of data from the master.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_SINGLE_SEND);

    //
    // Wait until master module is done transferring.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }


        //
        // Tell the master module what address it will place on the bus when
        // reading from the slave.
        //
        ROM_I2CMasterSlaveAddrSet(I2C_PORT, SlaveID, true);

        //
        // Start with BURST with more than one byte to write
        //
        MasterOptionCommand = I2C_MASTER_CMD_BURST_RECEIVE_START;


        for(nBytesCount = 0; nBytesCount < nBytes; nBytesCount++)
        {
                //
                // The second and intermittent byte has to be read with CONTINUE control word
                //
                if(nBytesCount == 1)
                        MasterOptionCommand = I2C_MASTER_CMD_BURST_RECEIVE_CONT;

                //
                // The last byte has to be send with FINISH control word
                //
                if(nBytesCount == nBytes - 1)
                        MasterOptionCommand = I2C_MASTER_CMD_BURST_RECEIVE_FINISH;

                //
                // Re-configure to SINGLE if there is only one byte to read
                //
                if(nBytes == 1)
                        MasterOptionCommand = I2C_MASTER_CMD_SINGLE_RECEIVE;

                //
                // Initiate read of data from the slave.
                //
                ROM_I2CMasterControl(I2C_PORT, MasterOptionCommand);

                //
                // Wait until master module is done reading.
                //
                while(ROM_I2CMasterBusy(I2C_PORT))
                {
                };

                //
        // Check for errors.
        //
        if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
        {
            return 0;
        }

        //
        // Move byte from register
        //
                pBuf[nBytesCount] = I2CMasterDataGet(I2C_PORT);
        }

        // send number of received bytes
        return nBytesCount;
}




//*****************************************************************************
//
//! Writes one/multiple bytes of data to an I2C slave device.
//! Ensure to use auto-increment options on some devices
//! (Control Registers, refer to data sheet).
//! I.e. store related command in the first position of your data array.
//!
//! \param I2C_PORT is the base for the I2C module.
//! \param SlaveID is the 7-bit address of the slave to be addressed.
//! \param addr is the register to start writing to.
//! \param pBuf is a pointer to the array to be send.
//! \param nBytes is the number of bytes to send from array pBuf[].
//!
//! This function writes multiple bytes of data an I2C slave device.
//! The I2C_PORT parameter is the I2C modules master base address.
//! \e I2C_PORT parameter can be one of the following values:
//!
//!
//! \return 0 if there was an error or 1 if there was not.

//int32_t  i2c_XmtBuf(uint8_t SlaveID, uint8_t addr, int32_t nBytes, uint8_t* pBuf );
//
//*****************************************************************************

int32_t i2c_WriteBuf( uint8_t SlaveID, uint8_t addr, int32_t nBytes , uint8_t* pBuf)
{
        uint8_t nBytesCount;            // local variable used for byte counting/state determination
        uint16_t MasterOptionCommand;           // used to assign the commands for ROM_I2CMasterControl() function

        //
        // Wait until master module is done transferring.
        //
        while(ROM_I2CMasterBusy(I2C_PORT))
        {
        };

    //
    // Tell the master module what address it will place on the bus when
    // writing to the slave.
    //
    ROM_I2CMasterSlaveAddrSet(I2C_PORT, SlaveID, false);

    //
    // Place the value to be sent in the data register.
    //
    ROM_I2CMasterDataPut(I2C_PORT, addr);

    //
    // Initiate send of data from the master.
    //
    ROM_I2CMasterControl(I2C_PORT, I2C_MASTER_CMD_BURST_SEND_START);

    //
    // Wait until master module is done transferring.
    //
    while(ROM_I2CMasterBusy(I2C_PORT))
    {
    };

    //
    // Check for errors.
    //
    if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
    {
        return 0;
    }

        //
        // Start with CONT for more than one byte to write
        //
        MasterOptionCommand = I2C_MASTER_CMD_BURST_SEND_CONT;


        for(nBytesCount = 0; nBytesCount < nBytes; nBytesCount++)
        {
                //
                // The second and intermittent byte has to be send with CONTINUE control word
                //
                if(nBytesCount == 1)
                        MasterOptionCommand = I2C_MASTER_CMD_BURST_SEND_CONT;

                //
                // The last byte has to be send with FINISH control word
                //
                if(nBytesCount == nBytes - 1)
                        MasterOptionCommand = I2C_MASTER_CMD_BURST_SEND_FINISH;

                //
                // Re-configure to SINGLE if there is only one byte to write
                //
                if(nBytes == 1)
                        MasterOptionCommand = I2C_MASTER_CMD_SINGLE_SEND;

                //
                // Send data byte
                //
                ROM_I2CMasterDataPut(I2C_PORT, pBuf[nBytesCount]);

                //
                // Initiate send of data from the master.
                //
                ROM_I2CMasterControl(I2C_PORT, MasterOptionCommand);

                //
                // Wait until master module is done transferring.
                //
                while(ROM_I2CMasterBusy(I2C_PORT))
                {
                };

                //
        // Check for errors.
        //
        if(ROM_I2CMasterErr(I2C_PORT) != I2C_MASTER_ERR_NONE)
        {
            return 0;
        }
        }

    //
    // Return 1 if there is no error.
    //
    return 1;
}

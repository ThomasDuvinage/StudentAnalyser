#include "scannerThread.h"

ScannerThread::ScannerThread(const char *port)
{
    // Connection to serial port
    char errorOpening = serial.openDevice(port, 115200);

    this->port = (char *)malloc(strlen(port) + 1);

    strcpy(this->port, port);

    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening != 1)
    {
        emit error();
        isConnected = false;
    }
    else
    {
        emit log("Successful connection to scanner");
        isConnected = true;
    }
}

ScannerThread::~ScannerThread()
{
}

void ScannerThread::run()
{
    // Set DTR
    serial.DTR(true);
    // Clear RTS
    serial.RTS(false);

    exec();

    // Close the serial device
    serial.closeDevice();
}

int ScannerThread::exec()
{
    while (1)
    {
        if (serial.available() && serial.readString(reading_string, FINAL_CHAR, 100, 100) != 0)
        {
            printf("message : %s\n", reading_string);
            emit getUID(reading_string);
        }

        sleep(1);
    }
}
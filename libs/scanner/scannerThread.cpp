#include "scannerThread.h"

ScannerThread::ScannerThread(const char *port)
{
    std::cout << port << std::endl;
    // Connection to serial port
    char errorOpening = serial.openDevice(port, 115200);

    reading_string = (char *)malloc(12 * sizeof(char));
    final_uid = (char *)malloc(15 * sizeof(char));

    // this->port = (char *)malloc(strlen(port) + 1);

    // strcpy(this->port, port);

    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening != 1)
    {
        emit log("Error while connecting to scanner");
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
    free(reading_string);
    free(final_uid);
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
        if (serial.available() && serial.readString(reading_string, FINAL_CHAR, 15, 100) != 0)
        {
            strncpy(final_uid, reading_string, strlen(reading_string) - 1);
            final_uid[strlen(reading_string) - 1] = '\0';
            final_uid = strcat(final_uid, "04");

            emit getUID(final_uid);
            serial.flushReceiver();
        }

        sleep(1);
    }
}
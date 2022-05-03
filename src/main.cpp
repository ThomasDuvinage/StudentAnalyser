#include "mainwindow.h"

#include <QApplication>

#if defined(__linux__) || defined(__APPLE__)
//#define SERIAL_PORT "/dev/ttyS0"
#define SERIAL_PORT "/dev/cu.usbmodem143101"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentAnalyzer w;
    w.show();
    return a.exec();

    // // Serial object
    // serialib serial;

    // // Connection to serial port
    // char errorOpening = serial.openDevice(SERIAL_PORT, 9600);

    // // If connection fails, return the error code otherwise, display a success message
    // if (errorOpening != 1)
    //     return errorOpening;

    // printf("Successful connection to %s\n", SERIAL_PORT);

    // // Set DTR
    // serial.DTR(true);
    // // Clear RTS
    // serial.RTS(false);

    // char *reading_string = (char *)malloc(100 * sizeof(char));
    // char finalchar = '\n';

    // // Loop forever
    // while (1)
    // {
    //     // Read and display the status of each pin
    //     // DTR should be 1
    //     // RTS should be 0
    //     printf("4-DTR=%d\t", serial.isDTR());
    //     printf("7-RTS=%d\t", serial.isRTS());

    //     printf("1-DCD=%d\t", serial.isDCD());
    //     printf("8-CTS=%d\t", serial.isCTS());
    //     printf("6-DSR=%d\t", serial.isDSR());
    //     printf("9-RING=%d\n", serial.isRI());

    //     serial.readString(reading_string, finalchar, 100, 100);

    //     printf("message : %s\n", reading_string);
    // }

    // // Close the serial device
    // serial.closeDevice();
}

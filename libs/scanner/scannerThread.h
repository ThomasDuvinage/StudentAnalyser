#ifndef SCANNER_THREAD_H
#define SCANNER_THREAD_H

#include <QtCore/QThread>
#include <serialib.h>

#if defined(_WIN32) || defined(_WIN64)
#define SERIAL_PORT "\\\\.\\COM1"
#endif
#if defined(__linux__) || defined(__APPLE__)
//#define SERIAL_PORT "/dev/ttyS0" "/dev/cu.usbmodem143101"
#define SERIAL_PORT "/dev/tty"
#endif

#define FINAL_CHAR '\n'

class ScannerThread : public QThread
{
    Q_OBJECT
private:
    serialib serial;
    char *reading_string;
    char *port;

public:
    ScannerThread(){};
    ScannerThread(const char *);
    ~ScannerThread();

    // bool isPortSet() { port ? return true : return false; }
    void setPort(const char *);

    bool isConnected;

protected:
    int exec();
    void run();

signals:
    void log(char *event);
    void error();
    void getUID(char *uid);
};

#endif
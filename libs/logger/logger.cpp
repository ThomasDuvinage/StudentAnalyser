#include "logger.h"
#include <time.h>

Logger::Logger(QTextEdit *log, QObject *parent) : QObject(parent)
{
    this->log_windows = log;
}

void Logger::logEvent(char *event){
    char buffer[30];

    time_t strDate;
    struct tm *timeinfo;

    time(&strDate);
    timeinfo = localtime(&strDate);

    strftime(buffer, 30, "%c", timeinfo);

    QString message = event;
    QString date = buffer;

    log_windows->append(buffer + spacer + event);

}

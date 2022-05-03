#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QTextEdit>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QTextEdit *log, QObject *parent = nullptr);

    QTextEdit *log_windows;

private:
    QString spacer = " ; ";

public slots:
    void logEvent(char *event);

};

#endif // LOGGER_H

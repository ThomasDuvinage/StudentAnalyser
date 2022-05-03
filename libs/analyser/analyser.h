#ifndef ANALYSER_H
#define ANALYSER_H

#include <QtCore/QObject>
#include <QtCore/QDebug>

#include "scanner.h"

class Analyser : public QObject
{
    Q_OBJECT
public:
    explicit Analyser(QObject *parent = nullptr);
    ~Analyser();

private:
signals:
    void saveReady();
    void log(char *log);

public slots:
    void stopScan();
    void scan();
};

#endif // ANALYSER_H

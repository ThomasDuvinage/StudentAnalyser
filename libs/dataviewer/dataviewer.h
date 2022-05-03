#ifndef DATAVIEWER_H
#define DATAVIEWER_H

#include <QObject>

class DataViewer : public QObject
{
    Q_OBJECT
public:
    explicit DataViewer(QObject *parent = nullptr);

signals:

};

#endif // DATAVIEWER_H

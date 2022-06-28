#ifndef DATAVIEWER_H
#define DATAVIEWER_H

#include <QObject>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QList>

class DataViewer : public QObject
{
    Q_OBJECT
private:
    QStandardItemModel *model;
    QTableView *table;

public:
    explicit DataViewer(QTableView *table, QObject *parent = nullptr);
    ~DataViewer();

public slots:
    void addRow(const QStringList &content);
    void clearRows();

signals:
};

#endif // DATAVIEWER_H

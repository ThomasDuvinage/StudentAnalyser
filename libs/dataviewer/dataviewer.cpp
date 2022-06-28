#include "dataviewer.h"

DataViewer::DataViewer(QTableView *table, QObject *parent) : QObject(parent)
{
    model = new QStandardItemModel(0, 5, parent);

    this->table = table;
    this->table->setModel(model);

    QStringList col_labels;
    col_labels << "First Name"
               << "Name"
               << "Login"
               << "Formation"
               << "Level";

    this->model->setHorizontalHeaderLabels(col_labels);
}

DataViewer::~DataViewer()
{
    delete model;
}

void DataViewer::addRow(const QStringList &content)
{
    QList<QStandardItem *> rowData;

    for (int i = 0; i < content.length(); i++)
    {
        rowData.append(new QStandardItem(content.at(i)));
    }

    model->appendRow(rowData);
}

void DataViewer::clearRows()
{
    model->removeRows(0, model->rowCount());
}
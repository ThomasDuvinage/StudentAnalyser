#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <analyser.h>
#include <filemanager.h>
#include <logger.h>
#include <scanner.h>
#include <serialib.h>
#include <dataviewer.h>

#include <unistd.h>
#include <stdio.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class StudentAnalyzer;
}
QT_END_NAMESPACE

class StudentAnalyzer : public QMainWindow
{
    Q_OBJECT

public:
    StudentAnalyzer(QWidget *parent = nullptr);
    ~StudentAnalyzer();

    Analyser *analyse;
    FileManager *fileManager;
    Logger *logger;
    Scanner *scanner;
    DataViewer *dataviewer;

private:
    Ui::StudentAnalyzer *ui;
};
#endif // MAINWINDOW_H

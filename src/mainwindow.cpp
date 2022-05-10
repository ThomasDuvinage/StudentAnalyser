#include "mainwindow.h"
#include "ui_mainwindow.h"

StudentAnalyzer::StudentAnalyzer(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::StudentAnalyzer)
{
    ui->setupUi(this);

    analyse = new Analyser();
    fileManager = new FileManager();
    logger = new Logger(ui->log_text);
    scanner = new Scanner();
    dataviewer = new DataViewer(ui->tableView, this);

    connect(ui->importButton, SIGNAL(clicked()), fileManager, SLOT(importFiles()));
    connect(ui->exportButton, SIGNAL(clicked()), fileManager, SLOT(exportFiles()));
    connect(ui->startButton, SIGNAL(clicked()), scanner, SLOT(scanning()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionImport_students_list, SIGNAL(triggered()), fileManager, SLOT(importFiles()));
    connect(ui->actionExport_results, SIGNAL(triggered()), fileManager, SLOT(exportFiles()));

    connect(fileManager, SIGNAL(log(char *)), logger, SLOT(logEvent(char *)));
    connect(analyse, SIGNAL(log(char *)), logger, SLOT(logEvent(char *)));
    connect(scanner, SIGNAL(log(char *)), logger, SLOT(logEvent(char *)));

    connect(scanner, SIGNAL(scan(char *, QString, QString)), fileManager, SLOT(updateStudentStatus(char *, QString, QString)));

    connect(fileManager, SIGNAL(addRow(const QStringList &)), dataviewer, SLOT(addRow(const QStringList &)));
}

StudentAnalyzer::~StudentAnalyzer()
{
    delete ui;
    delete analyse;
    delete fileManager;
    delete logger;
    delete scanner;
    delete dataviewer;
}

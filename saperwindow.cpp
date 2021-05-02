#include "saperwindow.h"
#include "ui_saperwindow.h"

SaperWindow::SaperWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SaperWindow)
{
    ui->setupUi(this);
    model = new gameBoardModel(this);
    ui->GameView->horizontalHeader()->hide();
    ui->GameView->verticalHeader()->hide();
    ui->GameView->setModel(model);
    ui->GameView->setItemDelegate(new FieldDelegate);
    ui->GameView->resizeColumnsToContents();
    ui->GameView->resizeRowsToContents();
    connect(ui->actionBest_Results,&QAction::triggered,this, &SaperWindow::showBestResults);
}

SaperWindow::~SaperWindow()
{
    delete ui;
}

void SaperWindow::setEasy()
{
    ui->actionEasy->setChecked(true);
    ui->actionMedium->setChecked(false);
    ui->actionHard->setChecked(false);
}

void SaperWindow::setMedium()
{
    ui->actionEasy->setChecked(false);
    ui->actionMedium->setChecked(true);
    ui->actionHard->setChecked(false);
}

void SaperWindow::setHard()
{
    ui->actionEasy->setChecked(false);
    ui->actionMedium->setChecked(false);
    ui->actionHard->setChecked(true);
}

void SaperWindow::showBestResults()
{
    BestResultsDialog* results = new BestResultsDialog(this);
    results->setModal(true);
    results->exec();
}

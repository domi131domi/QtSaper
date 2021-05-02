#include "saperwindow.h"
#include "ui_saperwindow.h"

SaperWindow::SaperWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SaperWindow)
{
    ui->setupUi(this);
}

SaperWindow::~SaperWindow()
{
    delete ui;
}


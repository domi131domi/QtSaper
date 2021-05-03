#include "savedialog.h"
#include "ui_savedialog.h"

SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    connect(this,&QDialog::accepted, this, &SaveDialog::saveResult);
    ui->setupUi(this);
}

SaveDialog::~SaveDialog()
{
    delete ui;
}

void SaveDialog::setPoints(int points)
{
    this->points = points;
}

void SaveDialog::saveResult()
{
    if(points == 0)
        return;
    if(ui->usernameTb->toPlainText().isEmpty())
        return;
    std::ofstream save(SAVE_PATH, std::ios_base::app);
    std::string name;
    if(save.is_open())
    {
        std::string text = ui->usernameTb->toPlainText().toStdString();
        save << text << " ";
        save << points << std::endl;
        save.close();
    }
}

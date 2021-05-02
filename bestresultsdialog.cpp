#include "bestresultsdialog.h"
#include "ui_bestresultsdialog.h"

bool BestResultsDialog::compare(Result res1, Result res2)
{
    return res1.time < res2.time;
}

BestResultsDialog::BestResultsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BestResultsDialog)
{
    ui->setupUi(this);
    std::vector<Result> vect;
    std::ifstream save(SAVE_PATH);
    Result res;
    std::string name;
    if(save.is_open())
    {
        while(save >> name)
        {
            res.name = QString::fromStdString(name);
            save >> res.time;
            vect.push_back(res);
        }
        save.close();
    }
    std::sort(vect.begin(), vect.end(), BestResultsDialog::compare);
    model = new BestResultModel(vect,this);
    ui->ResultsTableView->setModel(model);
}

BestResultsDialog::~BestResultsDialog()
{
    delete ui;
}

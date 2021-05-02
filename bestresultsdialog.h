#ifndef BESTRESULTSDIALOG_H
#define BESTRESULTSDIALOG_H

#include <QDialog>
#include <bestresultmodel.h>
#include <iostream>
#include <fstream>
#include <algorithm>

namespace Ui {
class BestResultsDialog;
}

class BestResultsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BestResultsDialog(QWidget *parent = nullptr);
    ~BestResultsDialog();

private:
    Ui::BestResultsDialog *ui;
    BestResultModel* model;

    static bool compare(Result res1, Result res2);
};

#endif // BESTRESULTSDIALOG_H

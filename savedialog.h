#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <fstream>
#include <settings.h>
#include <iostream>
#include <string>

namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = nullptr);
    ~SaveDialog();
    void setPoints(int);
public slots:
    void saveResult();
private:
    Ui::SaveDialog *ui;
    int points;
};

#endif // SAVEDIALOG_H

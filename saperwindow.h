#ifndef SAPERWINDOW_H
#define SAPERWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "bestresultsdialog.h"
#include "gameboardmodel.h"
#include "fielddelegate.h"
#include <QHeaderView>

QT_BEGIN_NAMESPACE
namespace Ui { class SaperWindow; }
QT_END_NAMESPACE

class SaperWindow : public QMainWindow
{
    Q_OBJECT

public:
    SaperWindow(QWidget *parent = nullptr);
    ~SaperWindow();

private slots:
    void setEasy();
    void setMedium();
    void setHard();
    void showBestResults();

private:
    Ui::SaperWindow *ui;
    gameBoardModel* model;
};
#endif // SAPERWINDOW_H

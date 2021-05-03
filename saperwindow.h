#ifndef SAPERWINDOW_H
#define SAPERWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "bestresultsdialog.h"
#include "gameboardmodel.h"
#include "fielddelegate.h"
#include <QHeaderView>
#include <QTableView>
#include "savedialog.h"

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
    void gameWon();
    void newGame();
    void gameOver();
    void saveResult();

private:
    Ui::SaperWindow *ui;
    gameBoardModel* model;
    bool canBeSaved;
};
#endif // SAPERWINDOW_H

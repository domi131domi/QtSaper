#ifndef SAPERWINDOW_H
#define SAPERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SaperWindow; }
QT_END_NAMESPACE

class SaperWindow : public QMainWindow
{
    Q_OBJECT

public:
    SaperWindow(QWidget *parent = nullptr);
    ~SaperWindow();

private:
    Ui::SaperWindow *ui;
};
#endif // SAPERWINDOW_H

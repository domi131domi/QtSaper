#include "saperwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SaperWindow w;
    w.show();
    return a.exec();
}

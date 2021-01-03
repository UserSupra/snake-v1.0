#include "testsnake.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testsnake w;
    w.setFocus();
    w.show();
    return a.exec();
}

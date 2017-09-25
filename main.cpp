#include "signature.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signature w;
    w.show();

    return a.exec();
}

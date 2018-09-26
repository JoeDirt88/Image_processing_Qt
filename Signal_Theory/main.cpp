#include "magicwindow.h"
#include <QApplication>
#include <QString>
#include <Qfile>
#include <QIODevice>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QtCore>
#include <QtGui>
#include <QDirModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MagicWindow w;
    w.show();

    return a.exec();
}

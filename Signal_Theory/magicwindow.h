#ifndef MAGICWINDOW_H
#define MAGICWINDOW_H

#include <QMainWindow>
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

namespace Ui {
class MagicWindow;
}

class MagicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MagicWindow(QWidget *parent = 0);
    ~MagicWindow();

private slots:
    void on_LoadButton_clicked();

    void on_DTFT_LP_GRAD_sliderReleased();

private:
    Ui::MagicWindow *ui;

    QDirModel *Directory;

};

#endif // MAGICWINDOW_H

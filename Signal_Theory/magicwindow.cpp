//==========================\\
//  ##Johannes de Lange##   \\
//  ##     23689293    ##   \\
//==========================\\


#include "magicwindow.h"
#include "ui_magicwindow.h"
#include <QString>
#include <Qfile>
#include <QIODevice>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QtCore>
#include <QtGui>
#include <QDirModel>
#include <QtMath>
#include <complex>

MagicWindow::MagicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MagicWindow)
{
    ui->setupUi(this);

    // Directory Model Creation
    Directory = new QDirModel(this);
    Directory->setReadOnly(false);

    ui->treeView->setModel(Directory);

}

MagicWindow::~MagicWindow()
{
    delete ui;
}

void MagicWindow::on_LoadButton_clicked()
{
    //Open file for DTFT
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    QString ImageFileName = Directory->fileName(index);
    QString ImageFilePath = Directory->filePath(index);
    QFile ImageFile(ImageFilePath);

    QImage image(ImageFilePath);

    //displays original image
    int Or_V_W = ui->Original_View->width();
    ui->Original_View->setPixmap(QPixmap::fromImage(image).scaledToHeight(Or_V_W));

    //displays grayscale image
    for (int I_W = 0; I_W < image.width(); I_W++)
    {
        for (int I_H = 0; I_H < image.height(); I_H++)
        {
            int gray = qGray(image.pixel(I_W, I_H));
            image.setPixel(I_W, I_H, QColor(gray, gray, gray).rgb());
        }
    }
    int Gs_V_W = ui->Grayscale_View->width();
    ui->Grayscale_View->setPixmap(QPixmap::fromImage(image).scaledToHeight(Gs_V_W));

    //displays the DFT spectrum of the image
    int M = image.width();
    int N = image.height();
    int Ave = 1/(M*N);

    int CColour;
    int SumColour = 0;
    int AveColour = 0;
    double pi = 3.14159265359;

    QImage Fimage = image;


    for (int F_W = 0; F_W < M; F_W++)
    {
        for (int F_H = 0; F_H < N; F_H++)
        {
            //perform iteration
            for (int I_W = 0; I_W < M; I_W++)
            {
                for (int I_H = 0; I_H < N; I_H++)
                {
                    CColour = qGray(image.pixel(I_W, I_H));
                    //SumColour = CColour*qExp((2*pi)(((F_W*I_W)/M)+((F_H*I_H)/N)));// WTF

                    AveColour = AveColour + SumColour;
                }
            }

            int FColour = Ave*AveColour;
            Fimage.setPixel(F_W, F_H, QColor(FColour, FColour, FColour).rgb());
        }
    }
    int Fs_V_W = ui->Spectrum_View->width();
    ui->Spectrum_View->setPixmap(QPixmap::fromImage(Fimage).scaledToHeight(Fs_V_W));

    //displays file and path information
    ui->Output_Window->setText("Full File Path : " + ImageFilePath);
}

void MagicWindow::on_DTFT_LP_GRAD_sliderReleased()
{
    //Open file for DTFT
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    QString ImageFileName = Directory->fileName(index);
    QString ImageFilePath = Directory->filePath(index);
    QFile ImageFile(ImageFilePath);

    QImage image(ImageFilePath);

    for (int F_W = 0; F_W < image.width(); F_W++)
    {
        for (int F_H = 0; F_H < image.height(); F_H++)
        {
            for (int I_W = 0; I_W < image.width(); I_W++)
            {
                for (int I_H = 0; I_H < image.height(); I_H++)
                {

                }
            }
        }
    }

    int LP_V_W = ui->DTFT_LP_View->width();
    ui->DTFT_LP_View->setPixmap(QPixmap::fromImage(image).scaledToHeight(LP_V_W));
}

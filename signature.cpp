#include "signature.h"
#include "ui_signature.h"
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QImage>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTextCodec>
#include <QDesktopWidget>
#include <QRect>
using namespace std;
using namespace cv;

signature::signature(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signature)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
    signature::getScreenInfo();

}

signature::~signature()
{
    delete ui;
}

void signature::on_generate_button_clicked()
{
    if(src_img.data!=NULL)
    {
        Mat src_gray;
        cvtColor(signature::src_img, src_gray, CV_RGB2GRAY);
        threshold(src_gray, signature::bin_img, 50, 255, CV_THRESH_OTSU);
        signature:: show_img(signature::bin_img);
        bin_img.copyTo(save_img);
    }
}

void signature::on_save_button_clicked()
{
     QString dst("C:\\");

    QString fileName = QFileDialog::getSaveFileName(this, tr("保存文件"),
                                                       NULL,
                                                       tr("PictureFile (*.jpg *.png)"));
    if(!fileName.isNull())
    {
        QTextCodec *code = QTextCodec::codecForName("gb2312");
        std::string filepath = code->fromUnicode(fileName).data();

        imwrite(filepath,signature::save_img);
    }
}

void signature::on_open_button_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                      NULL,
                                                       tr("txtFile (*.jpg *.png)"));

    if (!fileName.isNull())
    {
        QTextCodec *code = QTextCodec::codecForName("gb2312");
        std::string filepath = code->fromUnicode(fileName).data();
        signature:: src_img=imread(filepath);
        signature:: show_img(signature::src_img);
    }

}
 void signature:: show_img(const Mat& img)
 {
     Mat show_img_temp;
     QImage QTimg;

     Mat temp_img;
     img.copyTo(temp_img);

     //calculate suitable image size for showing
     if(temp_img.cols>700||temp_img.rows>600)
     {

         float scale_factor_col= 1.5/(g_nActScreenW*1.0/temp_img.cols);
         float scale_factor_row=1.5/(g_nActScreenH*1.0/temp_img.rows);

         float scale_factor= scale_factor_col > scale_factor_row ? scale_factor_col:scale_factor_row;
         scale_factor=  scale_factor==0?1:scale_factor;
         cv::resize(temp_img,temp_img,cv::Size(temp_img.cols/scale_factor,temp_img.rows/scale_factor));
     }
     if(temp_img.channels()==3)
     {
         cv::cvtColor(temp_img,show_img_temp,CV_BGR2RGB);
         QTimg=QImage((const uchar*)show_img_temp.data,show_img_temp.cols,
                show_img_temp.rows,show_img_temp.cols*show_img_temp.channels(),QImage::Format_RGB888);

     }
    else
     {

         QTimg=QImage((const uchar*)temp_img.data,temp_img.cols,
                temp_img.rows,temp_img.cols*temp_img.channels(),QImage::Format_Indexed8);

    }
     ui->label->setPixmap(QPixmap::fromImage(QTimg));
     ui->label->resize(QTimg.width(),QTimg.height());
     ui->label->show();
 }
 /******************************
  *  get the screen resolution
  ******************************/
 void  signature::getScreenInfo()
 {
     QDesktopWidget* desktopWidget = QApplication::desktop();
     QRect screenRect = desktopWidget->screenGeometry();
     g_nActScreenW = screenRect.width();
     g_nActScreenH = screenRect.height();
 }


void signature::on_blur_size_valueChanged(int value)
{
    //use different blur kernel size
    if(bin_img.data!=NULL){
        switch(value)
        {
            case 0 : break;
            case 1 : medianBlur(signature::bin_img, signature::save_img,3);break;
            case 2 : medianBlur(signature::bin_img, signature::save_img,5);break;
            case 3 : medianBlur(signature::bin_img, signature::save_img,7);break;
            case 4 : medianBlur(signature::bin_img, signature::save_img,9);break;
            case 5 : medianBlur(signature::bin_img, signature::save_img,11);break;
            case 6 : medianBlur(signature::bin_img, signature::save_img,13);break;
            case 7 : medianBlur(signature::bin_img, signature::save_img,15);break;
            default: break;
        }

        signature:: show_img(signature::save_img);
    }
}

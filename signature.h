#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class signature;
}

class signature : public QMainWindow
{
    Q_OBJECT

public:
    explicit signature(QWidget *parent = 0);
    ~signature();
    void show_img(const cv::Mat&);

private slots:
    void on_generate_button_clicked();

    void on_save_button_clicked();

    void on_open_button_clicked();

    void getScreenInfo();


    void on_blur_size_valueChanged(int value);

private:
    Ui:: signature *ui;
    cv:: Mat src_img;
    cv:: Mat bin_img;
    cv:: Mat save_img;
    int  g_nActScreenW;
    int  g_nActScreenH;

};

#endif // SIGNATURE_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorDetectController.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()  //open button
{

    QString fileName = QFileDialog::getOpenFileName(this,
     tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));

    cv::Mat image= cv::imread(fileName.toUtf8().data());

    if (image.data) {
        //cv::namedWindow("Original Image");

        //cv::imshow("Original Image", image);
        ui->pushButton_2->setEnabled(true);
    }
    colorDetect.setInputImage(fileName.toUtf8().data());
    cv:: imshow("Input Image", colorDetect.getInputImage());
}

void MainWindow::on_pushButton_2_clicked()  //process button
{
    colorDetect.setTargetColor(130, 190, 230);
    colorDetect.process();
    cv::imshow("Output Result", colorDetect.getLastResult());
}

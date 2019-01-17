/**
  ******************************************************************************
  * @file    MainWindow.cpp
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    17-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "MainWindow.h"
#include "ui_MainWindow.h"

/* Variables -----------------------------------------------------------------*/
/* Function ------------------------------------------------------------------*/
/*******************************************************************************
  * @brief  Construct function.
  * @param  QWidget *parent - Pointer of parent object
  * @retval None.
  *****************************************************************************/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // UI Initialization.
    ui->setupUi(this);

    // Further Initialization.
    FurtherInit();
}


/*******************************************************************************
  * @brief  Further Initialization of this Class.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void MainWindow::FurtherInit()
{
    excelThread = new ExcelOperation(this);

    viewer = new Viewer();
    ui->MainLayout->addWidget(viewer);
    viewer->show();

    // Signal-Slot Connection.
    connect(ui->ButtonOpenFile, &QPushButton::clicked,  this, &MainWindow::ButtonOpenFile_clicked);
    connect(ui->ButtonClear,    &QPushButton::clicked,  this, &MainWindow::ButtonClear_clicked);
    connect(ui->Slider,         &QSlider::valueChanged, this, &MainWindow::Slider_valueChanged);
    connect(excelThread, &ExcelOperation::readFinished, this, &MainWindow::getExcelData);
}


/*******************************************************************************
  * @brief  Destructor function.
  * @param  None.
  * @retval None.
  *****************************************************************************/
MainWindow::~MainWindow()
{
    delete viewer;
    delete ui;
}


/*******************************************************************************
  * @brief  Process when the button for opening a excel file is clicked.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void MainWindow::ButtonOpenFile_clicked()
{
    // Get the Excel file name.
    QString excelFile = QFileDialog::getOpenFileName(this, QStringLiteral("Open File"), "", "Excel file(*.xls *.xlsx)");
    if (excelFile.isEmpty())
    {
        ui->LabelStatus->setText("");
        return;
    }

    // UI Update.
    ui->ButtonOpenFile->setDisabled(true);
    ui->LabelStatus->setText("正在加载...");

    // The Thread of opening  the excel file.
    excelThread->setFileName(excelFile);
    excelThread->start();
}


/*******************************************************************************
  * @brief  Process when the button for clearing the viewer is clicked.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void MainWindow::ButtonClear_clicked()
{
    QList<QList<double>> pointList;
    viewer->setPointList(pointList, 811, ui->Slider->value());
}


/*******************************************************************************
  * @brief  Process when the excel file is ready to read.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void MainWindow::getExcelData(bool status)
{
    // UI Update.
    ui->ButtonOpenFile->setEnabled(true);

    qDebug() << "read file status: " << status;
    if(status == false)
    {
        ui->LabelStatus->setText("加载失败！");
        return;
    }

    ui->LabelStatus->setText("加载成功！");
    QVariantList sheetList = excelThread->getFileVariant()->toList();
    QList<QList<double>> pointList;
    for(int j = 0; ; j++)
    {
        for(int i = 0; i < sheetList.size(); i++)
        {
            if(1 + j*5 > sheetList.at(i).toList().size())
                goto exitAddPoint;

            QList<double> point;
            point << sheetList.at(i).toList().at(1 + j*5).toDouble() << sheetList.at(i).toList().at(2 + j*5).toDouble();
            pointList.append(point);
        }
    }

exitAddPoint:
    viewer->setPointList(pointList, 811, ui->Slider->value());
}


/*******************************************************************************
  * @brief  Process when the value of slider is changed.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void MainWindow::Slider_valueChanged()
{
    viewer->setLayerHeight(ui->Slider->value());
}

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

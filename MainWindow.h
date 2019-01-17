/**
  ******************************************************************************
  * @file    MainWindow.h
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    17-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* Includes ------------------------------------------------------------------*/
#include <QMainWindow>
#include <QFileDialog>
#include <QAxObject>
#include "PointCloudViewer.h"
#include "ExcelOperation.h"

/* Macro Definition ----------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Function Declaration ------------------------------------------------------*/
/* Class Declaration ---------------------------------------------------------*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ButtonOpenFile_clicked();
    void ButtonClear_clicked();
    void Slider_valueChanged();
    void getExcelData(bool status);

private:
    void FurtherInit();
    Ui::MainWindow *ui;
    Viewer *viewer;
    ExcelOperation *excelThread;
};

#endif // MAINWINDOW_H

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

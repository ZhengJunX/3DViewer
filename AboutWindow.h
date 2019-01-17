/**
  ******************************************************************************
  * @file    AboutWindow.h
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    15-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

/* Includes ------------------------------------------------------------------*/
#include <QDialog>

/* Macro Definition ----------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Function Declaration ------------------------------------------------------*/
/* Class Declaration ---------------------------------------------------------*/
namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

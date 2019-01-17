/**
  ******************************************************************************
  * @file    AboutWindow.cpp
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    15-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "AboutWindow.h"
#include "ui_AboutWindow.h"

/* Variables -----------------------------------------------------------------*/
/* Function ------------------------------------------------------------------*/
/*******************************************************************************
  * @brief  Construct function.
  * @param  QDialog *parent - Pointer of parent object
  * @retval None.
  *****************************************************************************/
AboutWindow::AboutWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AboutWindow)
{
    // UI Initialization
    ui->setupUi(this);

    // Remove the help buttons.
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    // Signal-Slot Connection
    connect(ui->ButtonClose, &QPushButton::clicked, this, &AboutWindow::close);
}


/*******************************************************************************
  * @brief  Destructor function.
  * @param  None.
  * @retval None.
  *****************************************************************************/
AboutWindow::~AboutWindow()
{
    delete ui;
}

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

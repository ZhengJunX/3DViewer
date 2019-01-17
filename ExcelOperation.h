/**
  ******************************************************************************
  * @file    ExcelOperation.h
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    17-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef EXCELOPERATION_H
#define EXCELOPERATION_H

/* Includes ------------------------------------------------------------------*/
#include <QObject>
#include <QAxObject>
#include <QThread>

/* Macro Definition ----------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Function Declaration ------------------------------------------------------*/
/* Class Declaration ---------------------------------------------------------*/
class ExcelOperation : public QThread
{
    Q_OBJECT

public:
    ExcelOperation(QObject *parent = nullptr);
    void run();

    void setFileName(const QString& name);
    QVariant *getFileVariant();

private:
    void openExcel();
    void readAll(QAxObject *sheet);

    QString  fileName;
    QVariant fileVar;

signals:
    void readFinished(bool status);
};

#endif // EXCELOPERATION_H

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

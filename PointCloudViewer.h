/**
  ******************************************************************************
  * @file    PointCloudViewer.h
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    17-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef POINTCLOUDVIEWER_H
#define POINTCLOUDVIEWER_H

/* Includes ------------------------------------------------------------------*/
#include <QDebug>
#include <QGLViewer/qglviewer.h>
#include "ExcelOperation.h"

/* Macro Definition ----------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Function Declaration ------------------------------------------------------*/
/* Class Declaration ---------------------------------------------------------*/
class Viewer : public QGLViewer
{
public:
    void setPointList(const QList<QList<double>> &list, qint32 cnt, double height);
    void setLayerPointCount(qint32 Cnt);
    void setLayerHeight(double height);

protected:
    virtual void init();
    virtual void draw();

private:
    QList<QList<double>> pointList;
    qint32 layerPointCount = 0;
    double layerHeight = 0;
};

#endif // POINTCLOUDVIEWER_H

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

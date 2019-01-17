/**
  ******************************************************************************
  * @file    PointCloudViewer.cpp
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    17-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "PointCloudViewer.h"
#include <math.h>
#include <stdlib.h>

/* Macro Definition ----------------------------------------------------------*/
#define PI 3.1415927

using namespace qglviewer;
using namespace std;

/* Variables -----------------------------------------------------------------*/
/* Function ------------------------------------------------------------------*/
/*******************************************************************************
  * @brief  Viewer initialization.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void Viewer::init() {
    glDisable(GL_LIGHTING);
    glPointSize(1.0);
    setGridIsDrawn();
    setAxisIsDrawn();
    setSceneRadius(5000);
    setFPSIsDisplayed(true);
    camera()->setUpVector(Vec(0.0, 0.0, 1.0));
    camera()->setViewDirection(Vec(-1.0, -1.0, -0.5));
    showEntireScene();
    startAnimation();
}


/*******************************************************************************
  * @brief  Function of viewer drawing.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void Viewer::draw()
{
    glBegin(GL_POINTS);
    int i = 0, j = 0; double z = 0;
    for(i = 0; i < pointList.count(); i++)
    {
        if(j < layerPointCount) {j++;}
        else {j = 0; z += layerHeight;}
        glVertex3d(z, pointList.at(i).at(1), pointList.at(i).at(0));
    }
    glEnd();
}


/*******************************************************************************
  * @brief  Setting the series of points.
  * @param  const QList<QList<double>> &list
  *         qint32 cnt
  *         double height
  * @retval None.
  *****************************************************************************/
void Viewer::setPointList(const QList<QList<double>> &list, qint32 cnt, double height)
{
    pointList.clear();

    for(int i = 0; i < list.count(); i++)
    {
        // Calculate the radian and distance.
        double rad = ((list.at(i).at(0) - 45.0)/180.0) * PI;
        double distance = list.at(i).at(1);

        // And Single Point.
        QList<double> point;
        point << distance*sin(rad) + 1500 << distance*cos(rad);
        pointList.append(point);
    }
    layerPointCount = cnt;
    layerHeight = height;
}


/*******************************************************************************
  * @brief  Setting the height of layer.
  * @param  double height.
  * @retval None.
  *****************************************************************************/
void Viewer::setLayerHeight(double height)
{
    layerHeight = height;
}

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

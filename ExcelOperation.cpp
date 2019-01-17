/**
  ******************************************************************************
  * @file    ExcelOperation.cpp
  * @author  Junxin Zheng
  * @version V1.0.0
  * @date    17-January-2019
  * @brief   ...
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ExcelOperation.h"

/* Variables -----------------------------------------------------------------*/
/* Function ------------------------------------------------------------------*/
/*******************************************************************************
  * @brief  Construct function.
  * @param  QWidget *parent - Pointer of parent object
  * @retval None.
  *****************************************************************************/
ExcelOperation::ExcelOperation(QObject *parent) : QThread(parent)
{

}


/*******************************************************************************
  * @brief  The starting point for the thread.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void ExcelOperation::run()
{
    fileVar.clear();

    if(fileName.isEmpty())
    {
        emit readFinished(false);
        return;
    }

    // Open and read excel file.
    openExcel();

    if(!fileVar.isNull())
    {
        emit readFinished(true);
    }
    else
    {
        emit readFinished(false);
    }
}


/*******************************************************************************
  * @brief  Setting the name of excel file which is waiting to open.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void ExcelOperation::setFileName(const QString& name)
{
    fileName = name;
}


/*******************************************************************************
  * @brief  Return the pointer of excel file data.
  * @param  None.
  * @retval None.
  *****************************************************************************/
QVariant *ExcelOperation::getFileVariant()
{
    return &fileVar;
}


/*******************************************************************************
  * @brief  Process to open a excel file.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void ExcelOperation::openExcel()
{
    // Initialing the Excel Engine.
    QAxObject excel("Excel.Application");

    // Hide the Window of Excel.
    excel.setProperty("Visible", false);

    // Get the collection of Excel Workbooks.
    QAxObject *workBooks = excel.querySubObject("WorkBooks");

    // Open Excel File.
    workBooks->dynamicCall("Open(const QString&)", fileName);

    // Get the current Excel Workbook.
    QAxObject *workBook = excel.querySubObject("ActiveWorkBook");

    if (workBook->querySubObject("Sheets")->property("Count").toInt() > 0)
    {
        QAxObject *sheet = workBook->querySubObject("Sheets(int)", 1);
        readAll(sheet);
    }

    // Close the Workbook.
    workBook->dynamicCall("Close(Boolean)", false);

    // Close the Excel Engine.
    excel.dynamicCall("Quit(void)");
}


/*******************************************************************************
  * @brief  Process to read the data from a sheet of the excel file.
  * @param  None.
  * @retval None.
  *****************************************************************************/
void ExcelOperation::readAll(QAxObject *sheet)
{
    if (sheet != nullptr && !sheet->isNull())
    {
        QAxObject *usedRange = sheet->querySubObject("UsedRange");
        if (nullptr == usedRange || usedRange->isNull())
        {
            return;
        }
        fileVar = usedRange->dynamicCall("Value");
    }
}

/**************** (C) COPYRIGHT 2019 Junxin Zheng ******** END OF FILE ********/

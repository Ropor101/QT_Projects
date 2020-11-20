#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CountButton_clicked()
{
    QString strLeft = ui->FirstNum->text();                         //преобразование текста в число
    QString strRight = ui->SecondNum->text();

    bool ok1, ok2;
                                                                    //операции
    double first = strLeft.toDouble(&ok1);
    double second = strRight.toDouble(&ok2);
    double result = 0;

    ui->Del0->setText(" ");

    if(ui->Plus->isChecked())                                         // "+"
    {
        ui->LeftText->setText("Первое слагаемое");
        ui->RightText->setText("Второе слагаемое");
        result=first+second;
    }


    else if (ui->Minus->isChecked())                                  // "-"
    {
        ui->LeftText->setText("Уменьшаемое");
        ui->RightText->setText("Вычитаемое");
        result=first-second;
    }


    else if (ui->Ymnojit->isChecked())                                // "*"
    {
        ui->LeftText->setText("Первый множитель");
        ui->RightText->setText("Второй множитель");
        result=first*second;
    }


    else if (ui->Delenie->isChecked())                                // "/"
    {
        if (strRight!="0")
        {
            ui->LeftText->setText("Делимое");
            ui->RightText->setText("Делитель");
            result=first/second;
        }
        else
        {
            ui->Del0->setText("ДЕЛИТЬ НА 0 НЕЛЬЗЯ!");
        }
    }


    else if(ui->Koren->isChecked())                                   // корень числа
    {
        ui->LeftText->setText("Извлекаемое число");
        result=sqrt(first);
    }


    QString strResult;                                          //преобразование числа в текст
    strResult.setNum(result);

    ui->Result2->setText(strResult);


    if(ui->Koren->isChecked())                                      //условия вывода текста
    {
        ok2=1;
        ui->SecondNum->hide();
        ui->RightText->hide();
    }
    else
    {
        ui->SecondNum->show();
        ui->RightText->show();
    }


    if (!ok2)
    {
        ui->Result2->setText("В поле 2 введено не число!");
        ui->SecondNum->setStyleSheet("background-color: red");
    }
    else
        ui->SecondNum->setStyleSheet("background-color: white");

    if (!ok1)
    {
        ui->Result2->setText("В поле 1 введено не число!");
        ui->FirstNum->setStyleSheet("background-color: red");
    }
    else
        ui->FirstNum->setStyleSheet("background-color: white");


}

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


void MainWindow::on_pushButton_clicked()
{
    //преобразование текста в число
    QString X_1 = ui->CoordX1->text();
    QString X_2 = ui->CoordX2->text();
    QString X_3 = ui->CoordX3->text();
    QString Y_1 = ui->CoordY1->text();
    QString Y_2 = ui->CoordY2->text();
    QString Y_3 = ui->CoordY3->text();

    bool ok1, ok2, ok3, ok4, ok5, ok6;

    double X1 = X_1.toDouble(&ok1);
    double X2 = X_2.toDouble(&ok2);
    double X3 = X_3.toDouble(&ok3);
    double Y1 = Y_1.toDouble(&ok4);
    double Y2 = Y_2.toDouble(&ok5);
    double Y3 = Y_3.toDouble(&ok6);

    //математика
    double side1= sqrt((X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1));
    double side2=sqrt((X3-X2)*(X3-X2)+(Y3-Y2)*(Y3-Y2));
    double side3=sqrt((X1-X3)*(X1-X3)+(Y1-Y3)*(Y1-Y3));

    double perim =side1+side2+side3 ;

    double plosh = sqrt((perim/2) * ((perim/2)-side1) * ((perim/2)-side2) * ((perim/2)-side3));

    //магия с преобразованием и выводом ответа
    QString strPerimetr;
    QString strPloshad;

    ui->Warn->setText("Координата отсутствует или введено не число!");
    ui->Warn->hide();

    if (!ok1)
        {
            ui->Warn->show();
            ui->CoordX1->setStyleSheet("background-color: red");
        }
    else if(!ok4)
        {   ui->CoordX1->setStyleSheet("background-color: white");
            ui->Warn->show();
            ui->CoordY1->setStyleSheet("background-color: red");
        }
    else if(!ok2)
        {
            ui->CoordY1->setStyleSheet("background-color: white");
            ui->Warn->show();
            ui->CoordX2->setStyleSheet("background-color: red");
        }
    else if(!ok5)
        {
            ui->CoordX2->setStyleSheet("background-color: white");
            ui->Warn->show();
            ui->CoordY2->setStyleSheet("background-color: red");
        }
    else if(!ok3)
        {
            ui->CoordY2->setStyleSheet("background-color: white");
            ui->Warn->show();
            ui->CoordX3->setStyleSheet("background-color: red");
        }
    else if(!ok6)
        {
            ui->CoordX3->setStyleSheet("background-color: white");
            ui->Warn->show();
            ui->CoordY3->setStyleSheet("background-color: red");
        }

    else
        {
            ui->CoordY3->setStyleSheet("background-color: white");
            ui->Warn->hide();
            strPerimetr.setNum(perim);
            ui->PERIMETR->setText(strPerimetr);
            strPloshad.setNum(plosh);
            ui->PLOSHAD->setText(strPloshad);
        }

}

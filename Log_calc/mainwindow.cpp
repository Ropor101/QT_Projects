#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette p = this->palette();
    QColor color;

    p.setColor(QPalette::Window, (parent ? Qt::green : Qt::red));
    this->setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TFLeft_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    calculate();
}

void MainWindow::on_CMBMid_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    calculate();
}

void MainWindow::on_TFRight_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    calculate();
}

void MainWindow::calculate()
{
    //возвращение индекса на текущий момент компонента в выпадающем списке
    bool left = ui->TFLeft->currentIndex();
    bool right = ui->TFRight->currentIndex();

    int operation = ui->CMBMid->currentIndex();

    bool result = false;

    switch (operation) {
    case 0:  //and

        ui->TFLeft->show();

        result = left && right;
        break;

    case 1:  //or

        ui->TFLeft->show();

        result = left || right;
        break;

    case 2:  //negative

        ui->TFLeft->hide();

        if (right==1){
            result=false;
        }
        else {
            result=true;
        }
        break;

    case 3: //implication

        ui->TFLeft->show();

        if (((left==1)&&(right==1)) || ((left==0)&&(right==1)) || ((left==0)&&(right==1)) || ((left==0)&&(right==0))){
            result=true;
        }
        else {
            result=false;
        }
        break;

    case 4: //equivalence

        ui->TFLeft->show();

        if ((left==1)&&(right==1) || (left==0)&&(right==0))
        {
            result=true;
        }
        else{
            result=false;
        }
        break;

    case 5: //xor

        ui->TFLeft->show();

        if (((left==0)&&(right==1)) || ((left==1)&&(right==0))){
                result=true;
    }
                else{
                result=false;
    }
                break;

    }


    //окраска окна
    QPalette p = this->palette();
    QColor color;

    p.setColor(QPalette::Window, (result ? Qt::green : Qt::red));
    this->setPalette(p);
}





#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_random_clicked()
{
    int number = rand() %100-1;
    QMessageBox::information(this, "Random Number", "Generated Number: " + QString::number(number), "OK");
}


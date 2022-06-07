#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->connect, &QPushButton::clicked, this, &Dialog::printDebug);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_editor_clicked()
{
    qDebug() << "I will print the time when printDebug and button are clicked.";
    printDebug();
}

void Dialog::printDebug()
{
    qInfo() << "Button Click Time: " << QDateTime::currentDateTime().toString();
    accept();
}


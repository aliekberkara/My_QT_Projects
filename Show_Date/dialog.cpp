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


void Dialog::on_date_clicked()
{
    QDate date = QDate::currentDate();
    QMessageBox::information(this, "Date", date.toString(), "OK");
}

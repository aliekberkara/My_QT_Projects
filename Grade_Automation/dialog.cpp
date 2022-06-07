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


void Dialog::on_calculate_clicked()
{
    QString name = ui->name->text();
    QString lesson = ui->lesson->text();
    int midterm = ui->midterm->text().toInt();
    int final_note = ui->final_note->text().toInt();
    int average = midterm * 0.4 + final_note * 0.6;

    if(ui->name->text() == "" || ui->lesson->text() == "" || ui->midterm->text() == "" || ui->final_note->text() == ""){
        ui->output->setText("Incomplete information was entered...");
    }

    else if(midterm > 100 || midterm < 0 || final_note > 100 || final_note < 0){
        ui->output->setText("Incorrect information was entered...");
    }

    else{
        if(average < 60 && average >= 0){
            ui->output->setText("A student named " + name + " failed " + lesson + " lesson.\nPassing Grade: " + QString::number(average));
        }
        else if(average >= 60 && average <= 100){
            ui->output->setText("A student named " + name + " passed " + lesson + " lesson.\nPassing Grade: " + QString::number(average));
        }
    }
}


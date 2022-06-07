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

int number, range1, range2;

void Dialog::on_generate_clicked()
{
    ui->guess->setVisible(true);
    if(ui->range1->text() == "" || ui->range2->text() == ""){
        ui->output->setText("Incomplete information was entered.");
    }
    else{
        range1 = ui->range1->text().toInt();
        range2 = ui->range2->text().toInt();
        srand(time(0));
        if(range1 >= range2){
            number = rand()%(range1-range2+1) + range2;
        }
        else{
            number = rand()%(range2-range1+1) + range1;
        }
        qDebug() << "Generated Number: " << number;
        ui->output->setText("");
    }
    ui->guess->setAutoRepeat(true);
}

void Dialog::on_guess_clicked()
{
    int guessing_number = 1;
    int number1;
    range1 = ui->range1->text().toInt();
    range2 = ui->range2->text().toInt();
    srand(time(0));
    while(ui->guess->autoRepeat() == true){
        if(range1 >= range2){
            number1 = rand()%(range1-range2+1) + range2;
        }
        else{
            number1 = rand()%(range2-range1+1) + range1;
        }
        if(number == number1){
            ui->output->setText("Right Guess!!!\nGuess Count: " + QString::number(guessing_number));
            ui->guess->setVisible(false);
            qDebug() << "Number: " << number1;
            break;
        }
        else{
            ui->output->setText("Wrong Guess!!!\nGuess Count: " + QString::number(guessing_number));
            guessing_number++;
            qDebug() << "Number: " << number1;
        }
    }
}


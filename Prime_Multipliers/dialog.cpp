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

int number;

void Dialog::on_random_clicked()
{
    int range1 = ui->range1->text().toInt();
    int range2 = ui->range2->text().toInt();
    srand(time(0));

    if(range1 >= range2){
        QMessageBox::warning(this, "Uyarı", "Aralıkları Kontrol Ediniz.", "Ok");
    }
    else{
        number = rand()%(range2-range1) + range1;
        ui->uret->setText("Üretilen Sayı: " + QString::number(number));
    }
}


void Dialog::on_listele_clicked()
{
    int i = 1, j = 2, state = 1;
    ui->liste->clear();
    ui->liste_2->clear();


    if(ui->liste->isEnabled() == true && ui->liste_2->isEnabled() == false){
        while(i <= number/2){
            if(number % i == 0){
                ui->liste->addItem(QString::number(i));
            }
            i++;
        }
        ui->liste->addItem(QString::number(number));
    }
    else if(ui->liste->isEnabled() == false && ui->liste_2->isEnabled() == true){
        while(i <= number/2){
            state = 1, j = 2;
            if(number % i == 0){
                    if(i == 2){
                        ui->liste_2->addItem(QString::number(i));
                    }
                    else if(i > 2){
                      while(j < i){
                        if(i % j == 0){
                            state = 0;
                        }
                        j++;
                      }
                      if(state == 1){
                          ui->liste_2->addItem(QString::number(i));
                      }
                    }
            }
            i++;
        }
        i = number;
        j = 2;
        while(j < i){
          if(i % j == 0){
              state = 0;
          }
          j++;
        }
        if(state == 1){
            ui->liste_2->addItem(QString::number(i));
        }

    }

    else if(ui->liste->isEnabled() == true && ui->liste_2->isEnabled() == true){
        while(i <= number/2){
            if(number % i == 0){
                ui->liste->addItem(QString::number(i));
            }
            i++;
        }
        ui->liste->addItem(QString::number(number));
        i =1;
        while(i <= number/2){
            state = 1, j = 2;
            if(number % i == 0){
                    if(i == 2){
                        ui->liste_2->addItem(QString::number(i));
                    }
                    else if(i > 2){
                      while(j < i){
                        if(i % j == 0){
                            state = 0;
                        }
                        j++;
                      }
                      if(state == 1){
                          ui->liste_2->addItem(QString::number(i));
                      }
                    }
            }
            i++;
        }

        i = number;
        j = 2;
        while(j < i){
          if(i % j == 0){
              state = 0;
          }
          j++;
        }
        if(state == 1){
            ui->liste_2->addItem(QString::number(i));
        }
    }
}


void Dialog::on_tum_stateChanged(int arg1)
{
    bool state = ui->liste->isEnabled();
    ui->liste->setEnabled(!state);
}


void Dialog::on_asal_stateChanged(int arg1)
{
    bool state = ui->liste_2->isEnabled();
    ui->liste_2->setEnabled(!state);
}


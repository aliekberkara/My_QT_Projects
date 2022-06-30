#include "Duration.h"
#include <QFont>
#include <QThread>
#include <QMessageBox>
#include <QTime>
#include <QCoreApplication>


Duration::Duration(QGraphicsItem *parent): QGraphicsTextItem(parent){
    duration = 0;

    setPlainText(QString("Süre: ") + QString::number(duration));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

}

void Duration::reduction(){
    for(duration = 0; duration<=1000; duration++){
        delay();
        setPlainText(QString("Süre: ") + QString::number(duration));

        if(duration==1000){
            QMessageBox msgBox;
            msgBox.setStyleSheet("QLabel{min-width:320px; font-size:20px; color:red;} QPushButton{ width:150px; font-size:16px;}");
            msgBox.setText("GAME OVER");
            msgBox.setInformativeText("Good game.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            setPlainText(QString("Süre: ") + "1000");
            int ret = msgBox.exec();
            switch (ret) {
              case QMessageBox::Ok:
                exit(duration);
            }
        }
    }
}

int Duration::getDuration(){
    return duration;
}

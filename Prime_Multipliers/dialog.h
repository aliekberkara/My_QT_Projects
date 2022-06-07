#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_random_clicked();

    void on_listele_clicked();

    void on_tum_stateChanged(int arg1);

    void on_asal_stateChanged(int arg1);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
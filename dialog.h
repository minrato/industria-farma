#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_depozit_clicked();

    void on_amestec_clicked();

    void on_presa_clicked();

    void on_verificare_clicked();

    void on_ambalare_clicked();

    void on_acoperire_clicked();

    void on_progres_valueChanged(int value);

    void on_ok_clicked();

    void on_exit_clicked();

private:
    Ui::Dialog *ui;
    Dialog *dialog;
};

#endif // DIALOG_H

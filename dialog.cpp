#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

int total_pastile=0;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->amestec->hide();
    ui->comanda->hide();
    ui->presa->hide();
    ui->matrite->hide();
    ui->verificare->hide();
    ui->acoperire->hide();
    ui->ambalare->hide();
    ui->depozit->hide();

    ui->next_etap->hide();
    ui->text->hide();
    ui->progres->hide();
    ui->progr->hide();

    ui->progres->setValue(0);
    ui->lcd2->display(total_pastile);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_depozit_clicked()
{
    ui->progres->setValue(5);
    QMessageBox aux;
    QMessageBox::StandardButton reply = QMessageBox::information(this, "Succes!", "Ingredientele au fost aduse din depozit.");
    if(reply == QMessageBox::Ok)
    {
    ui->progres->setValue(10);
    ui->depozit->setDisabled(true);
    ui->amestec->setDisabled(false);
    ui->text->setText("Comandați amestecarea și uscarea ingredientelor.");

    }
}

void Dialog::on_amestec_clicked()
{
    ui->progres->setValue(15);
    ui->comanda->setDisabled(false);
    ui->amestec->setDisabled(true);
    QMessageBox::StandardButton reply = QMessageBox::information(this, "Progres", "Aparatul de amestecare și uscare trimite sistemului de comandă și control faptul că începe procesul.");
    if(reply == QMessageBox::Ok)
    {
        ui->progres->setValue(20);
        ui->comanda->setDisabled(true);
        ui->amestec->setDisabled(false);
        reply = QMessageBox::information(this, "Progres", "Sistemul de comandă și control setează temperatura și curenții de aer în aparatul de amestecare și uscare.");

        if(reply == QMessageBox::Ok)
        {
            ui->progres->setValue(25);
            reply = QMessageBox::information(this,"Progres", "Se execută amestecarea și uscarea ingredientelor.");
            if(reply == QMessageBox::Ok)
            {
                ui->progres->setValue(30);
                ui->amestec->setDisabled(true);
                ui->presa->setDisabled(false);
                ui->text->setText("Comandați modelarea pastilelor.");

            }
        }
    }
}

void Dialog::on_presa_clicked()
{
    ui->progres->setValue(35);
    ui->matrite->setDisabled(false);
    ui->presa->setDisabled(true);
    QMessageBox::StandardButton reply = QMessageBox::information(this,"Progres", "Presa comandă matriței distribuția de pudră.");
    if(reply == QMessageBox::Ok)
    {
        ui->progres->setValue(40);
//    ui->matrite->setDisabled(false);
//    ui->presa->setDisabled(true);
        ui->presa->setDisabled(false);
        ui->matrite->setDisabled(true);
        reply = QMessageBox::information(this,"Progres", "Matrița distribuie pudra presei.");
        if (reply == QMessageBox::Ok)
        {
            ui->progres->setValue(45);
//            ui->presa->setDisabled(false);
//            ui->matrite->setDisabled(true);

            reply = QMessageBox::information(this,"Progres", "Presa modelează pastilele");

            if(reply == QMessageBox::Ok)
            {
                ui->progres->setValue(50);
                ui->presa->setDisabled(true);
                ui->verificare->setDisabled(false);
                ui->text->setText("Comandați controlul de calitate al pastilelor.");

            }
        }
    }
}

void Dialog::on_verificare_clicked()
{
    ui->progres->setValue(55);
    QMessageBox::StandardButton reply = QMessageBox::information(this,"Progres", "Este efectuat controlul de calitate al pastilelor.");
    if(reply == QMessageBox::Ok)
        ui->progres->setValue(60);
    ui->verificare->setDisabled(true);
    ui->acoperire->setDisabled(false);
    ui->text->setText("Comandați acoperirea pastilelor cu soluție de colorant.");

}

void Dialog::on_acoperire_clicked()
{
    ui->progres->setValue(65);
    ui->acoperire->setDisabled(true);
    ui->depozit->setDisabled(false);
    QMessageBox::StandardButton reply = QMessageBox::information(this,"Progres", "Unitatea de acoperire cere depozitului soluția de colorant.");
    if(reply == QMessageBox::Ok)
    {
        ui->progres->setValue(70);
        ui->depozit->setDisabled(true);
        ui->acoperire->setDisabled(false);
        reply = QMessageBox::information(this,"Progres", "Depozitul trimite soluția de colorant unității de acoperire.");
        if(reply == QMessageBox::Ok)
        {
            ui->progres->setValue(75);
            reply = QMessageBox::information(this,"Progres", "Este efectuată stropirea pastilelor.");
            if(reply == QMessageBox::Ok)
            {
                ui->progres->setValue(80);
                ui->ambalare->setDisabled(false);
                ui->acoperire->setDisabled(true);
                ui->text->setText("Comandați ambalarea pastilelor.");
            }
        }
    }
}
void Dialog::on_ambalare_clicked()
{

   ui->progres->setValue(85);
   ui->depozit->setDisabled(false);
   ui->ambalare->setDisabled(true);

   QMessageBox::StandardButton reply = QMessageBox::information(this,"Progres", "Unitatea de ambalare cere depozitului folie de PVC și folie de aluminiu.");
   if(reply == QMessageBox::Ok)
   {
       ui->progres->setValue(90);
       ui->depozit->setDisabled(true);
       ui->ambalare->setDisabled(false);
       reply = QMessageBox::information(this,"Progres", "Depozitul trimite unității de ambalare foliile cerute.");
       if(reply == QMessageBox::Ok)
       {
           ui->progres->setValue(95);
           reply = QMessageBox::information(this,"Progres", "Este efectuată ambalarea pastilelor.");
           if(reply == QMessageBox::Ok)
           {
               ui->ambalare->setDisabled(true);
               ui->progres->setValue(100);
               ui->text->setText("");
           }
       }
   }
}



void Dialog::on_progres_valueChanged(int value)
{

    if(value==100)
    {
        total_pastile = total_pastile + ui->cate->value();
        ui->lcd2->display(total_pastile);
        ui->lcd1->display(0);
        QMessageBox::StandardButton reply = QMessageBox::information(this, "Final!", "Procesul a fost finalizat cu succes.");
        if (reply == QMessageBox::Ok)
            reply = QMessageBox::question(this, "Continuare?", "Doriți începerea producției unei alte tranșe?");
        if (reply == QMessageBox::Yes)
        {
            hide();
            dialog = new Dialog(this);
            dialog->show();
        }
        else
            QApplication::exit();

    }
}

void Dialog::on_ok_clicked()
{
    ui->label->hide();
    ui->cate->hide();
    ui->ok->hide();

    ui->amestec->show();
    ui->comanda->show();
    ui->presa->show();
    ui->matrite->show();
    ui->verificare->show();
    ui->acoperire->show();
    ui->ambalare->show();
    ui->depozit->show();
    ui->next_etap->show();
    ui->text->show();
    ui->progres->show();
    ui->progr->show();

    ui->amestec->setDisabled(true);
    ui->comanda->setDisabled(true);
    ui->presa->setDisabled(true);
    ui->matrite->setDisabled(true);
    ui->verificare->setDisabled(true);
    ui->acoperire->setDisabled(true);
    ui->ambalare->setDisabled(true);



    ui->lcd1->display(ui->cate->value());

}

void Dialog::on_exit_clicked()
{
    QApplication::exit();
}

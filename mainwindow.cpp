#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_next_clicked()
{
    QApplication::exit();

}

void MainWindow::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username == "admin" && password == "admin")
    {
        hide();
        dialog = new Dialog(this);
        dialog->show();
    }
    else
       QMessageBox::warning(this, "Încercare eșuată.", "Username sau parolă introduse greșit!");
}

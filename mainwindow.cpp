#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::label_set(QString text, QLabel *lab)
{
    lab->update();
    lab->setText(text);
}
void MainWindow::on_encryp_triggered()
{
    mode = 1;
    label_set("Исходный текст", ui->label);
    label_set("Ключ", ui->label_2);
    label_set("Криптограмма", ui->label_3);
}

void MainWindow::on_decryp_triggered()
{
    mode = 2;
    label_set("Криптограмма", ui->label);
    label_set("Ключ", ui->label_2);
    label_set("Исходный текст", ui->label_3);
}

void MainWindow::on_pushButton_clicked()
{
    QString key = ui->lineEdit_4->text();
    QString in = ui->lineEdit_5->text();
    QString cryp = setNewKey(key, in);
    if (mode == 1)
    {
       QString str = "";
       for (int i=0; i<in.length(); i++)
       {
           int k = (in.at(i).unicode()+cryp.at(i).unicode()-194) % 26 + 97;
           str.append(k);
       }
        ui->lineEdit_3->setText(str);
    };
    if (mode == 2)
    {
        QString str = "";
        for (int i=0; i<in.length(); i++)
        {
            int k = (in.at(i).unicode()-cryp.at(i).unicode()+26) % 26 + 97;
            str.append(k);
        }
        ui->lineEdit_3->setText(str);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

QString MainWindow::setNewKey(QString oldKey, QString in)
{
    QString new_key = "";
    int len_key = oldKey.length();
    int len_in = in.length();
    if (len_key < len_in)
    {
        for (int i=0; i<len_in;i++)
        {
            new_key.append(oldKey[i % len_key]);
        }
    }
    return new_key;
}

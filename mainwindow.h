#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int mode;//мод шифровка и дешифровка

    void label_set(QString text, QLabel *lab);

    char alph[27] = "abcdefghijklmnopqrstuvwxyz";

    QString setNewKey(QString oldKey, QString in);

private slots:
    void on_encryp_triggered();

    void on_decryp_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

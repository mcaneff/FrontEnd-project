#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QColor>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
bool sendMsg= false;
QString client= "Kyle";
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if (text== "")
        return;
    ui->textEdit->append("<"+ client+"> "+text);
    ui->lineEdit->clear();
    if (sendMsg == false) {
        newParticipant ( client );
    }

}

void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_pushButton_clicked();
}

void MainWindow::newParticipant(const QString nick)
{
    if (nick.isEmpty())
        return;

      QColor color = ui->textEdit->textColor();
      ui->textEdit->setTextColor(Qt::gray);
      ui->textEdit->append(tr("* %1 has joined").arg(nick));
      ui->textEdit->setTextColor(color);
      ui->listWidget->addItem(nick);
      sendMsg=true;
}

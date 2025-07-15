#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QLineEdit>
#include <QString>
#include <string>
#include <QDateTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  //tcpConnect();
  //connect(ui->pushButtonStart,SIGNAL(clicked(bool)),this,SLOT(putData()));

  connect(ui->horizontalSliderMax, &QSlider::valueChanged,
          ui->lcdNumberMax, QOverload<int>::of(&QLCDNumber::display));

  connect(ui->HorizontalSliderMin, &QSlider::valueChanged,
          ui->lcdNumberMin, QOverload<int>::of(&QLCDNumber::display));

  connect(ui->pushButtonConnect, SIGNAL(clicked(bool)), this, SLOT(tcpConnect()));
  connect(ui->pushButtonDisconnect, SIGNAL(clicked(bool)), this, SLOT(tcpDisconnect()));

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(putData()));
  connect(ui->pushButtonStart,SIGNAL(clicked(bool)),this,SLOT(putData()));
  connect(ui->pushButtonStart,SIGNAL(clicked(bool)),this,SLOT(startTimer()));
  connect(ui->pushButtonStop,SIGNAL(clicked(bool)),this,SLOT(stopTimer()));
  connect(ui->horizontalSliderTiming, SIGNAL(valueChanged(int)),this, SLOT(updateTimer()));

}

void MainWindow::tcpConnect(){
  socket->connectToHost(ui->lineEdit->text(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
      ui->label_conexao->setText("Connected!");
  }
  else{
    qDebug() << "Disconnected";
      ui->label_conexao->setText("Disconnected");
  }
}

void MainWindow::tcpDisconnect()
{
    if(socket->state()== QAbstractSocket::ConnectedState){
        socket->disconnectFromHost();
        ui->label_conexao->setText("Disconnected");
    }
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;
  int valor_min = 1;
  int valor_max = 1;

  if(socket->state()== QAbstractSocket::ConnectedState){

    int valor_min = ui->HorizontalSliderMin->value();
    int valor_max = ui->horizontalSliderMax->value();

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();

    if(valor_min <= valor_max){
        str = "set "+ QString::number(msecdate) + " " +
            QString::number(valor_min + rand()%((valor_max - valor_min)+1))+"\r\n";

        qDebug() << str;
        ui->textEditMostrador->append(str);

        qDebug() << socket->write(str.toStdString().c_str())
               << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
      }
    }
    else if(valor_min > valor_max){
        QMessageBox aviso;
        aviso.setWindowTitle("VALORES INVÁLIDOS");
        aviso.setText("REDEFINA UM MÍN MENOR QUE O MÁX");
        aviso.exec();
    }

  }
}

void MainWindow::startTimer()
{
    timer->start((ui->horizontalSliderTiming->value())*1000);
}

void MainWindow::stopTimer()
{
    timer->stop();
}

void MainWindow::updateTimer()
{
    if (timer->isActive()) {
        int periodo_ciclo = (ui->horizontalSliderTiming->value()) * 1000;
        timer->setInterval(periodo_ciclo); //Muda o periodo enquanto o timer esta funcionando
        qDebug() << "Timer atualizou para " << periodo_ciclo << "ms";
    }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}

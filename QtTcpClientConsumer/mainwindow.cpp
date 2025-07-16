#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->pushButtonConnect, SIGNAL(clicked(bool)), this, SLOT(tcpConnect()));
  connect(ui->pushButtonStart, SIGNAL(clicked(bool)), this, SLOT(getData()));
  connect(ui->pushButtonDisconnect, SIGNAL(clicked(bool)), this, SLOT(tcpDisconnect()));
  connect(ui->pushButtonUpdate, SIGNAL(clicked(bool)), this, SLOT(machineList()));
  connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(machineSelected(QListWidgetItem*)));

  //TIMER
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(getData()));
  connect(ui->pushButtonStart,SIGNAL(clicked(bool)),this,SLOT(startTimer()));
  connect(ui->pushButtonStop,SIGNAL(clicked(bool)),this,SLOT(stopTimer()));
  connect(ui->horizontalSliderTiming, SIGNAL(valueChanged(int)),this, SLOT(updateTimer()));
}

void MainWindow::tcpConnect(){
  socket->connectToHost(ui->lineEditIP->text(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }

  //A lista fica disponível assim que conecta
  machineList();
}

void MainWindow::tcpDisconnect()
{
    if(socket->state()== QAbstractSocket::ConnectedState){
        socket->disconnectFromHost();
    }
}

void MainWindow::machineSelected(QListWidgetItem *selecionado)
{
    machineIP = selecionado->text();
    qDebug() << "Máquina selecionada:" << machineIP;
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
        timer->setInterval(periodo_ciclo);
        qDebug() << "Timer atualizou para " << periodo_ciclo;
    }
}

void MainWindow::machineList()
{
    ui->listWidget->clear(); // limpa a lista antiga

    if (socket->state() == QAbstractSocket::ConnectedState) {
        if (socket->isOpen()) {
            socket->write("list\r\n"); // envia 'list'
            socket->waitForBytesWritten();
            socket->waitForReadyRead();

            while (socket->bytesAvailable()) {
                QString line = socket->readLine().trimmed();
                if (!line.isEmpty()) {
                    ui->listWidget->addItem(line); // adiciona na lista
                }
            }
        }
    } else {
        qDebug() << "Conexao falhou";
    }
}


void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;

  if(machineIP.isEmpty()){
      qDebug() << "Nenhuma maquina selecionada";
      return;
  }

  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      QString comando = QString("get %1 %2\r\n").arg(machineIP).arg(num_dados);
      socket->write(comando.toUtf8());

      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          qDebug() << "Tempo recebido:" << thetime;

          float valor = str.toFloat(&ok);

          tempos.append(thetime);
          valores.append(valor);

          if(tempos.size() > 30){
              tempos.removeFirst();
              valores.removeFirst();
          }
          qDebug() << "Dados recebidos: \n";
          qDebug() << thetime << ": " << str;

        }
      }

      //Ordenando os tempos?
      for (int i = 0; i < tempos.size() - 1; ++i) {
          for (int j = i + 1; j < tempos.size(); ++j) {
              if (tempos[j] < tempos[i]) {
                  std::swap(tempos[i], tempos[j]);
                  std::swap(valores[i], valores[j]);
              }
          }
      }

      ui->widget_plotter->setDados(tempos, valores);
    }
  }
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}

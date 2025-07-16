#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QListWidget>
#include <QTimer>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
  void getData();
  void tcpConnect();
  void tcpDisconnect();
  void machineList();
  void machineSelected(QListWidgetItem *selecionado);
  void startTimer();
  void stopTimer();
  void updateTimer();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString machineIP;
  int num_dados = 5;
  QTimer *timer;
  QVector<qint64> tempos;
  QVector<float> valores;
};

#endif // MAINWINDOW_H

#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QVector>

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    // Receber as informações do mainwindow
    void setDados(const QVector<qint64> &tempo, const QVector<float> &valor);

public slots:
    void paintEvent(QPaintEvent *event);

private:
    QVector<qint64> tempos;
    QVector<float> valores;

signals:
};

#endif // PLOTTER_H

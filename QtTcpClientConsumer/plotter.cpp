#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{}

void Plotter::setDados(const QVector<qint64> &tempo, const QVector<float> &valor)
{
    tempos = tempo;
    valores = valor;
    repaint();
}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter pintor(this);
    QBrush pincel;
    QPen caneta;

    pintor.setRenderHint(QPainter::Antialiasing);
    pincel.setColor(QColorConstants::Yellow);
    pincel.setStyle(Qt::SolidPattern);
    caneta.setColor(QColorConstants::DarkBlue);
    caneta.setWidth(2);
    pintor.setBrush(pincel);
    pintor.setPen(caneta);
    pintor.drawRect(0,0,width(),height());

    if (tempos.size() < 2 || valores.size() < 2 || valores.size() != tempos.size()) {
        qDebug() << "Sem dados suficientes para plotagem";
        return;
    }

    // Ajustar os limites do grafico para o Qt nao desenhar fora da tela, graças aos valores recebidos
    qint64 tempoMin = *std::min_element(tempos.begin(), tempos.end());
    qint64 tempoMax = *std::max_element(tempos.begin(), tempos.end());
    float valorMin = *std::min_element(valores.begin(), valores.end());
    float valorMax = *std::max_element(valores.begin(), valores.end());

    if (tempoMin == tempoMax) tempoMax += 1; // Evitar divisão por zero
    if (valorMin == valorMax) valorMax += 1;

    caneta.setColor(QColorConstants::Red);
    pintor.setPen(caneta);

    // Colocar os pontos na escala do grafico
    for (int i = 0; i < tempos.size() - 1; ++i) {
        int x0 = (tempos[i] - tempoMin) * width() / (tempoMax - tempoMin);
        int y0 = height() - (valores[i] - valorMin) * height() / (valorMax - valorMin);

        int x1 = (tempos[i+1] - tempoMin) * width() / (tempoMax - tempoMin);
        int y1 = height() - (valores[i+1] - valorMin) * height() / (valorMax - valorMin);

        pintor.drawLine(x0, y0, x1, y1);
    }

}

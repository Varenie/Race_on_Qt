#ifndef PLAYER_CAR_H
#define PLAYER_CAR_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <Windows.h>//для проверки состояния клавиш

class Player_car: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player_car(QObject *parent = 0);
    ~Player_car();
signals:
    void signalCheck(QGraphicsItem *item);
    void signalGameOver();//сигнал конца игры
public slots:
    void slotGameTimer();//обработка перемещений

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLAYER_CAR_H

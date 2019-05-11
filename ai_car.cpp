#include "ai_car.h"
#include "widget.h"

AI_car::AI_car(QObject *parent)
:QObject(parent), QGraphicsItem ()
{

}

AI_car::~AI_car()
{

}

QRectF AI_car::boundingRect() const
{
    return QRectF(-25,-40,50,80); //ограничение области в которой лежит машина
}

void AI_car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;//отрисовка транспорта

    polygon << QPoint(0,45) << QPoint(-25,-40) << QPoint(25,-40);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void AI_car::slotGameTimerAI()
{
    setPos(mapToParent(0,5));
}

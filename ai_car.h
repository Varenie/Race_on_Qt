#ifndef AI_CAR_H
#define AI_CAR_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class AI_car: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit AI_car(QObject *parent = 0);
    ~AI_car();
public slots:
    void slotGameTimerAI();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // AI_CAR_H

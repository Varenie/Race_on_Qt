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
signals:

public slots:
    void slotGameTimerAI();//слот движения машин компьютера
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // AI_CAR_H

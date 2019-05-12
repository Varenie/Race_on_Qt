#include "player_car.h"

Player_car::Player_car(QObject *parent)
    :QObject(parent), QGraphicsItem ()
{

}

Player_car::~Player_car()
{

}

QRectF Player_car::boundingRect() const
{
    return QRectF(-25,-40,50,80); //ограничение области в которой лежит машина
}

void Player_car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;//отрисовка транспорта

    polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
    painter->setBrush(Qt::blue);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Player_car::slotGameTimer()
{
    //создание поля видимости перед машиной игрока
    QList<QGraphicsItem*> foundItems = scene()->items(QPolygonF()
                              << mapToScene(0,0) << mapToScene(-20,-20) << mapToScene(20, -20));

    foreach (QGraphicsItem *item, foundItems)//проверяем все элементы, один из которых сама машина игрока
    {
        if (item == this)
            continue;
        emit signalCheck(item);
    }

    //движения машинки
    if(GetAsyncKeyState(VK_LEFT))
        setPos(mapToParent(-5,0));
    if(GetAsyncKeyState(VK_RIGHT))
        setPos(mapToParent(5,0));
    if(GetAsyncKeyState(VK_UP))
        setPos(mapToParent(0,-5));
    if(GetAsyncKeyState(VK_DOWN))
        setPos(mapToParent(0,5));


    //проверка на выход за карту
    if(this->x() - 10 < -250)
    {
        this->setX(-240);       // слева
        emit signalGameOver();
    }
    if(this->x() + 10 > 250)
    {
        this->setX(240);        // справа
        emit signalGameOver();
    }
    if(this->y() - 10 < -250)
    {
        this->setY(-240);       // сверху
        emit signalGameOver();
    }
    if(this->y() + 10 > 250)
    {
        this->setY(240);        // снизу
        emit signalGameOver();
    }
}



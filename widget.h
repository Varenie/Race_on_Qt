#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QShortcut>
#include <player_car.h>
#include <ai_car.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
    QGraphicsScene *scene;// объявление графической сцены
    Player_car *player_car;// объявление машины игрока
    AI_car *ai_car;//объявление машины компьютера
    QTimer *timer;// таймер для обновления перемещения объекта
    QTimer *createCar;//таймер для создания машин компьютера
    QTimer *moveCar;//для перемещения машины

    QList<QGraphicsItem *> cars;//список с машинами компьютера

private slots:
    void slotDeleteCar(QGraphicsItem * item);//функция удаления машин
    void slotCreateCar();//функция созадния машин
    void slotGameOver();//функция конца игры
};

#endif // WIDGET_H

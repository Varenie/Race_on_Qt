#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QShortcut>
#include <player_car.h>

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
    QTimer *timer;// таймер для обновления перемещения объекта
};

#endif // WIDGET_H

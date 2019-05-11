#include "widget.h"
#include "ui_widget.h"
#include <QCoreApplication>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);//задание размеров виджета
    this->setFixedSize(600,600);//фиксирование размеров виджета

    scene = new QGraphicsScene();//инициализация графической сцены
    player_car = new Player_car();//инициализация машины игрока


    ui->graphicsView->setScene(scene);//установка сцены в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);//сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//выключение вертикального скроллбара
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//выключение горизонтального скролбара

    scene->setSceneRect(-250,-250,500,500);//размер графической сцены

    //отрисовка границ поля
    scene->addLine(-250, -250, 250, -250, QPen(Qt::black));//верх
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));//низ
    scene->addLine(-250, -250, -250, 250, QPen(Qt::black));//лево
    scene->addLine(250, -250, 250, 250, QPen(Qt::black));//право
    scene->addLine(0,-250, 0, 250, QPen(Qt::black));//средняя линия

    scene->addItem(player_car);//добавляем машину
    player_car->setPos(0,200);//устанавливаем ее на заданные координаты


    timer = new QTimer();//для машины игрока
    connect(timer, &QTimer::timeout, player_car, &Player_car::slotGameTimer);
    timer->start(1000/50);

    createCar = new QTimer();//для машины компьютера
    connect(createCar, &QTimer::timeout, this, &Widget::slotCreateCar);
    createCar->start(2000);
}

void Widget::slotCreateCar()
{
    AI_car *car = new AI_car();//создание машины
    scene->addItem(car);
    car->setPos((qrand() % (251)) * ((qrand()%2 == 1)?1:-1),-230);
    cars.append(car);


    moveCar = new QTimer();
    connect(moveCar, &QTimer::timeout, car, &AI_car::slotGameTimerAI);
    moveCar->start(1000/20);
}

void Widget::slotDeleteCar(QGraphicsItem *item)
{
    foreach (QGraphicsItem *car, cars)
    {
        if(car == item)
        {
            scene->removeItem(car);
            cars.removeOne(item);
            delete car;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

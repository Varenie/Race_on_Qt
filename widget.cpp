#include "widget.h"
#include "ui_widget.h"

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
    scene->addLine(-250, -250, 250, -250, QPen(Qt::black));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    scene->addLine(-250, -250, -250, 250, QPen(Qt::black));
    scene->addLine(250, -250, 250, 250, QPen(Qt::black));

    scene->addItem(player_car);//добавляем машину
    player_car->setPos(0,0);//устанавливаем ее на заданные координаты


    timer = new QTimer();
    connect(timer, &QTimer::timeout, player_car, &Player_car::slotGameTimer);
    timer->start(1000/50);
}

Widget::~Widget()
{
    delete ui;
}

#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3;

    //setup health text
    setPlainText(QString("Health: ")+ QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    setPos(0,25);
}

void Health::decreaseHealth(){
    if (health > 0){
        health--;
        setPlainText(QString("Health: ")+ QString::number(health));
    }
}

int Health::getHealth(){
        return health;
}



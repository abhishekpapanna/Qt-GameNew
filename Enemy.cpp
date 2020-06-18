#include "Enemy.h"
#include <stdlib.h>
#include <QGraphicsItem>
#include <QTimer>
#include "Game.h"


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    //random number for random spawn location for enemies
    int spawn_location = rand() % 700;
    setPos(spawn_location,0);

    //draw the enemy
    setPixmap(QPixmap(":/images/Enemy2.png"));

    // move the enemy down (defined in class, slower compared to bullet)
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // move effect
    timer->start(50);

    //connect the enemy to player's endgame
    connect(this,SIGNAL(gameend()),game->player,SLOT(endgame()));
}

void Enemy::move(){
    setPos(x(),y()+5);

    //if enemy reaches bottom of the screen decrease health and remove enemy
    if(pos().y() > 600){
        game->health->decreaseHealth();
        scene()->removeItem(this);
        delete this;
    }

    int n=game->health->getHealth();
    if (n == 0){
        emit gameend();
    }
}

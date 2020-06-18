#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    //draw the bullet
    setPixmap(QPixmap(":/images/Bullet2.png"));

    //move the bullet up
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //start the timer
    timer->start(50);

    explosion = new QMediaPlayer();
    explosion->setMedia(QUrl("qrc:/sounds/Blast.mp3"));
}

void Bullet::move(){
    //get a list of all items colliding with 'this' bullet
    QList <QGraphicsItem *> colliding_items = collidingItems();

    //If the bullet is colliding with enemy, then destroy both
    for (int i=0, n=colliding_items.size();i < n; ++i){
        if(typeid (* colliding_items[i]) == typeid (Enemy)){
            //increase the score
            game->score->increase();

            //Play Explosion sound
            if(explosion->state() == QMediaPlayer::PlayingState){
                explosion->setPosition(0);
            }
            else if (explosion->state() == QMediaPlayer::StoppedState){
                explosion->play();
            }

            //remove both from scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete items from memory
            delete colliding_items[i];
            delete this;

            //Since bullet is deleted, the code below for move animation can cause trouble
            return;
        }
    }

    //normal move animation
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}


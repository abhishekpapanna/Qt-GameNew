#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"
#include <QGraphicsTextItem>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
        bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));

        //set graphics
        setPixmap(QPixmap(":/images/Player2.png"));
}

void Player::keyPressEvent(QKeyEvent * event){
    //move player left or right
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-20,y());
    }

    else if (event->key() == Qt::Key_Right){
        if(pos().x() < 700)
        setPos(x()+10,y());
    }

    else if (event->key() == Qt::Key_Space){
        if (bullets > 0){
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+40,y());
            scene()->addItem(bullet);

            //play bullet sound
            if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
            }
            else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
            }
        }
    }

}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::endgame(){
    bullets = 0;
    QGraphicsTextItem * text = new QGraphicsTextItem();
    text->setPos(350,300);
    text->setPlainText("GAME OVER!");
    scene()->addItem(text);
}


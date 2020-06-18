#include "Game.h"
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QImage>

Game::Game(QWidget * parent){
    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    //setup the scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Create player
    player = new Player();
    player->setPos(width()/2,600-100);

    //make player focussable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add player to the scene
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    scene->addItem(health);

    //spawning enemies
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //play background music
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/Planebg.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    show();
}

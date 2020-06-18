#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>


class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player (QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void endgame();

private:
    int bullets=50;
    QMediaPlayer * bulletsound;
};


#endif // PLAYER_H

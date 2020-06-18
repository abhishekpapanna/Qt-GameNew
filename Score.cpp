#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    score = 0;

    //draw the score
    setPlainText(QString("Score: ") + QString::number(score));       //initially when the score is 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));      //update score as it increases
}

int Score::getscore(){
    return score;
}

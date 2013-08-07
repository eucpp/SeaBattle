#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <QObject>
#include <QTime>

#include "types.h"
#include "player.h"

/**
  * Pretty stupid implementation of AI for sea battle game. It just choose random cell on each step.
  */
class AIPlayer : public Player
{
    Q_OBJECT
public:
    explicit AIPlayer(QObject* parent = 0);

public slots:
    /**
      * Nothing to thing about it, choose the random cell!
      */
    void turn();
};

#endif // AIPLAYER_H

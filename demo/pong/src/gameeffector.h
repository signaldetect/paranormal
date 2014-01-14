#ifndef _GAMEEFFECTOR_H_
#define _GAMEEFFECTOR_H_

#include <p/effector.h>

class GameEffector : public p::Effector<GameEffector> {
public:
  p__def(gameLaunched)
  p__def(gameStarted)
  p__def(gamePlaying)
  p__def(gameStopped)
};

#endif /*_GAMEEFFECTOR_H_*/

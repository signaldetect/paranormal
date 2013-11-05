#ifndef _GAMEEFFECTOR_H_
#define _GAMEEFFECTOR_H_

#include <p/effector.h>

class GameEffector : public p::Effector<GameEffector> {
  p__effects {
    p__(gameLaunched);
    p__(gamePlaying);
  }
};

#endif /*_GAMEEFFECTOR_H_*/

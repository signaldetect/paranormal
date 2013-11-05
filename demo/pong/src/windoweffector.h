#ifndef _WINDOWEFFECTOR_H_
#define _WINDOWEFFECTOR_H_

#include <p/effector.h>

class WindowEffector : public p::Effector<WindowEffector> {
  p__effects {
    p__(windowClosed);
  }
};

#endif /*_WINDOWEFFECTOR_H_*/

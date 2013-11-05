#ifndef _FIELDEFFECTOR_H_
#define _FIELDEFFECTOR_H_

#include <p/effector.h>

class FieldEffector : public p::Effector<FieldEffector> {
  p__effects {
    p__(fieldTimeStepped, float time);
  }
};

#endif /*_FIELDEFFECTOR_H_*/

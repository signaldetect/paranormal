#ifndef _P_EFFECTOR_H_
#define _P_EFFECTOR_H_

#include "channel.h"

namespace p {

/**
 * Base class for effectors
 *
 * T_E -- effector
 */
template <class T_E>
class Effector {
private:
  const typename Channel<T_E>::RecId id;

protected:
  Effector()
    : id(Channel<T_E>::instance().record(static_cast<T_E*>(this)))
  {
  }

  virtual ~Effector()
  {
    Channel<T_E>::instance().unrecord(id);
  }
};

}

/**
 * Macro for definition of an effect as part of effector
 */
#define p__def(_name_, ...) virtual void _name_(__VA_ARGS__) {}

/**
 * Macro for incarnation of an effect (prototype) as part of eventer
 */
#define p__inc(_name_, ...) void _name_(__VA_ARGS__) override;

#endif /*_P_EFFECTOR_H_*/

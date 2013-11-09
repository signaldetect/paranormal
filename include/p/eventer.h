#ifndef _P_EVENTER_H_
#define _P_EVENTER_H_

#include "channel.h"

namespace p {

/**
 * Mark in eventer template parameters for extenders (VT_X)
 */
template <class ...VT_X>
class Ext;

/**
 * Mark in eventer template parameters for actualizers (VT_A)
 */
template <class ...VT_A>
class Act;

/**
 * Base class for eventers
 *
 * Generic template for effectors (VT_E)
 */
template <class ...VT_E>
class Eventer : public VT_E... {
protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }
};

/**
 * Base class for eventers
 *
 * Specialization for extenders (V_X) and effectors (VT_E)
 */
template <class ...VT_X, class ...VT_E>
class Eventer<Ext<VT_X...>, VT_E...> : public VT_X..., public VT_E... {
protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }
};

/**
 * Base class for eventers
 *
 * Specialization for actualizer (T_A) and effectors (VT_E)
 */
template <class T_A, class ...VT_E>
class Eventer<Act<T_A>, VT_E...> : public VT_E... {
private:
  Channel<T_A>& channel = Channel<T_A>::instance();

protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }

  template <class t_Sign, t_Sign t_Effect, class ...vt_Args>
  void actualize(vt_Args&& ...args)
  {
    channel.template wave<t_Sign, t_Effect>(args...);
  }
};

/**
 * Base class for eventers
 *
 * Specialization for actualizer (T_A), extenders (VT_X) and effectors (VT_E)
 */
template <class T_A, class ...VT_X, class ...VT_E>
class Eventer<Act<T_A>, Ext<VT_X...>, VT_E...> : public VT_X...,
                                                 public VT_E... {
private:
  Channel<T_A>& channel = Channel<T_A>::instance();

protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }

  template <class t_Sign, t_Sign t_Effect, class ...vt_Args>
  void actualize(vt_Args&& ...args)
  {
    channel.template wave<t_Sign, t_Effect>(args...);
  }
};

/**
 * Base class for eventers
 *
 * Specialization for extenders (VT_X), actualizer (T_A) and effectors (VT_E)
 */
template <class ...VT_X, class T_A, class ...VT_E>
class Eventer<Ext<VT_X...>, Act<T_A>, VT_E...> : public VT_X...,
                                                 public VT_E... {
private:
  Channel<T_A>& channel = Channel<T_A>::instance();

protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }

  template <class t_Sign, t_Sign t_Effect, class ...vt_Args>
  void actualize(vt_Args&& ...args)
  {
    channel.template wave<t_Sign, t_Effect>(args...);
  }
};

}

/**
 * Macro for sign and link of an effect
 */
#define p__the(_effect_) decltype(&_effect_), &_effect_

#endif /*_P_EVENTER_H_*/

#ifndef _P_EVENTER_H_
#define _P_EVENTER_H_

#include "channel.h"
#include "binder.h"

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
 * Generic template for effectors/effects (VT_E)
 */
template <class T_Host, class ...VT_E>
class Eventer : public Binder<T_Host, VT_E>... {
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
 * Specialization for extenders (V_X) and effectors/effects (VT_E)
 */
template <class T_Host, class ...VT_X, class ...VT_E>
class Eventer<T_Host, Ext<VT_X...>, VT_E...> : public VT_X...,
                                               public Binder<T_Host, VT_E>... {
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
 * Specialization for actualizer (T_A) and effectors/effects (VT_E)
 */
template <class T_Host, class T_A, class ...VT_E>
class Eventer<T_Host, Act<T_A>, VT_E...> : public Binder<T_Host, VT_E>... {
private:
  Channel<T_A*>& channel = Channel<T_A*>::instance();

protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }

  template <class t_Sign, t_Sign t_Member, class ...vt_Args>
  void actualize(vt_Args ...args)
  {
    channel.template wave<t_Sign, t_Member>(args...);
  }
};

/**
 * Base class for eventers
 *
 * Specialization for actualizer (T_A), extenders (VT_X) and
 * effectors/effects (VT_E)
 */
template <class T_Host, class T_A, class ...VT_X, class ...VT_E>
class Eventer<T_Host, Act<T_A>, Ext<VT_X...>, VT_E...>
    : public VT_X..., public Binder<T_Host, VT_E>... {
private:
  Channel<T_A*>& channel = Channel<T_A*>::instance();

protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }

  template <class t_Sign, t_Sign t_Member, class ...vt_Args>
  void actualize(vt_Args ...args)
  {
    channel.template wave<t_Sign, t_Member>(args...);
  }
};

/**
 * Base class for eventers
 *
 * Specialization for extenders (VT_X), actualizer (T_A) and
 * effectors/effects (VT_E)
 */
template <class T_Host, class ...VT_X, class T_A, class ...VT_E>
class Eventer<T_Host, Ext<VT_X...>, Act<T_A>, VT_E...>
    : public VT_X..., public Binder<T_Host, VT_E>... {
private:
  Channel<T_A*>& channel = Channel<T_A*>::instance();

protected:
  Eventer()
  {
  }

  ~Eventer()
  {
  }

  template <class t_Sign, t_Sign t_Member, class ...vt_Args>
  void actualize(vt_Args ...args)
  {
    channel.template wave<t_Sign, t_Member>(args...);
  }
};

}

#endif /*_P_EVENTER_H_*/

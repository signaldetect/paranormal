#ifndef _P_BINDER_H_
#define _P_BINDER_H_

namespace p {

/**
 * Wrapper for effector (T_E)
 */
template <class T_Host, class T_E>
class Binder : public T_E::Type {
protected:
  Binder()
  {
    T_E::Type::template bind<T_Host, typename T_E::Whitelist>();
  }

  ~Binder()
  {
  }
};

}

#endif /*_P_BINDER_H_*/

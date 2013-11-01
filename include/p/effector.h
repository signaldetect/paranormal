#ifndef _P_EFFECTOR_H_
#define _P_EFFECTOR_H_

#include "channel.h"
#include "effects.h"

namespace p {

/**
 * Base class for effectors
 *
 * Generic template for effector (T_E) only
 */
template <class T_E, class ...VT_Rest>
class Effector {
public:
  typedef Effects<> Whitelist;
  typedef T_E Type;

private:
  typename Channel<T_E*>::RecId id;

public:
  /**
   * Entry-effect method
   * t_Member -- method-effect pointer
   */
  template <class t_Host, class t_Sign, t_Sign t_Member, class ...vt_Args>
  void entry(vt_Args ...args)
  {
    (static_cast<t_Host*>(this)->*t_Member)(args...);
  }

  /**
   * Invoker of entry-effect method
   * t_Member -- pointer to entry-effect method pointer
   */
  template <class t_Sign, t_Sign t_Member, class ...vt_Args>
  void wave(vt_Args ...args)
  {
    typedef void (T_E::*EntryEffect)(vt_Args ...);
    const EntryEffect entry_effect = static_cast<T_E*>(this)->*t_Member;
    // entry_effect -- entry-effect method pointer
    if (entry_effect != nullptr)
      (static_cast<T_E*>(this)->*entry_effect)(args...);
  }

protected:
  Effector()
    : id(Channel<T_E*>::instance().record(static_cast<T_E*>(this)))
  {
  }

  ~Effector()
  {
    Channel<T_E*>::instance().unrecord(id);
  }
};

/**
 * Base class for effectors
 *
 * Specialization for effects only
 */
template <class T_Sign, T_Sign T_Member, class ...VT_Rest>
class Effector<Effect<T_Sign, T_Member>, VT_Rest...> {
public:
  typedef Effects<Effect<T_Sign, T_Member>, VT_Rest...> Whitelist;
  typedef typename Whitelist::Type Type;
};

}

/**
 * Macros for definition of an effector
 */

#include "binding.h"

/**
 * Definition of effects as part of effector
 */
#define p__effects \
protected: \
  template <class t_Host, class t_Whitelist> \
  void bind()

/**
 * Definition of effect as part of effector
 */
#define p__(_name_, ...) \
    bind_##_name_<t_Host, t_Whitelist>(); \
  } \
  \
public: \
  void (Effector::Type::*_name_)(__VA_ARGS__);  \
  \
private: \
  template <class t_Host, class t_Whitelist> \
  void bind_##_name_() \
  { \
    _name_ = p::Binding</*Init=*/p::Effect<p__the(Effector::Type::_name_)>, \
                        t_Whitelist, \
                        /*Dest=*/p::Effect<p__the(t_Host::_name_)>>::value

#endif /*_P_EFFECTOR_H_*/

#ifndef _P_CHANNEL_H_
#define _P_CHANNEL_H_

#include <list>

namespace p {

/**
 * Collection (singleton) of effectors of a specific type (T_E)
 */
template <class T_E>
class Channel : public std::list<T_E*> {
public:
  typedef std::list<T_E*> Type;
  typedef typename Type::iterator RecId;

private:
  RecId cursor = Type::end(); // iterator position in method-wave process

public:
  static Channel<T_E>& instance()
  {
    static Channel<T_E> channel_inst;
    return channel_inst;
  }

  const RecId record(T_E* effector)
  {
    Type::push_front(effector);
    return Type::begin();
  }

  void unrecord(const RecId& id)
  {
    if (id != Type::end()) {
      if (id == cursor)
        --cursor;
      Type::erase(id);
    }
  }

  /**
   * Invoker of method-effects
   * t_Effect -- pointer to method-effect
   */
  template <class t_Sign, t_Sign t_Effect, class ...vt_Args>
  void wave(vt_Args&& ...args)
  {
    if (cursor == Type::end()) {
      for (cursor = Type::begin(); cursor != Type::end(); ++cursor)
        ((*cursor)->*t_Effect)(args...);
    }
    else {
      RecId it;
      for (it = Type::begin(); it != Type::end(); ++it) {
        if (it == cursor) {
          ((*it)->*t_Effect)(args...); // cursor value may change in
                                       // method-effect (t_Effect) process =>
          it = cursor;                 // => change the it == cursor value too
        }
        else
          ((*it)->*t_Effect)(args...);
      }
    }
  }

private:
  Channel()
  {
  }

  ~Channel()
  {
  }

  Channel(const Channel&);
  Channel& operator =(const Channel&);
};

}

#endif /*_P_CHANNEL_H_*/

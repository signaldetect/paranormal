#ifndef _P_CHANNEL_H_
#define _P_CHANNEL_H_

#include <list>

namespace p {

/**
 * Collection (singleton) of effectors of a specific type (T_E)
 */
template <class T_E>
class Channel : public std::list<T_E> {
public:
  typedef std::list<T_E> Type;
  typedef typename Type::iterator RecId;

private:
  RecId cursor = Type::end();

public:
  static Channel<T_E>& instance()
  {
    static Channel<T_E> channel_inst;
    return channel_inst;
  }

  const RecId record(const T_E& effector)
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

  template <class t_Sign, t_Sign t_Member, class ...vt_Args>
  void wave(vt_Args&& ...args)
  {
    if (cursor == Type::end()) {
      for (cursor = Type::begin(); cursor != Type::end(); ++cursor)
        (*cursor)->template wave<t_Sign, t_Member>(args...);
    }
    else {
      RecId it;
      for (it = Type::begin(); it != Type::end(); ++it) {
        if (it == cursor) {
          (*it)->template wave<t_Sign, t_Member>(args...);
          it = cursor;
        }
        else
          (*it)->template wave<t_Sign, t_Member>(args...);
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

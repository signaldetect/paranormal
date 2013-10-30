#ifndef _P_EFFECT_H_
#define _P_EFFECT_H_

namespace p {

/**
 * Effect as class member (T_Member) with a specific signature (T_Sign)
 *
 * Generic template
 */
template <class T_Sign, T_Sign T_Member>
class Effect;

/**
 * Effect as class member with a specific signature
 *
 * Specialization for method-effect pointer
 * Abbreviation:
 *   T_H -- Host (host of member)
 *   T_M -- Member (method-effect pointer)
 */
template <class T_H, class ...VT_Args, void (T_H::*T_M)(VT_Args...)>
class Effect<void (T_H::*)(VT_Args...), T_M> {
public:
  typedef T_H Host;
};

/**
 * Effect as class member with a specific signature
 *
 * Specialization for pointer to method-effect pointer
 * Abbreviation:
 *   T_H -- Host (host of member)
 *   T_M -- Member (pointer to method-effect pointer)
 */
template <class T_H, class ...VT_Args, void (T_H::*(T_H::*T_M))(VT_Args...)>
class Effect<void (T_H::*(T_H::*))(VT_Args...), T_M> {
public:
  typedef T_H Host;
};

}

/**
 * Macros for definition of an effect
 */

#define the(_effect_) decltype(&_effect_), &_effect_

#define P_Effect(_Host_, _effect_) p::Effect<the(_Host_::_effect_)>

#endif /*_P_EFFECT_H_*/

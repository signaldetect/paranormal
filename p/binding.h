#ifndef _P_BINDING_H_
#define _P_BINDING_H_

#include "effect.h"
#include "helpers.h"
#include "effector.h"

namespace p {

/**
 * Binding of definition of the effect (Init Effect) from the effector with
 * the effect (Dest Effect) in the eventer
 *
 * Generic template
 * Abbreviation:
 *   T_IE -- Init Effect
 *   T_DE -- Dest Effect
 */
template <class T_IE, class T_Whitelist, class T_DE,
          class T_Available = typename Accessity<T_IE, T_Whitelist>::Type>
class Binding;

/**
 * Binding of definition of the effect (Init Member) from the effector
 * (Init Host) with the effect (Dest Member) in the eventer (Dest Host)
 *
 * Specialization with positive result
 * Abbreviation:
 *   T_IH -- Init Host (host of init member)
 *   T_DH -- Dest Host (host of dest member)
 *   T_IM -- Init Member (pointer to method-effect pointer)
 *   T_DM -- Dest Member (method-effect pointer)
 */
template <class T_IH, class T_DH, class ...VT_Args,
          void (T_IH::*(T_IH::*T_IM))(VT_Args...), class T_Whitelist,
          void (T_DH::*T_DM)(VT_Args...)>
class Binding<Effect<void (T_IH::*(T_IH::*))(VT_Args...), T_IM>, T_Whitelist,
              Effect<void (T_DH::*)(VT_Args...), T_DM>,
              /*T_Available=*/True> {
private:
  typedef void (T_IH::*EntryEffect)(VT_Args...);
  typedef void (T_DH::*DestSign)(VT_Args...);

public:
  static constexpr EntryEffect value = &Effector<T_IH>::
                                       template entry<T_DH, DestSign, T_DM>;
};

/**
 * Binding of definition of the effect (Init Member) from the effector
 * (Init Host) with the effect (Dest Member) in the eventer
 *
 * Specialization with negative result
 * Abbreviation:
 *   T_IH -- Init Host (host of init member)
 *   T_IM -- Init Member (pointer to method-effect pointer)
 *   T_DS -- Dest Sign (sign of dest member)
 *   T_DM -- Dest Member (method-effect pointer)
 */
template <class T_IH, class ...VT_Args,
          void (T_IH::*(T_IH::*T_IM))(VT_Args...), class T_Whitelist,
          class T_DS, T_DS T_DM>
class Binding<Effect<void (T_IH::*(T_IH::*))(VT_Args...), T_IM>, T_Whitelist,
              Effect<T_DS, T_DM>,
              /*T_Available=*/False> {
private:
  typedef void (T_IH::*EntryEffect)(VT_Args...);

public:
  static constexpr EntryEffect value = nullptr;
};

}

#endif /*_P_BINDING_H_*/

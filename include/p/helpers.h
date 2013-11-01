#ifndef _P_HELPERS_H_
#define _P_HELPERS_H_

/**
 * Helper classes
 */

namespace p {

/**
 * Two types meaning true and false
 *
 * True type
 */
class True {
public:
  static const bool value = true;
};

/**
 * Two types meaning true and false
 *
 * False type
 */
class False {
public:
  static const bool value = false;
};

/**
 * Equality of types
 *
 * Generic template
 */
template <class T_First, class ...VT_Rest>
class Equality;

/**
 * Equality of types
 *
 * First and second types (T_First) are equal =>
 * => recursion specialization for other types
 */
template <class T_First, class ...VT_Rest>
class Equality<T_First, T_First, VT_Rest...>
    : public Equality<T_First, VT_Rest...> {
};

/**
 * Equality of types
 *
 * There is one type (T_Single) =>
 * => terminating recursion specialization with positive result
 */
template <class T_Single>
class Equality<T_Single> {
public:
  typedef True Type;
  typedef T_Single EqualType;
};

/**
 * Equality of types
 *
 * Types T_First != T_Second =>
 * => terminating recursion specialization with negative result
 */
template <class T_First, class T_Second, class ...VT_Rest>
class Equality<T_First, T_Second, VT_Rest...> {
public:
  typedef False Type;
};

/**
 * Accessibility of element (T_Entity) with whitelist (T_Whitelist)
 *
 * Generic template
 */
template <class T_Entity, class T_Whitelist>
class Accessity;

/**
 * Accessibility of element
 *
 * Whitelist is empty (T_List<>) =>
 * => terminating specialization with positive result
 */
template <class T_Entity, template <class ...> class T_List>
class Accessity<T_Entity, T_List<>> {
public:
  typedef True Type;
};

/**
 * Accessibility of element (T_EntityA)
 *
 * Whitelist has element (T_EntityB) and T_EntityA != T_EntityB =>
 * => recursion specialization for other elements
 */
template <class T_EntityA, template <class ...> class T_List, class T_EntityB,
          class T_Other, class ...VT_Rest>
class Accessity<T_EntityA, T_List<T_EntityB, T_Other, VT_Rest...>>
    : public Accessity<T_EntityA, T_List<T_Other, VT_Rest...>> {
};

/**
 * Accessibility of element (T_Entity)
 *
 * Whitelist has element (T_Entity) =>
 * => terminating recursion specialization with positive result
 */
template <class T_Entity, template <class ...> class T_List,
          class T_Other, class ...VT_Rest>
class Accessity<T_Entity, T_List<T_Entity, T_Other, VT_Rest...>> {
public:
  typedef True Type;
};

/**
 * Accessibility of element (T_Entity)
 *
 * Whitelist has one element (T_List<T_Entity>) =>
 * => terminating recursion specialization with positive result
 */
template <class T_Entity, template <class ...> class T_List>
class Accessity<T_Entity, T_List<T_Entity>> {
public:
  typedef True Type;
};

/**
 * Accessibility of element (T_EntityA)
 *
 * Whitelist has one element (T_List<T_EntityB>) and T_EntityA != T_EntityB =>
 * => terminating recursion specialization with negative result
 */
template <class T_EntityA, template <class ...> class T_List, class T_EntityB>
class Accessity<T_EntityA, T_List<T_EntityB>> {
public:
  typedef False Type;
};

}

#endif /*_P_HELPERS_H_*/

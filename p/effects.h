#ifndef _P_EFFECTS_H_
#define _P_EFFECTS_H_

#include "effect.h"
#include "helpers.h"

namespace p {

/**
 * List of effects (VT_E)
 *
 * Generic template
 */
template <class ...VT_E>
class Effects;

/**
 * List of effects
 *
 * Specialization for equality check
 */
template <class T_Sign, T_Sign T_Member, class ...VT_Rest>
class Effects<Effect<T_Sign, T_Member>, VT_Rest...> {
public:
  typedef typename Equality<typename Effect<T_Sign, T_Member>::Host,
                            typename VT_Rest::Host...>::EqualType Type;
};

}

/**
 * Macros for definition of a list of effects
 */

#define p__from(...) \
  p__cat(p__effects_, \
         p__idByNumArgs(__VA_ARGS__, \
                        62, 61, 60, 59, \
                        58, 57, 56, 55, 54, 53, 52, 51, 50, 49, \
                        48, 47, 46, 45, 44, 43, 42, 41, 40, 39, \
                        38, 37, 36, 35, 34, 33, 32, 31, 30, 29, \
                        28, 27, 26, 25, 24, 23, 22, 21, 20, 19, \
                        18, 17, 16, 15, 14, 13, 12, 11, 10,  9, \
                         8,  7,  6,  5,  4,  3,  2,  1,  0,  0))(__VA_ARGS__)

#define p__idByNumArgs(_01, _02, _03, _04, _05, _06, _07, _08, _09, _10, \
                       _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
                       _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
                       _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
                       _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
                       _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
                       _61, _62, _63, _id_, ...) _id_

#define p__cat(a, b) p__cat_(a, b)
#define p__cat_(a, b) a ## b

#define p__effects_0(...)

#define p__effects_1 p__effect

#define p__effects_2(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_1(_Host_, __VA_ARGS__)

#define p__effects_3(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_2(_Host_, __VA_ARGS__)

#define p__effects_4(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_3(_Host_, __VA_ARGS__)

#define p__effects_5(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_4(_Host_, __VA_ARGS__)

#define p__effects_6(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_5(_Host_, __VA_ARGS__)

#define p__effects_7(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_6(_Host_, __VA_ARGS__)

#define p__effects_8(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_7(_Host_, __VA_ARGS__)

#define p__effects_9(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_8(_Host_, __VA_ARGS__)

#define p__effects_10(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_9(_Host_, __VA_ARGS__)

#define p__effects_11(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_10(_Host_, __VA_ARGS__)

#define p__effects_12(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_11(_Host_, __VA_ARGS__)

#define p__effects_13(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_12(_Host_, __VA_ARGS__)

#define p__effects_14(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_13(_Host_, __VA_ARGS__)

#define p__effects_15(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_14(_Host_, __VA_ARGS__)

#define p__effects_16(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_15(_Host_, __VA_ARGS__)

#define p__effects_17(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_16(_Host_, __VA_ARGS__)

#define p__effects_18(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_17(_Host_, __VA_ARGS__)

#define p__effects_19(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_18(_Host_, __VA_ARGS__)

#define p__effects_20(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_19(_Host_, __VA_ARGS__)

#define p__effects_21(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_20(_Host_, __VA_ARGS__)

#define p__effects_22(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_21(_Host_, __VA_ARGS__)

#define p__effects_23(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_22(_Host_, __VA_ARGS__)

#define p__effects_24(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_23(_Host_, __VA_ARGS__)

#define p__effects_25(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_24(_Host_, __VA_ARGS__)

#define p__effects_26(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_25(_Host_, __VA_ARGS__)

#define p__effects_27(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_26(_Host_, __VA_ARGS__)

#define p__effects_28(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_27(_Host_, __VA_ARGS__)

#define p__effects_29(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_28(_Host_, __VA_ARGS__)

#define p__effects_30(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_29(_Host_, __VA_ARGS__)

#define p__effects_31(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_30(_Host_, __VA_ARGS__)

#define p__effects_32(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_31(_Host_, __VA_ARGS__)

#define p__effects_33(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_32(_Host_, __VA_ARGS__)

#define p__effects_34(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_33(_Host_, __VA_ARGS__)

#define p__effects_35(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_34(_Host_, __VA_ARGS__)

#define p__effects_36(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_35(_Host_, __VA_ARGS__)

#define p__effects_37(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_36(_Host_, __VA_ARGS__)

#define p__effects_38(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_37(_Host_, __VA_ARGS__)

#define p__effects_39(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_38(_Host_, __VA_ARGS__)

#define p__effects_40(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_39(_Host_, __VA_ARGS__)

#define p__effects_41(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_40(_Host_, __VA_ARGS__)

#define p__effects_42(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_41(_Host_, __VA_ARGS__)

#define p__effects_43(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_42(_Host_, __VA_ARGS__)

#define p__effects_44(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_43(_Host_, __VA_ARGS__)

#define p__effects_45(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_44(_Host_, __VA_ARGS__)

#define p__effects_46(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_45(_Host_, __VA_ARGS__)

#define p__effects_47(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_46(_Host_, __VA_ARGS__)

#define p__effects_48(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_47(_Host_, __VA_ARGS__)

#define p__effects_49(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_48(_Host_, __VA_ARGS__)

#define p__effects_50(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_49(_Host_, __VA_ARGS__)

#define p__effects_51(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_50(_Host_, __VA_ARGS__)

#define p__effects_52(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_51(_Host_, __VA_ARGS__)

#define p__effects_53(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_52(_Host_, __VA_ARGS__)

#define p__effects_54(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_53(_Host_, __VA_ARGS__)

#define p__effects_55(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_54(_Host_, __VA_ARGS__)

#define p__effects_56(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_55(_Host_, __VA_ARGS__)

#define p__effects_57(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_56(_Host_, __VA_ARGS__)

#define p__effects_58(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_57(_Host_, __VA_ARGS__)

#define p__effects_59(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_58(_Host_, __VA_ARGS__)

#define p__effects_60(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_59(_Host_, __VA_ARGS__)

#define p__effects_61(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_60(_Host_, __VA_ARGS__)

#define p__effects_62(_Host_, _name_, ...) \
  p__effect(_Host_, _name_), p__effects_61(_Host_, __VA_ARGS__)

#endif /*_P_EFFECTS_H_*/

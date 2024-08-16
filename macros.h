/* -*- C -*- */
/* macros.h */
/* erzeugt Dienstag, 05. September 2023 08:17 (C) 2023 von Leander Jedamus */
/* modifiziert Montag, 02. Oktober 2023 12:02 von Leander Jedamus */
/* modifiziert Dienstag, 05. September 2023 09:08 von Leander Jedamus */

#ifndef MACROS_H
#define MACROS_H 1

#include <math.h>

#ifndef EPSILON
  #define EPSILON 1E-10
#endif

#define double_equal(value1,value2) (fabs(value1 - value2) < EPSILON)
#define double_sgn(value) ((double_equal(value1,0.0)) ? ' ' : ((value > 0.0) ? '+' : '\0'))

#define SIZE(array,type) (sizeof(array)/sizeof(type))

#ifdef DEBUG
  #define PRINTF(fmt, ...) \
    if(printf(fmt, __VA_ARGS__) < 0) \
    { \
      perror("printf"); \
    }
#else
  #define PRINTF(fmt, ...) printf(fmt, __VA_ARGS__)
#endif

#endif /* MACROS_H */

/* vim:set cindent ai sw=2 */

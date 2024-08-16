/* -*- C -*- */
/* minmax.c */
/* erzeugt Montag, 17. Juli 2023 14:06 (C) 2023 von Leander Jedamus */
/* modifiziert Samstag, 02. September 2023 11:12 von Leander Jedamus */
/* modifiziert Dienstag, 15. August 2023 14:21 von Leander Jedamus */
/* modifiziert Donnerstag, 10. August 2023 18:50 von Leander Jedamus */
/* modifiziert Mittwoch, 26. Juli 2023 08:26 von Leander Jedamus */
/* modifiziert Mittwoch, 19. Juli 2023 08:14 von Leander Jedamus */
/* modifiziert Dienstag, 18. Juli 2023 07:41 von Leander Jedamus */
/* modifiziert Montag, 17. Juli 2023 14:59 von Leander Jedamus */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#include "types.h"
#include "max.h"

RUECKGABE max(CONST ull zahlen, ...) {
  va_list           args;
  RUECKGABE         max = (RUECKGABE) zahlen;
  ull               varg;

  printf("%" PRIRUECKGABE ",", max);
  va_start(args, zahlen);
  while((varg = va_arg(args, ull)) != (ull) RUECKGABE_MIN)
  {
    RUECKGABE arg = (RUECKGABE) varg;
    printf("%" PRIRUECKGABE ",", arg);

    if(max < arg) {
      max = arg;
    }
  };
  va_end(args);

  return max;
}

/* vim:set cindent ai sw=2: */


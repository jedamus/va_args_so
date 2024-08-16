/* -*- C -*- */
/* minmax.c */
/* erzeugt Montag, 17. Juli 2023 14:06 (C) 2023 von Leander Jedamus */
/* modifiziert Samstag, 02. September 2023 11:12 von Leander Jedamus */
/* modifiziert Dienstag, 15. August 2023 14:20 von Leander Jedamus */
/* modifiziert Donnerstag, 10. August 2023 18:49 von Leander Jedamus */
/* modifiziert Mittwoch, 26. Juli 2023 08:27 von Leander Jedamus */
/* modifiziert Mittwoch, 19. Juli 2023 08:13 von Leander Jedamus */
/* modifiziert Dienstag, 18. Juli 2023 07:40 von Leander Jedamus */
/* modifiziert Montag, 17. Juli 2023 14:59 von Leander Jedamus */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#include "types.h"
#include "min.h"

RUECKGABE min(CONST ull zahlen, ...) {
  va_list           args;
  RUECKGABE         min = (RUECKGABE) zahlen;
  ull               varg;

  printf("%" PRIRUECKGABE ",", min);
  va_start(args, zahlen);
  while((varg = va_arg(args, ull)) != (ull) RUECKGABE_MAX)
  {
    RUECKGABE arg = (RUECKGABE) varg;
    printf("%" PRIRUECKGABE ",", arg);

    if(min > arg) {
      min = arg;
    }
  };
  va_end(args);

  return min;
}


/* vim:set cindent ai sw=2: */


/* -*- C -*- */
/* args.c */
/* erzeugt Freitag, 07. Juli 2023 12:05 (C) 2023 von Leander Jedamus */
/* modifiziert Montag, 07. Oktober 2024 18:48 von Leander Jedamus */
/* modifiziert Freitag, 23. Februar 2024 07:51 von Leander Jedamus */
/* modifiziert Donnerstag, 22. Februar 2024 17:44 von Leander Jedamus */
/* modifiziert Montag, 25. September 2023 07:39 von Leander Jedamus */
/* modifiziert Dienstag, 19. September 2023 18:04 von Leander Jedamus */
/* modifiziert Samstag, 09. September 2023 08:43 von Leander Jedamus */
/* modifiziert Freitag, 08. September 2023 17:18 von Leander Jedamus */
/* modifiziert Samstag, 02. September 2023 11:12 von Leander Jedamus */
/* modifiziert Donnerstag, 31. August 2023 05:02 von Leander Jedamus */
/* modifiziert Mittwoch, 30. August 2023 18:28 von Leander Jedamus */
/* modifiziert Montag, 28. August 2023 08:30 von Leander Jedamus */
/* modifiziert Dienstag, 15. August 2023 15:53 von Leander Jedamus */
/* modifiziert Mittwoch, 26. Juli 2023 08:26 von Leander Jedamus */
/* modifiziert Dienstag, 18. Juli 2023 07:42 von Leander Jedamus */
/* modifiziert Montag, 17. Juli 2023 16:24 von Leander Jedamus */
/* modifiziert Montag, 10. Juli 2023 09:27 von Leander Jedamus */
/* modifiziert Freitag, 07. Juli 2023 12:59 von Leander Jedamus */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "project.h"
#include "version.h"
#include "types.h"
#include "macros.h"
#include "min.h"
#include "max.h"
#include "getlocaledir.h"
#include "gettext.h"
#include "clrscr.h"

#if defined __unix__ || defined __APPLE__
#include "getch.h"
#elif defined __WIN32__ || defined _MSC_VER || defined __MS_DOS__
  #include <conio.h>
#endif

#define MAX 0
#define MIN 1

int main(int argc, char *argv[]) {
  RUECKGABE zahl,rmax,rmin;
  char      *localedir = getlocaledir(argv[0]);
  RUECKGABE (*ptr[])(CONST ull zahlen, ...) = { max, min };
  int       zeichen;

#ifdef CLRSCR
  clrscr();
#endif

  setlocale(LC_ALL, "");
  bindtextdomain(PROJECT, localedir);
  textdomain(PROJECT);

  printf(_("%s V%s (C) %s by %s <%s>\n"), PROJECT, VERSION, YEARS, AUTHOR, AUTHOR_EMAIL);
  if (strlen(MAINTAINER) > 0) {
    printf(_("maintained by %s <%s>\n"), MAINTAINER, MAINTAINER_EMAIL);
  }
  if (strlen(LICENSE) > 0) {
    printf(_("published under license \"%s\"\n"), LICENSE);
  }

#ifdef DEBUG  
  printf("%s\n",localedir);
#endif

  printf("MIN=%" PRIRUECKGABE ":\n", RUECKGABE_MIN);
  printf("MAX=%" PRIRUECKGABE ":\n", RUECKGABE_MAX);


  printf(_("Enter a number: "));
  if(scanf("%" SCNRUECKGABE, &zahl) <= 0) {
    printf(_("Input error.\n"));
    zahl = 0;
  } /* if scanf */
  printf("%" PRIRUECKGABE "\n",zahl);
  
  rmax = (*ptr[MAX]) ((ull) zahl,7ULL,2ULL,3ULL,9ULL,8ULL,(ull) RUECKGABE_MIN);
  printf("\n");
  rmin = (*ptr[MIN]) ((ull) zahl,7ULL,2ULL,3ULL,9ULL,8ULL,(ull) RUECKGABE_MAX);

  printf("max=%" PRIRUECKGABE ",min=%" PRIRUECKGABE "\n",rmax,rmin);

  printf(_("Please press 'q' to end program!\n"));
  while ((zeichen=getch()) != 'q');

  free(localedir);

  return EXIT_SUCCESS;
}

/* vim:set cindent ai sw=2: */


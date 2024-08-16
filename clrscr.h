/* -*- C -*- */
/* clrscr.h */
/* erzeugt Mittwoch, 30. August 2023 12:02 (C) 2023 von Leander Jedamus */
/* modifiziert Donnerstag, 31. August 2023 11:11 von Leander Jedamus */
/* modifiziert Mittwoch, 30. August 2023 19:03 von Leander Jedamus */

#ifndef CLRSCR_H
#define CLRSCR_H 1

#include <stdio.h>

#if defined __unix__ || defined __APPLE__
  #define clrscr() printf("\ec")
/*  #define clrscr() printf("\e[2J") */
/*  #define clrscr() system("clear") */
/*  #include <ncurses.h>
  #define clrscr() clear() */
#elif defined __BORLANDC__ && defined __MSDOS__
  #include <conio.h>
#elif defined __WIN32__ || defined _MSC_VER
  #define clrscr() system("cls")
#else
  #define clrscr() printf("clrscr() - fehlerhafte Implementierung!\n")
#endif

#endif /* CLRSCR_H */

/* vim:set cindent ai sw=2 */


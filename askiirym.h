/*
 * askiirym.h
 *
 */

#ifndef ASKIIRYM_H
#define ASKIIRYM_H

#define VERSION "0.1.0"

#define MAX_NAME 32

#define get(s,p) scanf(s,p); getchar()

#if   defined(_WIN64)
#  define cl() system("cls")
#elif defined(_WIN32)
#  define cl() system("cls")
#elif defined(__linux)
#  define cl() system("clear")
#elif defined(__unix)
#  define cl() system("clear")
#else
#  define cl()
#endif

struct Hero {
    char name[MAX_NAME];
    char race;
    int hp;
    int defense;
    int attack;
    int money;
    int level;
};

void newGame(void);

#endif /* ASKIIRYM_H */

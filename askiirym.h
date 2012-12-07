/*
 * askiirym.h
 *
 */

#ifndef ASKIIRYM_H
#define ASKIIRYM_H

#define VERSION "0.1.0"

struct Hero {
    char name[32];
    int hp;
    int defence;
    int attack;
    int money;
    int level;
};

void newGame(void);

#endif /* ASKIIRYM_H */

/*
 * askiirym.c
 *
 * Created at:  07.12.2012 19:29:31
 *
 * Author:  Szymon Urbas <szymon.urbas@aol.com>
 *
 * License: the MIT license
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "askiirym.h"

/*
 * TODO: o  Askiirym
 *       o  Hero stats
 *       o  Loading saves
 *       o  De/coding saves
 *       o  Maybe some plot
 */

struct Hero player;

int main(void)
{

#if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) || defined(__MACH__)
  printf("You are using Mac OS. That means your probably too dumb to play this very intelligent game. Have a nice day and GTFO.\n");
  exit(1);
#endif

  int action;
  char yn;

  cl();
  printf("Welcome, you adverturer, to Askiirym v%s!\n", VERSION);
  printf("\n");
  printf("[1] Start a new adventure\n");
  printf("[2] Load an andventure (not working)\n");
  printf("\n");
askforaction:
  printf("What is your action? ");
  get("%d", &action);

  switch (action){
    case 1: printf("Are you sure? [yn] ");
            get("%c", &yn);
            switch (yn){
              case 'n':
              case 'N':
                printf("\nSee you soon, adventurer!\n\n");
                exit(0);
              case 'y':
              case 'Y':
                cl();
                printf("A new adventure is just about to begin!\n\n");
                newGame();
            }
            break;

    case 2: printf("\nHey, it's not working, toldya!\n\n");
            goto askforaction;
  }

  return 0;
}

void newGame(void)
{
  char yn;
  int action;

askforname:
  printf("So, what's your name, adventurer? (%d chars limit): ", MAX_NAME);
  fgets(player.name, MAX_NAME, stdin);
  // remove the newline
  player.name[strlen(player.name)-1] = '\0';
  printf("%s, is that right? [yn] ", player.name);
  get("%c", &yn);

  switch (yn){
    case 'y':
    case 'Y':
      break;
    default: goto askforname;
  }

  // some initialization
  player.maxhp   = 100;
  player.hp      = 100;
  player.defense = 10;
  player.attack  = 10;
  player.money   = 250;
  player.level   = 1;

  cl();
  printf("There we go! Now, what are you, %s?\n", player.name);
  printf("\n");
  printf("[1] Human\n");
  printf("[2] Elf\n");
  printf("[3] Orc\n");
  printf("[4] Gnome\n");
  printf("\n");
askforrace:
  printf("What is your choice? [1-4] ");
  get("%d", &action);

  cl();
  switch (action){
    case 1: printf("You seem to be a human, and get +110 to money!\n");
            player.money += 110;
            player.race = 'h';
            break;

    case 2: printf("It turned out you're an elf, you get +3 to defense!\n");
            player.defense += 3;
            player.race = 'e';
            break;

    case 3: printf("You are an orc, you are a strong, very ugly being, you get +3 to attack!\n");
            player.attack += 3;
            player.race = 'o';
            break;

    case 4: printf("It seems you are a gnome, very short creature, but very healthy, you are +30 more healthy!\n");
            player.maxhp += 30;
            player.hp += 30;
            player.race = 'g';
            break;

    default: printf("Unknown race %d [1-4].\n", action);
             goto askforrace;
  }
  printf("\n");

  printf("Tell me, where were you raised as a young being, %s?\n", player.name);
  printf("\n");
  printf("[1] In a town.\n");
  printf("[2] In a village.\n");
  printf("[3] In a forest.\n");
  printf("[4] In your father's workshop.\n");
  printf("\n");
askforraiseness:
  printf("Where was it? [1-4] ");
  get("%d", &action);

  cl();
  switch (action){
    case 1: printf("You were raised in a town, you know your way around. You get +100 money!\n");
            player.money += 100;
            break;

    case 2: printf("You were raised in a village. Life there wasn't too easy. You get +10 health points!\n");
            player.maxhp += 10;
            player.hp += 10;
            break;

    case 3: printf("You were raised in a forest. You know the ways to survive an a wildness, you get +2 to defense!\n");
            player.defense += 2;
            break;

    case 4: printf("Your father raised you in his workshop. You were ment to be a true man, stinking from a sweat. You get +3 to attack!\n");
            player.attack += 3;
            break;

    default: printf("Unknown option %d [1-4]\n", action);
             goto askforraiseness;
  }
  printf("\n");
}


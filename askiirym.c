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

#include "askiirym.h"

/*
 * TODO: o  Askiirym
 *       o  Hero stats
 *       o  Loading saves
 *       o  De/coding saves
 */

int main(void)
{
  int action;
  char yn;

  printf("Welcome, you adverturer, to Askiirym v%s!\n", VERSION);
  printf("\n");
  printf("[1] Start a new adventure\n");
  printf("[2] Load an andventure (not working)\n");
  printf("\n");
  printf("What is your action? ");
  scanf("%d", &action);

  switch (action){
    case 1: printf("Are you sure? [Yn] ");
            scanf(" %c", &yn);
            if (yn == 'n' || yn == 'N'){
              printf("\nSee you soon, adventurer!\n\n");
              exit(0);
            } else {
              printf("\nA new adventure is about to begin!\n");
              newGame();
            }
            break;

    case 2: printf("\nHey, it's not working, toldya!\n");
            exit(0);
  }

  return 0;
}

void newGame(void)
{
  printf("That's been your adventure!\n");
  exit(0);
}


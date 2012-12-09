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
#include <readline/readline.h>
#include <readline/history.h>

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
                break;
              default:goto askforaction;
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

  switch (action){
    case 1: cl();
            printf("You seem to be a human, and get +110 to money!\n");
            player.money += 110;
            player.race = 'h';
            break;

    case 2: cl();
            printf("It turned out you're an elf, you get +3 to defense!\n");
            player.defense += 3;
            player.race = 'e';
            break;

    case 3: cl();
            printf("You are an orc, you are a strong, very ugly being, you get +3 to attack!\n");
            player.attack += 3;
            player.race = 'o';
            break;

    case 4: cl();
            printf("It seems you are a gnome, very short creature, but very healthy, you are +30 more healthy!\n");
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


  switch (action){
    case 1: cl();
            printf("You were raised in a town, you know your way around. You get +100 money!\n");
            player.money += 100;
            break;

    case 2: cl();
            printf("You were raised in a village. Life there wasn't too easy. You get +10 health points!\n");
            player.maxhp += 10;
            player.hp += 10;
            break;

    case 3: cl();
            printf("You were raised in a forest. You know the ways to survive an a wildness, you get +2 to defense!\n");
            player.defense += 2;
            break;

    case 4: cl();
            printf("Your father raised you in his workshop. You were ment to be a true man, stinking from a sweat. You get +3 to attack!\n");
            player.attack += 3;
            break;

    default: printf("Unknown option %d [1-4]\n", action);
             goto askforraiseness;
  }

  printf("\n");

  printf("In age of 13 your parents kicked you out of home. Why did they do that?\n\n"
         "[1] Because you were too naughty?\n"
         "[2] You were too smart, and they didnt want you to waste your talents?\n"
         "[3] They lost your trust, because you had stolen money from them?\n"
         "[4] You left home without any help to look for true love?\n\n");
askforhomeleaving:
    printf("What is your choice? [1-4] ");
    get("%d", &action);


    switch (action){
        case 1:cl();
            printf("Since you were kid you couldnt stop your strenght, and you get +3 to attack!\n");
            player.attack+=3;
            break;
        case 2:cl();
            printf("You were very smart, and received a scholarship in size of 50 money!\n");
            player.money+=50;
            break;
        case 3:cl();
            printf("You stole your parens money and hide them under stone, so noone found them, but you feel bad because of that. You gain 100 money, but loose 1 attack and 1 defense\n");
            player.money+=100;
            player.attack-=1;
            player.defense-=1;
            break;
        case 4:cl();
            printf("You left your home looking for love, but after many weeks you realized true love doesn't exists. You only lost your time.\n");
            break;
        default: printf("Unknown option %d [1-4]\n", action);
            goto askforhomeleaving;
    }


    printf("\nAfter many years you realized, that world is full of dangers and hate. Endless wars destroyed your family land, and you left to Wanzaniia. You found work in:\n\n"
           "[1] Smithy\n"
           "[2] Carpentry shop\n"
           "[3] Shipyard\n"
           "[4] Potion shop\n\n");
askforwork:
    printf("What is your choice? [1-4] ");
    get("%d", &action);

    switch(action){
            case 1:cl();
                printf("In a smithy you understood real men must be strong. You get +3 attack!");
                player.attack+=3;
                break;
            case 2:cl();
                printf("As carpenter, you need to be very careful if you want to survive, and you gained +2 to defense!");
                player.defense+=2;
                break;
            case 3:cl();
                printf("In shipyard you invented new way to join ship parts, and earned 300 money because of that!");
                player.money+=300;
                break;
            case 4:cl();
                printf("In potion shop you got payment in potions, which made you healthier. 20 points healthier.");
                player.maxhp+=20;
                player.hp+=20;
                break;
            default:printf("Unknown option %d [1-4]\n", action);
                goto askforwork;
    }


    printf("\n\nAnd now you are here, between dirty Hunner Sea and high and steep Angin Mountains, heading to mistery Cimarian City. Why are you here?\n\n"
           "[1] You met christian monk, who told you to visit this area to clean your soul\n"
           "[2] You got a recommendation to work in nearest iron mine\n"
           "[3] You want to make good deal and earn some money\n"
           "[4] You are here to learn how to fight\n\n");
askforreason:
    printf("What is your choice? [1-4] ");
    get("%d",&action);

    switch (action){
        case 1:cl();
            printf("You cleant your soul and made yourself more healthy. You get +20 HP!\n");
            player.maxhp+=20;
            player.hp+=20;
            break;
        case 2:cl();
            printf("By working in mine you are getting stronger, and get extra +2 to attack! You also earned 50 money!\n");
            player.attack+=2;
            player.money+=50;
            break;
        case 3:cl();
            printf("You made it! You sold some trolls skins, and earned 130 money!\n");
            player.money+=130;
            break;
        case 4:cl();
            printf("After several weeks of training, your attack and defense raised by 2, but you had to pay 100 money for that!\n");
            player.attack+=2;
            player.defense+=2;
            player.money-=100;
            break;
        default:printf("Unknown option %d [1-4]\n", action);
            goto askforreason;
    }

    printf("\nNow, here is the actuall game. You can exit anytime by typing 'exit' or 'quit'.\n\n");
    mainLoop(player);
} // end of newGame

void mainLoop(struct Hero player)
{
  char *input, shell_prompt[100];

  for (;;){
    /* getting the current user */
    snprintf(shell_prompt, sizeof(shell_prompt), "%s:%d/%d> ", player.name, player.hp, player.maxhp);
    /* inputting */
    input = readline(shell_prompt);
    // eof
    if (!input) break;
    /* path completion when tab hit */
    rl_bind_key('\t', rl_complete);
    /* add the input to the history */
    add_history(input);

    if (!strcmp(input, "quit") || !strcmp(input, "exit")){
      printf("\nHave a nice day!\n");
      return;
    } else
      printf("=> %s\n", input);
    /* do stuff */
  }
}

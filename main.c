#include <stdio.h>

#define BLACK "\e[30m"
#define ANSI_COLOR_RED "\x1b[31;1m"
#define ANSI_COLOR_GREEN "\x1b[32;2m"
#define ANSI_COLOR_YELLOW "\x1b[33;3m"
#define ANSI_COLOR_BLUE "\e[34;4m"
#define ANSI_COLOR_MAGENTA "\x1b[35;5m"
#define ANSI_COLOR_CYAN "\x1b[36;6m"
#define ANSI_COLOR_WHITE "\x1b[37;7m"
#define ANSI_COLOR_RESET "\x1b[0m"

int n, flg = 0;  // n:no of players
void mainmenu(); // QUIZ GAME AND WELCOME STATEMENT
struct input {
  char name[43];
  int age;
} inpt[10];
int ipt();
struct gameplay {
  int ans[10];
  int scre; // score of individual participant will be stored.
} game[10];
int play(int ch);
int score(int flg); // score will be calculated in it.
void winner(struct gameplay game[n], struct input inpt[n]);
void scoreboard(struct gameplay game[n], struct input inpt[n]);

int main(void) {
  int no; // not yet used
  mainmenu();
  n = ipt();

  if (n == 0) // in ip function if(no<1) return 0;
  {
    printf(ANSI_COLOR_RED "\n\t\t\t\t\t# # WRONG INPUT # #\n\t\t\t\t\tBYE, SEE "
                          "YOU LATER!" ANSI_COLOR_RESET);
    goto end;
  }

  if (n == 1) {
    play(n);
  } else {
    for (int i = 0; i < n; i++) {
      printf("\n\nPlayer %d its your turn.\n\n", i + 1);
      play(i + 1);
    }
    scoreboard(game, inpt);
    winner(game, inpt);
  }

end:
  printf("\nBYE,Have a nice day and STAY VACCINATED.");
}

void mainmenu() {
  printf(ANSI_COLOR_YELLOW "\n\t\t\t\t# " ANSI_COLOR_RESET);

  printf("# ");
  printf(ANSI_COLOR_GREEN "#" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_WHITE " QUIZ GAME " ANSI_COLOR_RESET);

  printf(ANSI_COLOR_YELLOW "# " ANSI_COLOR_RESET);
  printf("#");
  printf(ANSI_COLOR_GREEN " # " ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN "\n--------------------------------------------------"
                          "--" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN
         "\n\t\t\t\tWELCOME ALL PARTICIPANTS\n" ANSI_COLOR_RESET);
}

int ipt() {
  printf("\nNumber of participants = ");
  scanf("%d", &n);
  if (n < 1)
    return 0;
  for (int i = 0; i < n; i++) {
    printf("\nEnter Name and Age of participant %d:\n", i + 1);
    scanf("%s %d", inpt[i].name, &inpt[i].age);
  }
  return n;
}

int score(int flg) {
  int sc = 1;
  if (flg == 0)
    return 0;
  for (int i = 1; i < flg; i++)
    sc = sc + (2 * i);
  return sc;
}

void winner(struct gameplay game[n], struct input inpt[n]) {
  int i = 0, winner = 0, t = 0;
  printf("\n_________________");
  printf("\n\t\t\tWINNER:");
  printf("\n_________________");
  do {
    if (t == game[i].scre)
      printf("\nWinner is %s with %d coins", inpt[winner].name,
             game[winner].scre);
    if (game[i].scre >= t) {
      t = game[i].scre;
      winner = i;
    }
    i++;
  } while (i < n);
  printf("\nWinner is %s with %d coins\n", inpt[winner].name,
         game[winner].scre);
}

void scoreboard(struct gameplay game[n], struct input inpt[n]) {
  printf("\n_________________");
  printf("\n\t\tSCOREBOARD:");
  printf("\n_________________");
  printf("\nName and Score:");
  for (int i = 0; i < n; i++)
    printf("\n%s\t\t\t%d", inpt[i].name, game[i].scre);
}

int play(int ch) {
  static int i = 0;
  int j = 0, t = 0;
  switch (ch) {
  case 1:
    printf(ANSI_COLOR_CYAN);
    printf("\nQ1 . National Animal of India "
           "is\n\t1:Tiger\t\t2:Lion\t\t3:Peacock \t\t4:Leapord");
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0) {
      t++;
      printf("\nQ1 . National Animal of India is\n\t1:Tiger\t\t2:Lion");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ2 . Who was the first Chief Minister of Maharashtra? "
           "\n\t1:Yashwantrao Chavan\t\t2:P. K. Sawant\t\t3:Vasantrao "
           "Naik\t\t4:Shankarrao Chavan");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ2 . Who was the first Chief Minister Maharashtra? "
             "of\n\t1:1:Yashwantrao Chavan\t\t4:Shankarrao Chavan");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

      return 0;
    }

    //##############################################
    printf("\nQ3 .India's first satellite Aryabhata was launched from?  "
           "\n\t1:Soviet Union\t\t2: America\t\t3:India\t\t4:Israel");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ3 .India's first satellite Aryabhata was launched from?  "
             "\n\t1:Soviet Union\t\t3:India");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ4 . Who among the following is known as 'Father of Indian "
           "Cinema'? \n\t1:.Dada Saheb Torne\t\t2:Dada Saheb "
           "Phalke\t\t3:Amitabh Bachchan\t\t4:Mani Sethna");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ4 .Who among the following is known as 'Father of Indian "
             "Cinema? \n\t2: Dada Saheb Phalke\t\t4:Mani Sethna");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ5 .Which indian state has the largest area? \n\t1:. "
           "Maharashtra\t\t2:Madhya Pradesh\t\t3:Uttar Pradesh\t\t4:Rajasthan");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ5Which indian state has the largest area? "
             "\n\t1:Maharashtra\t\t4:Rajasthan");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 4) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    break;
    //###########################################################//
    //###########################################################//
  case 2:
    i++;
    j = 0;
    flg = 0;
    printf("\nQ1 .What is the National Fruit of India? "
           "\n\t1:Pomegranate\t\t2:Apple\t3: Banana\t\t4:Mango");
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0) {
      t++;
      printf("\nQ1 .)What is the National Fruit of "
             "India?\n\t1:2.Apple\t\t4:Mango(correct)");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 4) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ2 . The minimum age of the voter in india? "
           "\n\t1:15\t\t2:18\t\t3:21\t\t4:25");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ2 .The minimum age of the voter in india? \n\t2:18\t\t3:21");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

      return 0;
    }

    //##############################################
    printf("\nQ3 .Who was the first chairman of Indian Space Research "
           "Organisation(ISRO)? \n\t1:K kasturirangan\t\t2:Vikram "
           "Sarabhai\t\t3:Satish Dhawan\t\t4:Homi J Bhabha");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ3 .)Who was the first chairman of Indian Space Research "
             "Organisation(ISRO)? \n\t2:Vikram Sarabhai\t\t4:Homi J Bhabha");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ4 .Filmfare awards started from the year?  "
           "\n\t1:1952\t\t2:1964\t\t3:1954\t\t4:1960");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf(
          "\nQ4 . Filmfare awards started from the year? \n\t2:1964\t\t3:1954");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 3) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ5 .What is the new name of Feroz Shah Kotla ground? \n\t1:Arun "
           "Jaitley Stadium\t\t2:Sheila Dikshit Stadium\t\t3:Gautam Gambhir "
           "Stadium\t\t4:Ajit Wadekar Stadium");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ5 .What is the new name of Feroz Shah Kotla ground? "
             "\n\t1:Arun Jaitley Stadium\t\t2: Sheila Dikshit Stadium");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    break;

  case 3:
    i++;
    j = 0;
    flg = 0;

    printf("\nQ1 .What is the National River of India? \n\t1:1.The Narmada "
           "Rive\t\t2:The Krishna River\t3:The Ganga River \t\t4:The "
           "Brahmaputra River");
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0) {
      t++;
      printf("\nQ1 .What is the National River of India?\n\t2:The Krishna "
             "River\t\t3:The Ganga River");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 3) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ2 .The minimum age to qualify for election to the Lok Sabha "
           "is?\n\t1:25\t\t2:21\t\t3:18\t\t4:35");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ2 .The minimum age to qualify for election to the Lok Sabha "
             "is? \n\t1:25\t\t2:21");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

      return 0;
    }

    //##############################################
    printf("\nQ3 .Who is known as the father of indian nuclear programme? "
           "\n\t1:APJ Abdul Kalam\t\t2: Raja Ramanna\t\t3:Homi J "
           "Bhabha\t\t4:.Vikram Sarabhai");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ3 .Who is known as the father of indian nuclear programme? "
             "\n\t1:APJ Abdual Kalam\t\t3:Homi J Bhabha");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 3) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ4 .Which of the following regional cinema referred to as "
           "Kollywood?  \n\t1: Punjabi Cinema\t\t2:Tamil Cinema\t\t3:Kannada "
           "Cinema\t\t4:Malayalam Cinema");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ4 .Which of the following regional cinema referred to as "
             "Kollywood?  \n\t2:Tamil Cinema\t\t3:Kannada Cinema");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ5 .Who has won the Rajiv Gandhi Khel Ratna Award 2019? "
           "\n\t1:.Sakshi Malik\t\t2:Mirabai Chanu\t\t3:.Bajrang "
           "Punia\t\t4:.Rohit sharma");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ5 .Who has won the Rajiv Gandhi Khel Ratna Award 2019? "
             "\n\t3:Bajrang Punia\t\t4:Rohit sharma ");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 3) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    break;

  case 4:
    i++;
    j = 0;
    flg = 0;

    printf("\nQ1 .What is the National Bird of India? "
           "\n\t1:Peacock\t\t2:Kingfisher\t3:Bald Eagle \t\t4:Parrot");
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0) {
      t++;
      printf(
          "\nQ1 .What is the National Bird of India?\n\t1:Peacock\t\t4:Parrot");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ2 .Who is the first Deputy Prime Minister of India?\n\t1:G L "
           "Nanda\t\t2:Devi Lal\t\t3: Charan Singh\t\t4:Vallabhbhai Patel");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ2 .Who is the first Deputy Prime Minister of India? "
             "\n\t3:Charan Singh  \t\t4:Vallabhbhai Patel");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 4) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

      return 0;
    }

    //##############################################
    printf("\nQ3 .India's first supercomputer is known as? \n\t1:. "
           "SAGA\t\t2:PARAM 8000 \t\t3: EKA \t\t4:PARAM YUVA");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ3 .India's first supercomputer is known as? \n\t2:PARAM "
             "8000\t\t4:PARAM YUVA");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ4 .First Indian movie submitted for Oscar?  \n\t1:The Guide "
           "\t\t2:Mother India\t\t3:Madhumati\t\t4: Amrapali");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ4 .First Indian movie submitted for Oscar?  \n\t1:The "
             "Guide\t\t2:Mother India");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf(
        "\nQ5 .who has won the first medal in Tokyo Olympics 2020 for India? "
        "\n\t1:.P V sindhu\t\t2: Mirabai chanu\t\t3:Atanu Das\t\t4:Mary kom");

    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ5 .Who has won the Rajiv Gandhi Khel Ratna Award 2019? "
             "\n\t1:P V Sindhu\t\t2:Mirabai Chanu");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    break;

  case 5:
    i++;
    j = 0;
    flg = 0;

    printf("\nQ1 .What is the National Tree of India? \n\t1: Tamarind "
           "Tree\t\t2: Banyan Tree\t3:Neem Tree \t\t4:Peepal Tree");
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0) {
      t++;
      printf("\nQ1 .What is the National Tree of India??\n\t2:Banyan "
             "Tree\t\t3:Neem Tree");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ2 .In which state, the President's Rule was first imposed in "
           "India?\n\t1:Andhra Pradesh\t\t2:Bihar\t\t3: Assam \t\t4:Arunachal "
           "Pradesh");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ2 .In which state, the President's Rule was first imposed in "
             "India? \n\t1:Andhra Pradesh   \t\t2:Bihar");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 1) {
      printf("\n\tYou are Right!!\n");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

      return 0;
    }

    //##############################################
    printf("\nQ3 .ISRO was formed in? \n\t1:1963 \t\t2:1969 \t\t3: 1972 "
           "\t\t4:1985");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ3 .ISRO was formed in? \n\t1:1963\t\t2:1969");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));

    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ4 .Who among the following made first Film Theatre of India?  "
           "\n\t1:Lumiere Brothers \t\t2:Mani Sethna \t\t3:Dada Saheb "
           "Phalke\t\t4:Dhirendra Nath Ganguly ");
    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ4 .Who among the following made first Film Theatre of India ? "
             " \n\t2:Mani Sethna t\t3:Dada Saheb Phalke");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    //##############################################
    printf("\nQ5 .Which one of the following ports is the oldest port in "
           "India? \n\t1:Mumbai Port\t\t2:Chennai Port  \t\t3:Kolkata "
           "Port\t\t4:.Vishakhapatnam Port");

    j++;
    printf("\n\tAns = ");
    scanf("%d", &game[i].ans[j]);

    if (game[i].ans[j] == 0 && t == 0) {
      t = 1;
      printf("\nQ5 .Which one of the following ports is the oldest port in "
             "India?  \n\t1:Mumbai Port\t\t2:Chennai Port");
      printf("\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 0) {
      printf("\n\tYou can use 50-50 only once in a game");
      printf("\n\n\tAns = ");
      scanf("%d", &game[i].ans[j]);
    }

    if (game[i].ans[j] == 2) {
      printf("\n\tYou are Right!!");
      flg++; // flg gives no.of questions answered correctly.
      game[i].scre = score(flg);
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    } else {
      printf("\n\n\t\tWrong Answer");
      printf("\n\n\tTotal no. of coins earned = %d\n", score(flg));
      return 0;
    }
    break;
  }

  return 0;
}

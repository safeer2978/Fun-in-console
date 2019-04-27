#include <stdio.h>
#include <stdlib.h>
#include<conio.h>


char matrix[3][3];  /* the tic tac toe matrix */

char check_(void);
void init_matrix(void);
int get_player_move(void);
void get_player_2_move(void);
void disp_matrix(void);
void print_title(void);
int xando(void)
{
  print_title();
  disp_matrix();
  char done;
  int score=1;

  done =  ' ';
  init_matrix();
int flag=0;
  do {
  flag =  get_player_move();
    done = check_(); 
    if(done!= ' ') break;
	system("cls");
    print_title();
    disp_matrix(); 
	get_player_2_move();
    system("cls");
    print_title();
    disp_matrix();
    done = check_(); 
  } while(done== ' ' && flag>=0);
system("cls");
    print_title();
    disp_matrix(); 
  if(done=='X') {
  printf("\t\t\t\t\t\t\tPlayer 1 won!\n");
  score+=10;
  }
  else if(flag>0) printf("\t\t\t\t\t\t\tPlayer 2 Won!\n");
  else printf("goodbye!");
 // disp_matrix(); /* show final positions */
 	init_matrix();
	getch();
  return score;
}


void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrix[i][j] =  ' ';
}

int get_player_move(void)
{
  int x, y;

  printf("\t\t\t\t\t\tPlayer 1:Enter X,Y coordinates for your move: ");
   char key=getch();
  if(key==27)return -1;

  scanf("%d%*c%d", &y, &x);

  x--; y--;

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    get_player_move();
  }
  else matrix[x][y] = 'X';
}

void get_player_2_move(void)
{
  int x, y;

  printf("\t\t\t\t\t\tPlayer 2 :Enter X,Y coordinates for your move: ");
   char key=getch();
  if(key==27)return -1;

  scanf("%d%*c%d", &y, &x);

  x--; y--;

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    get_player_move();
  }
  else matrix[x][y] = 'O';
}

void print_title()
{
	int t,f;
	printf(
	"\t\t\t\t\t\t___________.__         ___________               ___________            \n\
\t\t\t\t\t\t\\__    ___/|__| ____   \\__    ___/____    ____   \\__    ___/___   ____  \n\
\t\t\t\t\t\t   |   |  |/ ___\\    |    |  \\__  \\ _/ ___\\    |    | /  _ \\_/ __ \\  \n\
\t\t\t\t\t\t  |    |   |  \\  \\___    |    |   / __ \\  \\___    |    |(  <_> )  ___/ \n\
\t\t\t\t\t\t |____|   |__|\\___  >   |____|  (____  /\\___  >   |____| \____/ \\___  >\n\
\t\t\t\t\t\t                  \\/                 \/     \\/                      \\/  \n");

printf("\t\t\t\t");
for(t=0;t<100;t++)
printf("*");

printf("\n\t\t\t\t\t\tHow to play:\n\t\t\t\t\t\t1. Select X,Y coordinates of where you want to place your chance\n\t\t\t\t\t\t2.Player 1 is X, Player 2 is O\n");

printf("\t\t\t\t");
for(f=0;f<100;f++)
printf("*");

printf("\n");
}

/* Display the matrix on the screen. */
void disp_matrix(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf("\t\t\t\t\t\t\t\t\t %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n\t\t\t\t\t\t\t\t\t---|---|---\n");
  }
  printf("\n");
printf("\t\t\t\t");
for(t=0;t<100;t++)
printf("*");
printf("\n");
}

/* See if there is a winner. */
char check_(void)
{
  int i;

  for(i=0; i<3; i++) 
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++)
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];


  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
}

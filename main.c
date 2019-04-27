#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//using getch so need to use ASCII values..
#define XANDO 49				//1
#define APLHABET 50				//2
#define QUIZ 51
#define TOI 52					//4
#define CROSSWORD 53			//5
#define LEADERBOARD 54
#define EXIT 55

#define YES 49					//1
#define NO 50					//2

extern int loginPage();
extern int crossword();
extern int TowerOfHanoi();
extern int aplhabet();
extern int xando();
extern int printLeaderBoard();
extern void updatePlayerScore(int ,int);
extern int quiz(void);

void loadMainMenu(void);

int  SetFontSize(HANDLE windowHandle, COORD size){							//
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
 
    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
 
    font.dwFontSize = size;
 
    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
 
    return 1;
    }

int main(int argc, char *argv[]) 
{
	 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;
	size.X =3;
        size.Y =28;
        
    SetFontSize(h, size);
	int index=loginPage();
	int a;
	startA:
	system("cls");	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	int choice;
	loadMainMenu();
	//scanf("%d",&choice);
	choice=getch();
	system("cls");	
	switch(choice){
		case XANDO:
			a=xando();
			updatePlayerScore(index,a);
			break;
		case TOI:
			a=TowerOfHanoi();
			updatePlayerScore(index,a);
			break;
		case APLHABET:
			a=alphabet();
			updatePlayerScore(index,a);
			break;
		case CROSSWORD:
			a=crossword();
			updatePlayerScore(index,a*10);
			break;
		case QUIZ:
			a=quiz();
			updatePlayerScore(index,a*10);
			break;
		case LEADERBOARD:
			index=leadB(index);
		//	updatePlayerScore(index,1);
			break;
		case EXIT:
		case 27:
			goto exit;
	}goto startA;
	exit:
	system("cls");
	printf("\t\t\tDo you want to exit?\n\t\t\t1.Yes\n\t\t\t2.No");
	
//	scanf("%d",&choice);
	choice=getch();
	if(choice==NO) goto startA;
	else exit(0);
	return 0;
}


void loadMainMenu(){


printf("\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf(
"	\t\t\t\t /$$$$$$$$                        /$$$$$$ /$$   /$$        /$$$$$$  \n\
	\t\t\t\t| $$_____/                       |_  $$_/| $$$ | $$       /$$__  $$ \n\
	\t\t\t\t| $$    /$$   /$$ /$$$$$$$         | $$  | $$$$| $$      | $$  \\__/\n\
	\t\t\t\t| $$$$$| $$  | $$| $$__  $$        | $$  | $$ $$ $$      | $$       \n\
	\t\t\t\t| $$__/| $$  | $$| $$  \\ $$        | $$  | $$  $$$$      | $$      \n\
	\t\t\t\t| $$   | $$  | $$| $$  | $$        | $$  | $$\\  $$$      | $$    $$\n\
	\t\t\t\t| $$   |  $$$$$$/| $$  | $$       /$$$$$$| $$ \\  $$      |  $$$$$$/\n\
	\t\t\t\t|__/    \______/ |__/  |__/       |______/|__/  \\__/       \\______/");

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

printf("\n\t\t\t\t\t*******************************************************************\n\
			\t\t\t\t*	1.Tic Tac Toe		*\n\
			\t\t\t\t*	2.Alphabet Game		*\n\
			\t\t\t\t*	3.Quiz			*\n\
			\t\t\t\t*	4.Tower of Henoi	*\n\
			\t\t\t\t*	5.CrossWord		*\n\
			\t\t\t\t*	6.LeaderBoard		*\n\
			\t\t\t\t*	7.exit			*");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

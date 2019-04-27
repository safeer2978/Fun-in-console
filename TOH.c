#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <string.h>
#include <Wincon.h>
#include<windows.h>
#include<conio.h>

/*
 *
 *TOWER OF HENOI
 **/

#define OGX 7
#define OGY 12
#define COLUMNS 3
int ROWS=3;
int selected=3;
int TOH_score=1;
int moves=0;

void printTOItitle(){														//prints the title
	printf(
"\t _________                                               ___   ____  ____                          _   \n\
\t|  _   _  |                                            .' ..] |_   ||   _|                        (_)  \n\
\t|_/ | | \\_|.--.   _   _   __  .---.  _ .--.    .--.   _| |_     | |__| |   ,--.   _ .--.   .--.   __   \n\
\t    | |  / .'`\\ \\[ \\ [ \\ [  ]/ /__\\\\[ `/'`\\] / .'`\\ \\'-| |-'    |  __  |  `'_\\ : [ `.-. |/ .'`\\ \\[  |  \n\
\t   _| |_ | \\__. | \\ \\/\\ \\/ / | \\__., | |     | \\__. |  | |     _| |  | |_ // | |, | | | || \\__. | | |  \n\
\t  |_____| '.__.'   \\__/\\__/   '.__.'[___]     '.__.'  [___]   |____||____|\\'-;__/[___||__]'.__.' [___] \n");
}
void initializeGrid(int arr[ROWS][COLUMNS]){								// initializes the grid
int i, j; 
    for (i = 0; i < ROWS; i++) {
	   for (j = 0; j < COLUMNS; j++) 
        if(j==0) arr[i][0]=i+1;
        else arr[i][j]=0;
}
}
void printGrid(int arr[ROWS][COLUMNS]){										// prints the main grid with formatting
	 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;
	printf("\n\n");
	printf("\t");
	for(int i=0;i<100;i++)printf("*");
	printf("\n\n");
	int i, j; 
	printf("\t\t\t\tA\t\t\tB\t\t\tC\n");
    for (i = 0; i < ROWS; i++) {
    	printf("\t");
    //	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (100+(i*10)));
	      for (j = 0; j < COLUMNS; j++) {
	      	if(selected<3&& j==selected){
			   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);}
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (10+(j*5)));  
		size.X =3;
        size.Y =30;
        
      //  SetFontSize(h, size);
        printf("\t\t\t%d",arr[i][j]);
    }printf("\n");
    
	}selected=3;	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
}
bool isBelow(int arr[ROWS][COLUMNS],int i, int j){							// checks if a disc is below a smaller disc
return (arr[i-1][j]>0 && i!=1)?true:false;
}
bool discExists(int arr[ROWS][COLUMNS],int i,int j){						//checks if disc exists the column
	return (arr[i][j]>0)?true:false;
}
bool move(int arr[ROWS][COLUMNS], int from, int to){						// MOVES can only be from column and to column
	if(from==to)return true;
	int size=getSize(arr,from);
	
	int i=ROWS-1;
	//printf("\ninvoked");
	while(i!=-1){
		if(arr[i][to]<size && arr[i][to]!=0) // any lower size disc exits, is below another disc
		{
			printf("\nmove not possible!\n");
			//goto moveEnd;
			return false;
		}
		
		if(discExists(arr,i,to)) {
		i--;continue;}
		arr[i][to]=size;
		break;
	}
	
	//to remove
	i=0;
	while(i<ROWS){
		if(arr[i][from]==size)arr[i][from]=0;
		i++;
	}
	moves++;
	return true;
}
bool isEmpty(int arr[ROWS][COLUMNS],int column){							//checks and returns boolean if the column is empty
	int i=0;
	while(arr[i][column]==0){
	
		if(i==ROWS-1)return true;
		i++;}
 	return false;
}
int  getSize(int arr[ROWS][COLUMNS],int column){								// returns the number on top of the column (size of disc)
	int i=0;
	while(arr[i][column]==0){
		i++;}
		return arr[i][column];
}
int  map(char column){														// Maps the User's Choices(A,B & C) to Values Used in the Grid(0,1 & 2)  of Arrrary to identify Columns
	switch(column){
		case 'A':
		case 'a':
			return 0;
		case 'B':
		case 'b':
			return 1;
		case 'C':
		case 'c':
			return 2;
		default:
			return 0;
	}
}

void printInstructions(){
	printf("\n\t");
	for(int i=0;i<100;i++)printf("*");
	printf("\n\n");
	printf("\t");
	printf(
	"The objective of the puzzle is to move the entire stack form Column A to Column C,\n\tobeying the following simple rules:\n\
\n\t\t1.Only one Number can be moved at a time.\
\n\t\t2.Each move consists of taking the upper Number from one of the stacks and placing it\n\t\ton top of another stack or on an empty Column.\
\n\t\t3.No larger Number may be placed on top of a smaller disk.");
}

int* printOptions(int arr[ROWS][COLUMNS]){									// Prints options on Screens as well as accepts the values. Also check for incorrent User Inputs
	char columns[2];
	start:
		
		printf("\n\n\t");
		for(int i=0;i<100;i++)printf("*");
		printf("\n\t\t\t\t\t");
		printf("Select a column to Select Number from....\n\t\t\t\t\tPress Key of the COlUMN A, B or C");
		printf("\n\t\t\t\t\t");
		printf("or press ESC to go back to Main Menu\n");
		//scanf(" %c",&columns[0]);
		//fflush(stdin);
		columns[0]=getch();
		if(columns[0]==27)return 27;
		int first_column=map(columns[0]);
		selected=first_column;
		if(isEmpty(arr,first_column))// || first_column>=COLUMNS-1)
		{	printf("Column empty!");
			goto start;
}
			system("cls");
				printTOItitle();
		printInstructions();
		printGrid(arr);
			printf("\n\n\t");
		for(int i=0;i<100;i++)printf("*");
	
		printf("\n\t\t\t\t\tSelect a column to Put the Number To....\n\t\t\t\t\t Press Key of the COlUMN A, B or C\n");
		scanf(" %c",&columns[1]);
		int second_column=map(columns[1]);
		
		
		int int_cols[2];
		int_cols[0]=first_column;
		int_cols[1]=second_column;
	
return int_cols;
}

bool checkColumn(int arr[ROWS][COLUMNS]){
	for(int i=1;i<=ROWS;i++)
		if(arr[i-1][2]!=i)
			return false;
	return true;
}

int TowerOfHanoi() {														//Uses all above functions and runs the sequence of main program
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	printTOItitle();
printf("enter number of Discs you want to play with...select from 3 to 8");
scanf("%d",&ROWS);	
	int arr[ROWS][COLUMNS];
	initializeGrid(arr);
//	system("cls");
	//printGrid(arr);	

	for(;;){
			system("cls");
		printTOItitle();
		printInstructions();
		printGrid(arr);
		int *columns=printOptions(arr);	
		if(columns==27)return TOH_score;
		move(arr,columns[0],columns[1]);
		if(checkColumn(arr)){
			system("cls");
			printTOItitle();
		printInstructions();
		printGrid(arr);
			TOH_score=ROWS*100;
			TOH_score-=moves*10;
			printf("\t\t\t\tNICE! you solved it in %d moves\n\t\t\t\t You scored %d",moves,TOH_score);
			moves=0;
			getch();
			break;
		}
		
		//system("cls");		
	}	
	return TOH_score;
}			





#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

char CHARACTER=65;
#define LIVES 5
#define X_SIZE 45


void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void printTitle(){
int t;
	
		printf(
		"\t\t\t\t ____  _     ____  _     ____  ____  _____  ____  _ ___  _ \n\
\t\t\t\t/  _ \\/ \\   /  __\\/ \\ /|/  _ \\/  _ \\/__ __\\/  __\\/ \\  \\// \n\
\t\t\t\t| / \\|| |   |  \\/|| |_||| / \\|| | //  / \  |  \/|| | \  / \n\
\t\t\t\t| |-||| |_/\\|  __/| | ||| |-||| |_\\\\  | |  |    /| | /  \\ \n\
\t\t\t\t\\_/ \\|\\____/\\_/   \\_/ \\|\\_/ \\|\\____/  \\_/  \\_/\\_\\\\_//__/\\");
printf("\n");

printf("\t");
for(t=0;t<=100;t++)
printf("*");

printf("\n");
		
	}
void space(char *a1) {
  	int i;
  	for(i=0;i<=X_SIZE;i++)
  	{if(a1[i]!='.')
  	 a1[i]=' ';
  	 else continue;
    } 		
  }
void printArray(char *arr){
		int i;
		/*
		printf("\t*******************************");
		
		printf("\n");
		printf("\t");*/
		printf("\n\n\t");
		for(int i=0;i<100;i++)printf("*");
	printf("\n\t\t");
	for(i=0;i<X_SIZE;i++) printf("%c ",arr[i]);
	printf("\n\n\t");
		for(int i=0;i<100;i++)printf("*");
					
	} // prints arrray	
void rules(){ 
	//printf("\033:[1;35m");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	printf("\tRules:");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);	
//	printf(\033:[0;36m);
	printf("		1.The random alphabet will move from left to right\n\
			2.The pointer will be placed in any random posiotion\n\
			3.If you hit the respective key of the alphabet when it is on the pointer you score points\n\n\n ");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10000);
}
void function() { //redundant
  	char ch;
 	char a[15];
    space(a);
    rules();
	int i,j,f,d,b[15];
	f=0;	
	
	

	
	
	for(j=0;j<5;j++)
	{	
			 for( i=1;i<X_SIZE;i++){
    	//random position
		/*for(d=1;d<=15;d++)
		{
			n=rand()
			printf("%d"b[n]);
		}
		*/
		a[i]='C';
		//printf("*\n");
		printArray(a);
		Sleep(100);
		space(a);
		rules();
		while(kbhit()){
			char c = fgetc(stdin);
			if(c==0x0A)
			{
			printf("yo");f=1;
			printf("\n#%d",f);break;}
		}
	}
	if(f==1)
	break;
	
	for( i=15;i>0;i--)
	{
	
		a[i]='A';
		//printf("*\n");
		printArray(a);
		Sleep(100);
		space(a);
		rules();	
	
}
	
}
}
int random(int low,int high){
	int num = (rand() % 
           (high - low + 1)) + low;

		   return num; 
}

void printLives(int life){
	printf("\n\t\t\t\t");
	printf("Health:");
	for(int i=0;i<life;i++)printf("%c",232);

}



int alphabet(){
	printTitle();
	int score=1;
	int life=LIVES;
	int pos=X_SIZE-1;
	system("cls");
	printTitle();
	//curs_set(0);
	hidecursor();
	char board[X_SIZE];
	
	space(board);
	board[pos]='.';
//	rules();
	int flag=0;
	int iflag=0;
	for(;;)
	{	int i=0;
		int sleepTime=random(10,90);
		 while(flag==0){
		 //	Sleep(10);
		 		system("cls");
		 	printTitle();
			 		rules();
		 	space(board);
		 	if(board[i]!='.')
		 	board[i]=CHARACTER;
		 	printArray(board);
		 	printLives(life);
		 	Sleep(sleepTime);
		 //	printf("\n\n\%d",random(10,25,1));
		 
		 	while(kbhit()){
		 			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),227);
		 			system("cls");
		 	     printTitle();
			 		rules();
		 	space(board);
		 	printArray(board);
		 			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		 			
			char c = getch();
			if(c==CHARACTER && board[i]=='.') // ASCII of ENTER
			{
		//	printf("yo");
			score+=20;
			flag=1;
			break;
			}
			else if(c==27)return score;
			else {
			life--;//printf("!!!!!!!!!!!!!%d",life);
			if(life==0)flag=1;	}	
				}
		 	if(flag==1)break;
		 
		 	if(i<=X_SIZE && iflag==0)i++;
		 	else {
			i--;iflag=1;}
		 	if(iflag==1 && i==0)iflag=0;
		 	
		 
		 }
		 if(life==0){
		 	break;
		 }
		 
		 board[pos]=' ';
		 	pos= random(4,X_SIZE-2);
		 	CHARACTER++;
		 	board[pos]='.';
		flag=0;	 	
}
		system("cls");
		printf("\n\n\n\t\t\t\tYou Scored:%d",score);
	getch();
	return score;
}
/*void printdemo(){
	printf("				Rules:\
			1.something!\
			2.another thing!\  ");
}*/


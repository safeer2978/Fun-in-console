#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define ROWS 12
#define COLUMNS 15
#define QUESTIONS 9
int score=1;
extern void main();
int setAcross(char* word,int row, int from, char board[ROWS][COLUMNS]){									//
//	row=row-1;
//	from--;
	int len=strlen(word);
	for(int i=from;i<(from+len);i++){
		if(board[row][i]==word[i-from])continue;
		board[row][i]=word[i-from];
	}
	return from+len;
}
int setDown(char* word,int column, int from, char board[ROWS][COLUMNS]){								//
	//column--;
	//from--;
	int len=strlen(word);
	for(int i=from;i<(from+len);i++){
		if(board[column][i]==word[i-from])continue;
		board[i][column]=word[i-from];
	}
	return from+len;
}
void printtitle(){																						//
	printf("\t\t _______  _______  _______  _______  _______           _______  _______  ______  \n\
	\t(  ____ \\(  ____ )(  ___  )(  ____ \\(  ____ \\|\\     /|(  ___  )(  ____ )(  __  \ \n\
	\t| (    \\/| (    )|| (   ) || (    \\/| (    \\/| )   ( || (   ) || (    )|| (  \\  )\n\
	\t| |      | (____)|| |   | || (_____ | (_____ | | _ | || |   | || (____)|| |   ) |\n\
	\t| |      |     __)| |   | |(_____  )(_____  )| |( )| || |   | ||     __)| |   | |\n\
	\t| |      | (\\ (   | |   | |      ) |      ) || || || || |   | || (\\ (   | |   ) |\n\
	\t| (____/\\| ) \\ \\__| (___) |/\\____) |/\\____) || () () || (___) || ) \\ \\__| (__/  )\n\
	\t(_______/|/   \\__/(_______)\\_______)\\_______)(_______)(_______)|/   \\__/(______/ \n" );
	printf("\n\n\t");
		for(int i=0;i<100;i++)printf("*");
}
void printBoard(char arr[ROWS][COLUMNS]){																//
	printf("\n\n");														//
	for(int i=0;i<ROWS;i++)
	{
		printf("\t\t\t\t\t");
		for(int j=0;j<COLUMNS;j++)
		{
			if(arr[i][j]!=' '){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);			
			printf("%c_",arr[i][j]);
		}else printf("%c ",arr[i][j]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);			
		}printf("\n");
	}printf("\n");
	printf("\n\t");
		for(int i=0;i<100;i++)printf("*");
		printf("\n");
}
int checkWord(char board[ROWS][COLUMNS], char *answer,int row, int column,int orientation){//REDUNDENT //
	int len=strlen(answer);
	char input[len];
	if(orientation==0){
		for(int i=0;i<len;i++)
		input[i]=board[row][column+i];
		input[len]='\0';
	//	printf("%s",input);
	}
	else
	{
		for(int i =0;i<ROWS;i++)
		{
			input[i]=board[row+i][column];
		}
	}
	return strcmp(answer,input);
}
char* getAnswer(int index){																				//
	 char *answers[]={
			"RECYCLE",
			"DEFORESTATION",
	    	"PRESERVE",
			"LANDFILL",
			"FLOOD",
			"PROTECT",
			"POLLUTION",
			"REDUCE",
			"REUSE"};
	return answers[index];
}
int check(int question, char* userAnswer){																//
	return strcmp(getAnswer(question),userAnswer);
}
char* getQuestions(int index){																			//
	 char* questions[]={//= malloc(QUESTIONS * sizeof(char)),
	"questions:",
	"To treat things that have already been used so they can be used again.",
	"The act of cutting or burning trees in a area.",
	"To keep safe from injury, harm, or destruction.",
	"An area of land where large amounts of waste material are buried under the earth.",
	"A large number of water covering an area that is usually dry.",
	"To watch and help an animal or the environment.",
	"Something making land, water or sky dirty.",
	"To make less rubbish.",
	"To use something again."};
	return questions[index];
}
void printQuestions(){																					//
	for(int i=1;i<=QUESTIONS;i++)printf("\t%d ) %s\n",i,getQuestions(i));
}
int isComplete(char board[ROWS][COLUMNS],char Aboard[ROWS][COLUMNS]){									//
	for(int i=0;i<ROWS;i++){
	for(int j=0;j<COLUMNS;j++)
		if(board[i][j]!=Aboard[i][j])return 0;
			
		}
		
return 1;
}
void setQuestionPoints(char board[ROWS][COLUMNS]){														//
	board[0][1]='1';
	board[1][0]='2';
	board[2][14]='3';
	board[5][1]='4';
	board[5][5]='5';
	board[5][11]='6';
	board[7][3]='7';
	board[9][2]='8';
	board[9][10]='9';
}

int crossword(){
	score=1;																						//
	char board[ROWS][COLUMNS];
	char Aboard[ROWS][COLUMNS];
	for(int i=0;i<ROWS;i++){
	for(int j=0;j<COLUMNS;j++)
		{
		setAcross(" ",i,j,board);
		setDown(" ",i,j,board);
		setAcross(" ",i,j,Aboard);
		setDown(" ",i,j,Aboard);
		char* star[8];

 		setDown(getAnswer(0),2-1,1-1,board);
		setAcross(getAnswer(1),2-1,1-1,board);
		setDown(getAnswer(2),15-1,3-1,board);
		setAcross(getAnswer(3),6-1,2-1,board);
		setDown(getAnswer(4),6-1,6-1,board);
		setDown(getAnswer(5),12-1,6-1,board);
		setAcross(getAnswer(6),8-1,5-1,board);
		setAcross(getAnswer(7),10-1,4-1,board);
		setAcross(getAnswer(8),10-1,11-1,board);
			
		for(int i=0;i<ROWS;i++)for(int j=0;j<COLUMNS;j++)if(board[i][j]!=' ')Aboard[i][j]='.';
		}
		}
	
	int question=0;
	
	setQuestionPoints(Aboard);
	for(int i=0;i<9;i++)
	{	
	printtitle();
	printBoard(Aboard);
	printQuestions();

	printf("Select Question number....OR press 99 to go back");
				while(kbhit())
			{
			char c = getch();
			if(c==27) return score;
}
	scanf("%d",&question);

	if(question==99)return score;
	char*userAnswer= malloc(15*sizeof(char));
	printf("enter your answer....");
	fflush(stdin);
	gets(userAnswer);
	userAnswer=strupr(userAnswer);
	if(check(question-1,userAnswer)==0){
		score++;
		switch(question){
			case 1:setDown(getAnswer(0),2-1,1-1,Aboard);break;
			case 2:setAcross(getAnswer(1),2-1,1-1,Aboard);break;
			case 3:setDown(getAnswer(2),15-1,3-1,Aboard);break;
			case 4:setAcross(getAnswer(3),6-1,2-1,Aboard);break;
			case 5:setDown(getAnswer(4),6-1,6-1,Aboard);break;
			case 6:setDown(getAnswer(5),12-1,6-1,Aboard);break;
			case 7:setAcross(getAnswer(6),8-1,5-1,Aboard);break;
			case 8:setAcross(getAnswer(7),10-1,4-1,Aboard);break;
			case 9:setAcross(getAnswer(8),10-1,11-1,Aboard);break;
			case 99:return 1;
		
			}
	}
	else printf("incorrect answer!");
	
	int flag=isComplete(board,Aboard);
	if(flag==1)goto end;
	system("cls");
	//printBoard(Aboard);
	}
	end:	
		system("cls");
		printf("YOU WON!!");
		
return score;
}



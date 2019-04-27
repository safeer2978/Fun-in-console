#include<stdio.h>
#include<windows.h>


#define CURRENT 49				//1
#define SCIENCE 50				//2
#define SPORTS 51				//3

int q_score=1;
void  printq_scores(int i){
	printf("\t\t\t");
	printf("Score:%d\t\t\tQuestion no:%d\n\t\t\t",q_score,i);
	for(i=0;i<100;i++)
       printf("*");
       
       printf("\n");
}

char* getQuestion(int index){																			//
	const char* questions[]={
		
	"questions:",
	".which indian personality has been chosen for russia highest civilian\n\t\t\t\t award order of st andrew the apostle ?",
	". jallianwala bagh massacre was held in which of the following year?",
	". who has taken oath as new chief justice of bobay high court?",
	". which country has decided to launch worlds first 5 G network ?",
	". who is topper of UPSC 2018?",
	". In which year IT act came into force in india?",
	". which one is indias operational remote sensing satellite?",
	". the first nuclear test conducted in india under the code name smiling\n\t\t\t\t buddha in the year?",
	". which one is a indias permanent research station in antartica?",
	". who is known as father of electricity",
	". which tennis player have most grand slam titles?",
	". birdie and eagle are two terms released to which sports?",
	".who among the following is the first rajiv gandhi khel ratna?",
	". who mong the following is known as flying sikh?",
	". which crickter is known as master blaster?"
	
	};
	return questions[index];
}
char* getOptions(int index){																			
	const char* options[]={
	"options:",
	"1. Mary kom 2. Naredera modi 3.Ratan tata 4. MS dhoni",
	"1. 1916 2. 1917 3.1918 4.1919",
	"1. Pawan Kalyan 2. Rishi bagree 3. Pradeep nandrajog 4. Vidyasagar rao",
	"1. South Korea  2. Japan 3. USA 4. China",
	"1.Tina dabi 2. Anudeep durashetty 3. kanishk kataria 4. Ankit jain",
	"1. 2007 2.2003 3.2000 4.1997",
	"1. IRS-1A 2. INSAT- 1A 3. GSAT-1 4 PSLV-D3.",
	"1. 1975 2. 1978 3. 1974 4. 1999",
	"1. Ganga 2. Agni 3. Maitri 4. Noneof the above",
	"1. Alexander Graham Bell 2. Michael Faraday 3. Benjamin Franklin 4. None of the above",
	"1.Roger Federer 2. Rafael Nadal 3.Novok djokovic 4. Pete Sampras",
	"1. Golf 2. Badminton 3.Chess 4.Tennis",
	"1. Kamla maheshwari 2. Geet sethi 3. Viswanathan 4. Major dhyan chand",
	"1.Harbhajan singh 2.Milkha singh 3. Yuvraj singh 4. Roshan singh sodhi",
	"1. Sunil gavaskar  2. Sachin tendulkar  3. MSdhoni 4. Kapil Dev"
	};
	return options[index];
}
int getAnswers(int index){																			
	const int options[]={
	0,2,4,3,1,3,3,1,3,3,3,1,1,3,2,2
	//write correct answers without quotes
	
	};
	return options[index];
}

void print_title_()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
   int i;
   printf("\n\n\n\n\n");
	printf(
	"\t\t\t\t\t\t\t________   ____ ___._____________ \n\
\t\t\t\t\t\t\t\\_____  \\ |    |   \\   \\____    /  \n\
\t\t\t\t\t\t\t/  / \\  \\|    |   /   | /     /     \n\
\t\t\t\t\t\t\t/   \\_/.  \    |  /|   |/     /_      \n\
\t\t\t\t\t\t\t\_____\\ \\_/______/ |___/_______ \\   \n\
\t\t\t\t\t\t\t\\__>                    \\/\n");
     printf("\t\t\t");  for(i=0;i<100;i++)
       printf("*");
       
       printf("\n");
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
int quiz()
{

	print_title_();
	int i,p=0,a,b,c,d;
	int answer,count=0,choice;
	int catagorie;
	starta:
	system("cls");
	print_title_();	
	printf("\t\t\t\t\t\tchoose the category to be used\n\t\t\t\t1.current affairs\n\t\t\t\t2.science and technology\n\t\t\t\t3.sports\n");
	d=getch();
	switch(d){
		case CURRENT:
			catagorie=1;
			break;
		case SCIENCE:
			catagorie=6;
			break;
		case SPORTS:
			catagorie=11;
			break;
		case 27:
			return q_score;
	}
	
	/*scanf("%d",&d);
	if(d==1)
	catagorie=1;
	else if(d==2)
	catagorie=6;
	else if(d==3)
	catagorie=11;
	*/
	system("cls");
	print_title_();
	printq_scores(1);
	
//	printf("Q1.scsdcvsd \n 1)vvw\n 2)fbdfbd\n 3)vsvvs\n 4)dfdfs\n");
	
	for(i=catagorie;(i<catagorie+5);i++){
	
	printf("\n\t\t\t\tQ%d %-20s? \n \t\t\t\t\t%s",i-catagorie+1,getQuestion(i),getOptions(i));
	scanf("\n\t\t\t\t%d",&answer);
	system("cls");
	print_title_();
	printq_scores(i-catagorie+2);
	if(answer==getAnswers(i)) {count++;q_score++;
	}/*printf("\ncorrect answer");*/
	else continue;
/*printf("\nwrong answer");*/
}
q_score+=count;
printf("\t\t\tyour score is %d out of 5\n\t\t\tDo you want to contiue\n\t\t\t1 for yes\n\t\t\t2 for no",count);
scanf("%d",&choice);
if(choice==1)
goto starta;
else
return q_score;
}

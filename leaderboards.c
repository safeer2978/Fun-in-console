#include <stdio.h>
#include <string.h>


FILE *fp;
const int no_of_entries=10;
struct player{
	char name[10];
	int score;
}p[20],pl;
void readPlayer(){
	 FILE *infile; 
    struct player input; 
    // Open person.dat for reading 
    infile = fopen ("person.txt", "r"); 
    if (infile == NULL) 
    { 
      //  fprintf(stderr, "\nError opening file\n"); 
      //  exit (); 
    } 
      int i=0;
    // read file contents till end of file 
    while(fread(&input, sizeof(struct player), 1, infile)) {
        //printf (" name = %s %d\n", input.name, input.score);
       // p[i]== malloc(sizeof(struct chess));
		memcpy(p[i].name,input.name,sizeof(p[i].name));
		p[i].score=input.score;
		i++;
		}
		
  
    // close file 
    fclose (infile);      
}



int addPlayer(struct player input) { 
  FILE *outfile; 
    outfile = fopen ("person.txt", "a"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        //exit (1); 
    } 
  
    //struct player input1 = {"rohan", 8}; 
    //struct player inputno_of_entries = {"mahendra", 51}; 
        
    // write struct to file 
    /* TODO (#1#): change loop limit */
   // for (int i=0;i<no_of_entries;i++)fwrite (&input[i], sizeof(struct player), 1, outfile); 
    //fwrite (&inputno_of_entries, sizeof(struct player), 1, outfile); 
    fwrite (&input, sizeof(struct player), 1, outfile);
      
    if(fwrite != 0)  
        printf("added\n");//"contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
  
    // close file 
    fclose (outfile); 
  
    return 0;   
} 

int printLeaderBoard(){
		printf("\n\n\t\t");
	printf("  _                _           _                         _\ \n\
\t\t | | ___  __ _  __| | ___ _ __| |__   ___   __ _ _ __ __| |\n\
\t\t | |/ _ \\/ _` |/ _` |/ _ \\ '__| '_ \\ / _ \\ / _` | '__/ _` |\n\
\t\t | |  __/ (_| | (_| |  __/ |  | |_) | (_) | (_| | | | (_| |\n\
\t\t |_|\\___|\\__,_|\\__,_|\\___|_|  |_.__/ \\___/ \\__,_|_|  \\__,_|\n\n");
	//formatting
	printf("\n\t");
		for(int i=0;i<75;i++)printf("*");
	printf("\n");
	for(int i=0;i<no_of_entries;i++)
	printf("\t\t\t%d.\t%-20s\t%d\n",i+1,p[i].name,p[i].score);
	getch();
	return 0;
}
int writePlayer(struct player input[]) { 
  FILE *outfile; 
    outfile = fopen ("person.txt", "w"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        //exit (1); 
    } 
  
    //struct player input1 = {"rohan", 8}; 
    //struct player inputno_of_entries = {"mahendra", 51}; 
        
    // write struct to file 
    /* TODO (#1#): change loop limit */
    for (int i=0;i<no_of_entries;i++)fwrite (&input[i], sizeof(struct player), 1, outfile); 
    //fwrite (&inputno_of_entries, sizeof(struct player), 1, outfile); 
    //fwrite (&input, sizeof(struct player), 1, outfile);
      
    if(fwrite != 0)  
        printf("written");//"contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
  
    // close file 
    fclose (outfile); 
  
    return 0;   
} 
int sortPlayers(int index){	int n=no_of_entries;
char n_name[20];
	strcpy(n_name,p[index].name);
	for(int i=0;i<n-1;i++)
	{
		for (int j=0;j<n-i-1;j++){
			if(p[j+1].score>p[j].score){
			int score_temp=p[j].score;
			char name_temp[10];
			strcpy(name_temp,p[j].name);
			memcpy(p[j].name,p[j+1].name,sizeof(p[j].name));
		//	memcpy(p[j].score,p[j+1].score,sizeof(p[j].score));
			p[j].score=p[j+1].score;
			p[j+1].score=score_temp;
			strcpy(p[j+1].name,name_temp);
			//memcpy(p[j+1].name,name_temp,sizeof(p[j+1].name));
		//	memcpy(p[j+1].score,score_temp,sizeof(p[j+1].score));}
		}
	}
	}
	return searchName(n_name);	

}
void refresh(){
	//readPlayer();
	//writePlayer(p);
//	sortPlayers();
//	printLeaderBoard();
	}//}
void updatePlayerScore(int id,long score){
	p[id].score+=score;
	//refresh();
	writePlayer(p);
	printf("done %d",id);
}
void add_player(struct player input){
	int i=searchName("");
	strcpy(p[i].name,input.name);
	p[i].score=input.score;
	writePlayer(p);
	readPlayer();
	
}

int searchName(char name[20]){
	int i=0;
	while(strcmp(p[i].name,name)!=0){
	i++;
	if(i==20)return -1;
	}
	return i;
}
int loginPage()
{
	readPlayer();
	char name[20];
	printf("\n\t\t\t");
	for(int i=0;i<100;i++)printf("*");
	printf("\n\n\n\t\t\tEnter your name...");
	//	printf("\n\t\t\t");
//	for(int i=0;i<100;i++)printf("*");
	gets(name);
	struct player newplayer;
	strcpy(newplayer.name,name);
	newplayer.score=10;
	if(searchName(name)<0){
	add_player(newplayer);
	return searchName(name);}
	else return searchName(name);
}
int leadB(int index){
	readPlayer();
	index =	sortPlayers(index);
	printLeaderBoard();
	return index;
}


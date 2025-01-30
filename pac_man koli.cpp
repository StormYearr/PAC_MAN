#include <iostream>  
#include <stdio.h>  
#include <windows.h>  
#include <string>  
#include <vector>  
#include <stdlib.h>
#include <conio.h>
#pragma warning (disable:4996)
#define GHOST "\xF0\x9F\x91\xBB"
using namespace std;
#define StdLen      100

struct User
{
    char pass[StdLen];  
    char  Name[StdLen];
    char ID[StdLen];
    int level;
    struct User *next;
    struct User *pBefor;
	
   
};
//global;
char name[50], password[50];
 char file_name[50], file_password[50],file_ID[50],save[50];
 int file_level;
char tmp_map[18][32]; 
 char temp_name[50], temp_password[50];
 char ID[50];
 char pass2[50]; 
 char cpass[50];
 char state[50];
int yaft,yaft2;



char tmp_map1[5][15];
    char map1[5][15]=
    {
      "|-----------|",
      "|P     -    |",
      "|  -|       |",
      "|      - -  |",
      "|-----------|"
    };
  char tmp_map2[8][12];
  char map2[8][12]=
    {
     "|--------|",
     "|   |P   |",
     "|   |    |",
     "|        |",
     "|-       |",
     "|      - |",
     "|P  |    |",
     "|--------|"
    };
    char tmp_map3[10][20];
    char map3[10][20]=
    {
       "|----------------|",
       "|   |P -         |",
       "|  -| |          |",
       "|  -  |-         |",
       "|  |             |",
       "|       |   |   -|",
       "|       |     |  |",
       "|                |",
       "| P |     |    P |",
       "|----------------|"
    };



//Golden map
char tmp_map4[18][32];
char map4[18][32] = {  
    "+#############################+",  
    "|           #           #     |", 
    "|                 P           |",  
    "|## ##### ##### ##   #### ####|",  
    "|   |                         |",  
    "| | |### | |        P   |     |",  
    "| |      |  | |###  |   |  |  |",  
    "| | #####|  | |      ## | P   |",  
    "| |           |###  |      |  |",  
    "| |### # ###         ##      P|",  
    "|          ######  ####### ###|",  
    "|                            P|",  
    "|# ### ####      ###   ## ####|",  
    "|P                            |",  
    "|                             |",  
    "|      #                      |",  
    "|                            P|",  
    "+#############################+"};


char tmp_map5[18][60];
char map5[18][60]={
    "+#########################################################+",  
    "|   ##      #           #                                 |", 
    "|                 P            |  ##  |  ##  |      |     |",  
    "|## ##### ##### ##   #### #### |      |      ####### P|   |",  
    "| P |                                        #            |",  
    "| | |### |  |       P   |        |    | |    #      |     |",  
    "| |      |  | |###  |   |  |   ##### #       #            |",  
    "| | #####|  | |      ## | P          #   |   #   #########|",  
    "| |           |###  |      |    |    #       #   #     P  |",  
    "| |### # ###         ##      P       #########   #    ####|",  
    "|          ######  ####### ###    |          #   #    #   |",  
    "|                            P               |            |",  
    "|# ### ####      ###   ## ####      ###################   |",  
    "|P                                  #                     |",  
    "|           |                       #           ##########|",  
    "|      #         P   ####    |      #      |              |",  
    "|         |                                       |      P|",  
    "+#########################################################+"};

void ShowMap1();
void ShowMap2();
void ShowMap3();
void ShowMap4();
void ShowMap5();

void gotoxy(short x,short y);
void AddArray1(int x,int y,int Mc,int back);
void AddArray2(int x,int y,int Mc,int back);
void AddArray3(int x,int y,int Mc,int back);
void AddArray4(int x,int y,int Mc, int back);
void AddArray5(int x,int y,int Mc, int back);

void FindWay1(int zx,int zy,int x,int y);
void FindWay2(int zx,int zy,int x,int y);
void FindWay3(int zx,int zy,int x,int y);
void FindWay4(int zx,int zy,int x,int y);
void FindWay5(int zx,int zy,int x,int y);


void Class1();
void Class2();
void Class3();
void Class4(); 
void Class5();

void  help();
void play();
void log();
void speed();
void welcome();


void printlist();
void deletall();
void deletone();
void printone();

struct User * registerUser();
void saveToFile(struct User *head) ;  
void changeUsersLevel(struct User* head,  char pass2[50],int Level);
struct User   * LoadUserInfoFromFile(char *strFileName);
struct User *gethead(struct User *head );
void deletf(char cpass[50]);
//void deleteNode(struct User** head);
//void   DeleteUser(struct User **pHead, char pass[50]); 
void deleteUserf(struct User** head, char* ToRemove);
  struct walk  
{  
    short walk_count;  
    short x;  
    short y;  
    short back;  
};  
  
struct target  
{  
    short x;  
    short y;  
};  

vector<target> walk_queue;  
vector<walk> BFSArray;   

 
  

int main()  
{  
   
	welcome();
    struct User user;
    struct User *head;
     char    strFileName[100];
   
   
    int  cmd;
	int target;
    int select;
	int  correct;
    bool working=true;
	char Enter[20];
	char file_enter[20];
 while(1)
 {   
    system("Color D0");
	scanf("%s",Enter);
	FILE *pfile=fopen("ENTER.txt","r");
while(fscanf(pfile,"%s",file_enter) !=EOF)
{	  
	if(strcmp(Enter,file_enter)==0)
	{
         correct=1;
		 break;
	}
	
}	
if(correct==1)
{ 
 printf("\033[1;32mYou are logged in!");
    
while(working)
{    
    strcpy(strFileName, "users.txt" );
    head = LoadUserInfoFromFile(strFileName);
    int frame=0;
    log();
    cin>>select;
    struct User *p;
    if(select==2)
    {
     // first time
    
    // registerUser();
     p=gethead(registerUser());
  //  if(p== NULL)
    //{
     // printf("\nYou have already registered, please select login\n");
     // continue;
   // }

    
   // saveToFile(ptmp);
   
    }
    else if(select==1)  //log in
        {   
            struct User *pt;
            char name[50];
            char iD[50]; 
			char password1[50];
            char file_name[50];
            char file_ID[50];
            int found=0;
            printf("\033[1;36mEnter your name: ");
            scanf("%s",name );
            strcpy(save,name);
            printf("\033[1;36mEnter your password: ");
            scanf("%s", password1);
            strcpy(pass2,password1);
            FILE *cfile = fopen("change.txt", "w");
            fprintf(cfile,"%s",password1);
            fclose(cfile);
            FILE *file = fopen("users.txt", "r");
            if(file==NULL)
            printf("can not be opened");
            while(fscanf(file,"%s %s %s %d",file_name,file_ID,file_password ,&file_level) !=EOF)
            {
                   if(strcmp(name,file_name)==0 && strcmp(password1,file_password)==0)
                   {
                   found=1;
                   break;
                   }
            }
            fclose(file);
            if(found)
           {  
			 printf("\033[1;32mYou are logged into your account\n");
              help();
            cin >> cmd;
           while(cmd)
      {
            switch(cmd)
          {
             case 1:
             deletone();
             break;
             case 2:
             deletall();
               break;
              case 3:
               printlist();
                break;
               case 4:
               printone();
                break;
           
            default:
                cout << "\n\033[1;31mCommand is not Valide!!!!!\n";
        }
        help();
        cin >> cmd;
    }


//void asli(char diffi)
bool game=true;
while(game)
{

   play();
    bool running = true;  
    int x,y; 
    int old_x;  
    int old_y;  

    int ex ;
    int ey ; 
    int score = 0;  
  

    
    int level;
    int speedmod ;
    char choice;
    cin>>choice;

    if(choice=='H')
    
{   printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=7;
		y=1;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=1;
		ey=2;

     system("cls");  //clear the page  
     ShowMap3();
     gotoxy( x, y);
	printf("%s","@");
     Class3();
     FindWay3(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map3[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map3[y-1][x] == ' ' ||  map3[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map3[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map3[y+1][x] == ' ' || map3[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map3[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map3[y][x-1] == ' ' || map3[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map3[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map3[y][x+1] == ' ' || map3[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay3( ex,ey,x,y );
		}


		gotoxy( x,y );
	    printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==3){
			break;
		}

      

		gotoxy( 20, 10 );
		gotoxy( 20, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 1, ey = 6;
	int ex2=5 ,ey2=5;
    system("cls");   
    ShowMap3(); 
     gotoxy(x, y);  
     printf("%s","@");  
    gotoxy(ex,ey); 
    printf("%c",char(2)); 
     gotoxy(ex2,ey2); 
     printf("%c",char(1));


    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map3[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map3[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map3[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map3[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map3[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map3[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map3[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map3[y][x + 1] == ' ')  
                x++;  
        }  
      
       
  
    
            // Sleep(200); 
              gotoxy(x, y);  
             printf("%s","@");  
              gotoxy(ex, ey); 
              cout << " ";
               
             if (direction == 0 &&( map3[ey - 1][ex] == ' ' || map3[ey - 1][ex] == '@' ) &&  map3[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map3[ey + 1][ex] == ' ' || map3[ey + 1][ex] == '@') && map3[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map3[ey][ex - 1] == ' ' || map3[ey][ex - 1] == '@' ) && map3[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map3[ey][ex + 1] == ' ' || map3[ey][ex + 1] == '@' ) && map3[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
              printf("%c",char(2)); 
        
        //mokhtasat nameyesh score
        gotoxy(20, 10);  
        gotoxy(20, 1);  
        cout << score;  
        gotoxy(20,10);
        //printf("")

		     if (map3[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
			   gotoxy(ex2, ey2); 
              cout << " ";
               
             if (direction2 == 0 &&( map3[ey2 - 1][ex2] == ' ' || map3[ey2 - 1][ex2] == '@' ) &&  map3[ey2 - 1][ex2] !='#' ) 
            ey2--; 
        else if (direction2 == 1 &&( map3[ey2 + 1][ex2] == ' ' || map3[ey2 + 1][ex2] == '@') && map3[ey2 + 1][ex2] != '#' ) 
            ey2++; 
        else if (direction2 == 2 && (map3[ey2][ex2 - 1] == ' ' || map3[ey2][ex2 - 1] == '@' ) && map3[ey2][ex2 - 1] != '#') 
            ex2--; 
        else if (direction2 == 3 && (map3[ey2][ex2 + 1] == ' ' || map3[ey2][ex2 + 1] == '@' ) && map3[ey2][ex2 + 1] != '#') 
            ex2++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex2, ey2); 
             printf("%c",char(1)); 
            Sleep(300);
            
			  if (map3[ey2][ex2] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex2==x && ey2==y)
            {
              gameOver = true;
                break;
            }

             
             if ( score==3)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     


        
        }        //while(1)
		               
    }         //gameOver

}           //target==2


    
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 3) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);

     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{
FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"3");
 fprintf(file,"%s",state);
 fclose(file);

//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");


}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=3)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	  FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");       
   
    
   } 
        else if(score==3)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");        
   
         }

      }



    else if(choice=='N')
    
{   printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=5;
		y=4;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=3;
		ey=1;

     system("cls");  //clear the page  
     ShowMap2();
     gotoxy( x, y);
	   printf("%s","@");
     Class2();
     FindWay2(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map2[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map2[y-1][x] == ' ' ||  map2[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map2[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map2[y+1][x] == ' ' || map2[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map2[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map2[y][x-1] == ' ' || map2[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map2[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map2[y][x+1] == ' ' || map2[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay2( ex,ey,x,y );
		}


		gotoxy( x,y );
	     printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==2){
			break;
		}

      

		gotoxy( 12, 8 );
		gotoxy( 12, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 3, ey = 1;
	int ex2=3 ,ey2=7;
    system("cls");   
    ShowMap2(); 
     gotoxy(x, y);  
      printf("%s","@"); 
    gotoxy(ex,ey); 
      printf("%c",char(2));
    gotoxy(ex,ey); 
      printf("%c",char(1)); 


    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map2[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map2[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map2[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map2[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map2[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map2[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map2[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map2[y][x + 1] == ' ')  
                x++;  
        }  
      
       
              //mokhtasat nameyesh score
            gotoxy(12, 8);  
            gotoxy(12, 1);  
             cout << score;  
            gotoxy(12,8);
        
    

              gotoxy(x, y);  
                printf("%s","@");
              gotoxy(ex, ey); 
                printf(" ");
               
             if (direction == 0 &&( map2[ey - 1][ex] == ' ' || map2[ey - 1][ex] == '@' ) &&  map2[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map2[ey + 1][ex] == ' ' || map2[ey + 1][ex] == '@') && map2[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map2[ey][ex - 1] == ' ' || map2[ey][ex - 1] == '@' ) && map2[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map2[ey][ex + 1] == ' ' || map2[ey][ex + 1] == '@' ) && map2[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
             printf("%c",char(2)); 
   

		     if (map2[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
			   gotoxy(ex2, ey2); 
              cout << " ";
               
             if (direction2 == 0 &&( map2[ey2 - 1][ex2] == ' ' || map2[ey2 - 1][ex2] == '@' ) &&  map2[ey2 - 1][ex2] !='#' ) 
            ey2--; 
        else if (direction2 == 1 &&( map2[ey2 + 1][ex2] == ' ' || map2[ey2 + 1][ex2] == '@') && map2[ey2 + 1][ex2] != '#' ) 
            ey2++; 
        else if (direction2 == 2 && (map2[ey2][ex2 - 1] == ' ' || map2[ey2][ex2 - 1] == '@' ) && map2[ey2][ex2 - 1] != '#') 
            ex2--; 
        else if (direction2 == 3 && (map2[ey2][ex2 + 1] == ' ' || map2[ey2][ex2 + 1] == '@' ) && map2[ey2][ex2 + 1] != '#') 
            ex2++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex2, ey2); 
             printf("%c",char(1)); 
            Sleep(400);
            
			  if (map2[ey2][ex2] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex2==x && ey2==y)
            {
              gameOver = true;
                break;
            }

                  if ( score==2)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     
       



        
        }        //while(1)
		               
    }         //gameOver

}           //target==2


    
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 2) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);

     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{
FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"2");
 fprintf(file,"%s",state);
 fclose(file);

//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");
 

}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=2)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	 FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");    
   
    
   } 
        else if(score==2)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
    FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");       
   
         }

      }





    else if(choice=='E')
{   printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=11;
		y=3;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=3;
		ey=1;

     system("cls");  //clear the page  
     ShowMap1();
     gotoxy( x, y);
	 printf("%s","@");
     Class1();
     FindWay1(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map1[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map1[y-1][x] == ' ' ||  map1[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map1[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map1[y+1][x] == ' ' || map1[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map1[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map1[y][x-1] == ' ' || map1[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map1[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map1[y][x+1] == ' ' || map1[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay1( ex,ey,x,y );
		}


		gotoxy( x,y );
	    printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==1){
			break;
		}

      

		gotoxy( 15, 5 );
		gotoxy( 15, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 3, ey = 1;
    system("cls");   
    ShowMap1(); 
     gotoxy(x, y);  
      printf("%s","@"); 
    gotoxy(ex,ey); 
      printf("%c",char(2));


    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map1[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map1[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map1[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map1[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map1[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map1[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map1[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map1[y][x + 1] == ' ')  
                x++;  
        }  
      
        
        //mokhtasat nameyesh score
        gotoxy(15, 5);  
        gotoxy(15, 1);  
        cout << score;  
        gotoxy(15,5);
        //print("")
  
    
            // Sleep(200); 
              gotoxy(x, y);  
                printf("%s","@");  
              gotoxy(ex, ey); 
              cout << " ";
               
             if (direction == 0 &&( map1[ey - 1][ex] == ' ' || map1[ey - 1][ex] == '@' ) &&  map1[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map1[ey + 1][ex] == ' ' || map1[ey + 1][ex] == '@') && map1[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map1[ey][ex - 1] == ' ' || map1[ey][ex - 1] == '@' ) && map1[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map1[ey][ex + 1] == '.' || map1[ey][ex + 1] == '@') && map1[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
              printf("%c",char(2)); 
            Sleep(400);
       


		     if (map1[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
	            
             if ( score==1)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     
       




        
        }        //while(1)
		               
    }         //gameOver

}           //target==2


    
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 1) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);


     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{

FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"1");
 fprintf(file,"%s",state);
 fclose(file);

//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n"); 

}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=1)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	  FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");       
   
    
   } 
        else if(score==1)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");    
         }

      }




    else if(choice=='G')
{   printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=15;
		y=16;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=1;
		ey=1;

     system("cls");  //clear the page  
     ShowMap4();
     gotoxy( x, y); 
    printf("%s","@");
     Class4();
     FindWay4(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map4[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map4[y-1][x] == ' ' ||  map4[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map4[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map4[y+1][x] == ' ' || map4[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map4[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map4[y][x-1] == ' ' || map4[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map4[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map4[y][x+1] == ' ' || map4[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay4( ex,ey,x,y );
		}


		gotoxy( x,y );
        printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==8){
			break;
		}

FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
 while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) 
 {
    if(strcmp(user.pass, cpass) == 0)
      {
         gotoxy(32,20);
         gotoxy(32,2);
         printf("%s",user.Name);
      }
         
}
       
		gotoxy( 32, 18 );
		gotoxy( 32, 1 );
		cout << score;

		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 1, ey = 1;
	int ex2=1 ,ey2=15;
    system("cls");   
    ShowMap4(); 
     gotoxy(x, y);  
  printf("%s","@");
    gotoxy(ex,ey); 
    printf("%c",char(2)); 
    gotoxy(ex2,ey2); 
   printf("%c",char(1));

    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map4[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map4[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map4[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map4[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map4[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map4[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map4[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map4[y][x + 1] == ' ')  
                x++;  
        }  
      
    while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) 
 {
    if(strcmp(user.pass, pass2) == 0)
      {
        // gotoxy(32,20);
         gotoxy(32,2);
         printf("%s\n",user.Name);
         break;
      }
         
}
      
        //mokhtasat nameyesh score
        gotoxy(32, 18);  
        gotoxy(32, 1);  
        cout << score<<"\t"<<save;  
        gotoxy(32,18);
        //printf("")
    
            // Sleep(200); 
              gotoxy(x, y);  
                printf("%s","@");  
              gotoxy(ex, ey); 
              cout << " ";
               
             if (direction == 0 &&( map4[ey - 1][ex] == ' ' || map4[ey - 1][ex] == '@') &&  map4[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map4[ey + 1][ex] == ' ' || map4[ey + 1][ex] == '@') && map4[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map4[ey][ex - 1] == ' ' || map4[ey][ex - 1] == '@' ) && map4[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map4[ey][ex + 1] == ' ' || map4[ey][ex + 1] == '@' ) && map4[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
              printf("%c",char(2)); 
            //Sleep(200);
           

		     if (map4[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
			   gotoxy(ex2, ey2); 
              cout << " ";
               
             if (direction2 == 0 &&( map4[ey2 - 1][ex2] == ' ' || map4[ey2 - 1][ex2] == '@' ) &&  map4[ey2 - 1][ex2] !='#' ) 
            ey2--; 
        else if (direction2 == 1 &&( map4[ey2 + 1][ex2] == ' ' || map4[ey2 + 1][ex2] == '@') && map4[ey2 + 1][ex2] != '#' ) 
            ey2++; 
        else if (direction2 == 2 && (map4[ey2][ex2 - 1] == ' ' || map4[ey2][ex2 - 1] == '@' ) && map4[ey2][ex2 - 1] != '#') 
            ex2--; 
        else if (direction2 == 3 && (map4[ey2][ex2 + 1] == ' ' || map4[ey2][ex2 + 1] == '@' ) && map4[ey2][ex2 + 1] != '#') 
            ex2++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex2, ey2); 
              printf("%c",char(1)); 
            Sleep(200);
            
			  if (map4[ey2][ex2] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex2==x && ey2==y)
            {
              gameOver = true;
                break;
            }

               if ( score==8)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     


        
        }        //while(1)
		               
    }         //gameOver

}           //target==2

FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 8) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);


     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{

 FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"4");
 fprintf(file,"%s",state);
 fclose(file);



//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");
 

}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=8)
   {  
       struct User user;
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	 // FILE *file=fopen("level3.txt","r");
	  //fscanf(file,"%d",&level);
     // printf("Your Level is : %d",level);  
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");    
   
    
   } 
        else if(score==8)
   {
    struct User user;
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
    // FILE *file=fopen("level3.txt","r");
	// fscanf(file,"%d",&level);
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
         // break;
        }
     }
      
     printf("\n"); 
     int des;
     printf("The special stage of the game has been opened for you, do you want to play it?\n1. yes\n2. NO\n\n");
     scanf("%d",&des);
     if(des==1)
     {
       score=0;	
       printf("The speed at this stage is fast by default\n");
        Sleep(3000);
		x=5;
		y=6;
		ex=1;
		ey=1;
        speedmod=3;

     system("cls");  //clear the page  
     ShowMap5();
     gotoxy( x, y);
	 printf("%s\033[1;33m","@");
     Class5();
     FindWay5(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map5[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map5[y-1][x] == ' ' ||  map5[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map5[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map5[y+1][x] == ' ' || map5[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map5[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map5[y][x-1] == ' ' || map5[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map5[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map5[y][x+1] == ' ' || map5[y][x+1] == '@' )
			   x++;
		}


        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay5( ex,ey,x,y );
		}


		gotoxy( x,y );
	    printf("%s\033[1;33m","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c\033[1;31m",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==11){
			break;
		}

        while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) 
 {
    if(strcmp(user.pass, pass2) == 0)
      {
         gotoxy(32,20);
         gotoxy(32,2);
         printf("%s\n",user.Name);
      }
         
}
      

		gotoxy( 60, 18 );
		gotoxy( 60, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 11) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);


       if(score!=11)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	  FILE *file=fopen("level3.txt","r");
	  fscanf(file,"%d",&level);
      printf("Your Level is : %d",level);  
      printf("\n");    
   
    
   } 
        else if(score==11)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
     FILE *file=fopen("level3.txt","r");
	 fscanf(file,"%d",&level);
     printf("Your Level is : %d",level);  
     printf("\n");    
   
         }

     }
     else if(des==2)
     {
        
     }
   
         }

      }





	  else if(choice=='B')
	  {
         break;
	  }
      
      else if(choice=='R')
      {
        char Res[50];
         FILE *file=fopen("Map.txt","r");
         fscanf(file,"%s",Res);
         if(file==NULL)
         printf("\nYou have not saved any game state before\n");
          if (strcmp(Res,"1") == 0)
         {
          // map E
          
     
     
  printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=11;
		y=3;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=3;
		ey=1;

     system("cls");  //clear the page  
     ShowMap1();
     gotoxy( x, y);
	 printf("%s","@");
     Class1();
     FindWay1(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map1[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map1[y-1][x] == ' ' ||  map1[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map1[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map1[y+1][x] == ' ' || map1[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map1[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map1[y][x-1] == ' ' || map1[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map1[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map1[y][x+1] == ' ' || map1[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay1( ex,ey,x,y );
		}


		gotoxy( x,y );
	    printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==1){
			break;
		}

      

		gotoxy( 15, 5 );
		gotoxy( 15, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 3, ey = 1;
    system("cls");   
    ShowMap1(); 
     gotoxy(x, y);  
      printf("%s","@"); 
    gotoxy(ex,ey); 
      printf("%c",char(2));


    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map1[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map1[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map1[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map1[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map1[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map1[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map1[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map1[y][x + 1] == ' ')  
                x++;  
        }  
      
        
        //mokhtasat nameyesh score
        gotoxy(15, 5);  
        gotoxy(15, 1);  
        cout << score;  
        gotoxy(15,5);
        //print("")
  
    
            // Sleep(200); 
              gotoxy(x, y);  
                printf("%s","@");  
              gotoxy(ex, ey); 
              cout << " ";
               
             if (direction == 0 &&( map1[ey - 1][ex] == ' ' || map1[ey - 1][ex] == '@' ) &&  map1[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map1[ey + 1][ex] == ' ' || map1[ey + 1][ex] == '@') && map1[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map1[ey][ex - 1] == ' ' || map1[ey][ex - 1] == '@' ) && map1[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map1[ey][ex + 1] == '.' || map1[ey][ex + 1] == '@') && map1[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
              printf("%c",char(2)); 
            Sleep(400);
       


		     if (map1[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
	            
             if ( score==1)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     
       




        
        }        //while(1)
		               
    }         //gameOver

}           //target==2


    
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 1) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);


     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{

FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"1");
 fprintf(file,"%s",state);
 fclose(file);

//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");

}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=1)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	  FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");       
   
    
   } 
        else if(score==1)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");    
         }

      

         }

         else if (strcmp(Res,"2") == 0)
          {
           //map N
            printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=5;
		y=4;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=3;
		ey=1;

     system("cls");  //clear the page  
     ShowMap2();
     gotoxy( x, y);
	   printf("%s","@");
     Class2();
     FindWay2(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map2[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map2[y-1][x] == ' ' ||  map2[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map2[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map2[y+1][x] == ' ' || map2[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map2[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map2[y][x-1] == ' ' || map2[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map2[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map2[y][x+1] == ' ' || map2[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay2( ex,ey,x,y );
		}


		gotoxy( x,y );
	     printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==2){
			break;
		}

      

		gotoxy( 12, 8 );
		gotoxy( 12, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 3, ey = 1;
	int ex2=3 ,ey2=7;
    system("cls");   
    ShowMap2(); 
     gotoxy(x, y);  
      printf("%s","@"); 
    gotoxy(ex,ey); 
      printf("%c",char(2));
    gotoxy(ex,ey); 
      printf("%c",char(1)); 


    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map2[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map2[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map2[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map2[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map2[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map2[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map2[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map2[y][x + 1] == ' ')  
                x++;  
        }  
      
       
              //mokhtasat nameyesh score
            gotoxy(12, 8);  
            gotoxy(12, 1);  
             cout << score;  
            gotoxy(12,8);
        
    

              gotoxy(x, y);  
                printf("%s","@");
              gotoxy(ex, ey); 
                printf(" ");
               
             if (direction == 0 &&( map2[ey - 1][ex] == ' ' || map2[ey - 1][ex] == '@' ) &&  map2[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map2[ey + 1][ex] == ' ' || map2[ey + 1][ex] == '@') && map2[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map2[ey][ex - 1] == ' ' || map2[ey][ex - 1] == '@' ) && map2[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map2[ey][ex + 1] == ' ' || map2[ey][ex + 1] == '@' ) && map2[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
             printf("%c",char(2)); 
   

		     if (map2[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
			   gotoxy(ex2, ey2); 
              cout << " ";
               
             if (direction2 == 0 &&( map2[ey2 - 1][ex2] == ' ' || map2[ey2 - 1][ex2] == '@' ) &&  map2[ey2 - 1][ex2] !='#' ) 
            ey2--; 
        else if (direction2 == 1 &&( map2[ey2 + 1][ex2] == ' ' || map2[ey2 + 1][ex2] == '@') && map2[ey2 + 1][ex2] != '#' ) 
            ey2++; 
        else if (direction2 == 2 && (map2[ey2][ex2 - 1] == ' ' || map2[ey2][ex2 - 1] == '@' ) && map2[ey2][ex2 - 1] != '#') 
            ex2--; 
        else if (direction2 == 3 && (map2[ey2][ex2 + 1] == ' ' || map2[ey2][ex2 + 1] == '@' ) && map2[ey2][ex2 + 1] != '#') 
            ex2++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex2, ey2); 
             printf("%c",char(1)); 
            Sleep(400);
            
			  if (map2[ey2][ex2] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex2==x && ey2==y)
            {
              gameOver = true;
                break;
            }

                  if ( score==2)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     
       



        
        }        //while(1)
		               
    }         //gameOver

}           //target==2


    
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 2) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);

     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{
FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"2");
 fprintf(file,"%s",state);
 fclose(file);

//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");


}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=2)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	 FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");    
   
    
   } 
        else if(score==2)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
    FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");       
   
         }
          }
         
          else if (strcmp(Res,"3") == 0)
          {
            //map H
            printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=7;
		y=1;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=1;
		ey=2;

     system("cls");  //clear the page  
     ShowMap3();
     gotoxy( x, y);
	printf("%s","@");
     Class3();
     FindWay3(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map3[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map3[y-1][x] == ' ' ||  map3[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map3[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map3[y+1][x] == ' ' || map3[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map3[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map3[y][x-1] == ' ' || map3[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map3[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map3[y][x+1] == ' ' || map3[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay3( ex,ey,x,y );
		}


		gotoxy( x,y );
	    printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==3){
			break;
		}

      

		gotoxy( 20, 10 );
		gotoxy( 20, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 1, ey = 6;
	int ex2=5 ,ey2=5;
    system("cls");   
    ShowMap3(); 
     gotoxy(x, y);  
     printf("%s","@");  
    gotoxy(ex,ey); 
    printf("%c",char(2)); 
     gotoxy(ex2,ey2); 
     printf("%c",char(1));


    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map3[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map3[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map3[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map3[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map3[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map3[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map3[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map3[y][x + 1] == ' ')  
                x++;  
        }  
      
       
  
    
            // Sleep(200); 
              gotoxy(x, y);  
             printf("%s","@");  
              gotoxy(ex, ey); 
              cout << " ";
               
             if (direction == 0 &&( map3[ey - 1][ex] == ' ' || map3[ey - 1][ex] == '@' ) &&  map3[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map3[ey + 1][ex] == ' ' || map3[ey + 1][ex] == '@') && map3[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map3[ey][ex - 1] == ' ' || map3[ey][ex - 1] == '@' ) && map3[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map3[ey][ex + 1] == ' ' || map3[ey][ex + 1] == '@' ) && map3[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
              printf("%c",char(2)); 
        
        //mokhtasat nameyesh score
        gotoxy(20, 10);  
        gotoxy(20, 1);  
        cout << score;  
        gotoxy(20,10);
        //printf("")

		     if (map3[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
			   gotoxy(ex2, ey2); 
              cout << " ";
               
             if (direction2 == 0 &&( map3[ey2 - 1][ex2] == ' ' || map3[ey2 - 1][ex2] == '@' ) &&  map3[ey2 - 1][ex2] !='#' ) 
            ey2--; 
        else if (direction2 == 1 &&( map3[ey2 + 1][ex2] == ' ' || map3[ey2 + 1][ex2] == '@') && map3[ey2 + 1][ex2] != '#' ) 
            ey2++; 
        else if (direction2 == 2 && (map3[ey2][ex2 - 1] == ' ' || map3[ey2][ex2 - 1] == '@' ) && map3[ey2][ex2 - 1] != '#') 
            ex2--; 
        else if (direction2 == 3 && (map3[ey2][ex2 + 1] == ' ' || map3[ey2][ex2 + 1] == '@' ) && map3[ey2][ex2 + 1] != '#') 
            ex2++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex2, ey2); 
             printf("%c",char(1)); 
            Sleep(300);
            
			  if (map3[ey2][ex2] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex2==x && ey2==y)
            {
              gameOver = true;
                break;
            }

             
             if ( score==3)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     


        
        }        //while(1)
		               
    }         //gameOver

}           //target==2


    
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 3) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);

     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{
FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"3");
 fprintf(file,"%s",state);
 fclose(file);

//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");
  

}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=3)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	  FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");       
   
    
   } 
        else if(score==3)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");        
   
         }

          }
           else if (strcmp(Res,"4") == 0)
           {
             //map G
             printf("\nSelect the soul model :\n1. Haunting Ghost\n2. random Ghost\n\nInput : \n");
		scanf("%d",&target);
        x=15;
		y=16;
		bool gameOver=false;
		int tmp;

     if(target==1)
     {
    	
       speed();
      cin>>speedmod;
	
		ex=1;
		ey=1;

     system("cls");  //clear the page  
     ShowMap4();
     gotoxy( x, y); 
    printf("%s","@");
     Class4();
     FindWay4(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map4[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map4[y-1][x] == ' ' ||  map4[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map4[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map4[y+1][x] == ' ' || map4[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map4[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map4[y][x-1] == ' ' || map4[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map4[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map4[y][x+1] == ' ' || map4[y][x+1] == '@' )
			   x++;
		}


          if(GetAsyncKeyState(VK_SPACE))
        {
          running=false;
            
         
        }
        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay4( ex,ey,x,y );
		}


		gotoxy( x,y );
        printf("%s","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << " ";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==8){
			break;
		}

 while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) 
 {
    if(strcmp(user.pass, pass2) == 0)
      {
         gotoxy(32,20);
         gotoxy(32,2);
         printf("%s\n",user.Name);
      }
         
}
       
		gotoxy( 32, 18 );
		gotoxy( 32, 1 );
		cout << score;

		Sleep( 100 );
		frame++;
	 }

	}

   
   else if(target==2)
   {
	int ex = 1, ey = 1;
	int ex2=1 ,ey2=15;
    system("cls");   
    ShowMap4(); 
     gotoxy(x, y);  
  printf("%s","@");
    gotoxy(ex,ey); 
    printf("%c",char(2)); 
    gotoxy(ex2,ey2); 
   printf("%c",char(1));

    while(!gameOver)
    {  
        int direction = rand() % 4;
		int direction2 = rand() % 4;

        while(1)
        {     
         gotoxy(x, y);  
          cout << " ";  
          old_x = x;  
          old_y = y;  
  
        if (GetAsyncKeyState(VK_UP))  
        {  
            if (map4[y - 1][x] == 'P')  
            {  
                y--;  
                score++;  
            }  
            else if (map4[y - 1][x] == ' ')  
                y--;  
        }  
        if (GetAsyncKeyState(VK_DOWN))  
        {  
            if (map4[y + 1][x] == 'P')  
            {  
                y++;  
                score++;  
            }  
            else if (map4[y + 1][x] == ' ')  
                y++;  
        }  
        if (GetAsyncKeyState(VK_LEFT))  
        {  
            if (map4[y][x - 1] == 'P')  
            {  
                x--;  
                score++;  
            }  
            else if (map4[y][x - 1] == ' ')  
                x--;  
        }  
        if (GetAsyncKeyState(VK_RIGHT))  
        {  
            if (map4[y][x + 1] == 'P')  
            {  
                x++;  
                score++;  
            }  
            else if (map4[y][x + 1] == ' ')  
                x++;  
        }  
      
       
      
        //mokhtasat nameyesh score
        gotoxy(32, 18);  
        gotoxy(32, 1);  
        cout << score;  
        gotoxy(32,18);
        //printf("")
    
            // Sleep(200); 
              gotoxy(x, y);  
                printf("%s","@");  
              gotoxy(ex, ey); 
              cout << " ";
               
             if (direction == 0 &&( map4[ey - 1][ex] == ' ' || map4[ey - 1][ex] == '@') &&  map4[ey - 1][ex] !='#' ) 
            ey--; 
        else if (direction == 1 &&( map4[ey + 1][ex] == ' ' || map4[ey + 1][ex] == '@') && map4[ey + 1][ex] != '#' ) 
            ey++; 
        else if (direction == 2 && (map4[ey][ex - 1] == ' ' || map4[ey][ex - 1] == '@' ) && map4[ey][ex - 1] != '#') 
            ex--; 
        else if (direction == 3 && (map4[ey][ex + 1] == ' ' || map4[ey][ex + 1] == '@' ) && map4[ey][ex + 1] != '#') 
            ex++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex, ey); 
              printf("%c",char(2)); 
            //Sleep(200);
           

		     if (map4[ey][ex] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex==x && ey==y)
            {
              gameOver = true;
                break;
            }
            
			   gotoxy(ex2, ey2); 
              cout << " ";
               
             if (direction2 == 0 &&( map4[ey2 - 1][ex2] == ' ' || map4[ey2 - 1][ex2] == '@' ) &&  map4[ey2 - 1][ex2] !='#' ) 
            ey2--; 
        else if (direction2 == 1 &&( map4[ey2 + 1][ex2] == ' ' || map4[ey2 + 1][ex2] == '@') && map4[ey2 + 1][ex2] != '#' ) 
            ey2++; 
        else if (direction2 == 2 && (map4[ey2][ex2 - 1] == ' ' || map4[ey2][ex2 - 1] == '@' ) && map4[ey2][ex2 - 1] != '#') 
            ex2--; 
        else if (direction2 == 3 && (map4[ey2][ex2 + 1] == ' ' || map4[ey2][ex2 + 1] == '@' ) && map4[ey2][ex2 + 1] != '#') 
            ex2++;
            //barkhord ba divar
            else
            break; 
            gotoxy(ex2, ey2); 
              printf("%c",char(1)); 
            Sleep(200);
            
			  if (map4[ey2][ex2] == '@')
            {
                gameOver = true;
                break;
            }
            
			 if(ex2==x && ey2==y)
            {
              gameOver = true;
                break;
            }

               if ( score==8)  
            {  
            gameOver=true; 
              }  
          if(GetAsyncKeyState(VK_SPACE))
          {
            tmp=1;
           gameOver=true;
             }     


        
        }        //while(1)
		               
    }         //gameOver

}           //target==2

FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 8) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);


     if(running==false)
{
system("cls");
printf("Your score is :%i",score);
printf("\n\n");
printf("Do you want to save the current state of the game and continue it in the future?\n");
printf("YES->Y\nNO->N\n");
char res;
int i;
cin>>res;
//char file_map[18][32];
struct User user;
if(res=='Y')
{

 FILE *file =fopen("Map.txt","w");
 if(file==NULL)
 printf("can not be opened");
 strcpy(state,"4");
 fprintf(file,"%s",state);
 fclose(file);



//FILE *file=fopen("users.txt","a");
//FILE *mfile=fopen("GoldenMap.txt","r");
//user.sign=4;
//fprintf(file,"\t");
//fprintf(file,"%d",user.sign);

//fprintf(file,"\t");
//fprintf(file,"%d",c);
//user.sign=4;
//fprintf(file," ");
//fprintf(file,"%d\n",user.sign);
//int c; 
//while((c=fgetc(mfile)) !=EOF)
//{
//  fputc(c,file);
//}
//fprintf(file,"\n");
/*
for(int i=0; i<18; i++)
{
//fscanf(mfile,"%s",file_map[i]);
fprintf(file,"%s\n",map4[i]);
//fprintf(file,"\n");
}
*/	
//fclose(file);
//fclose(mfile);
printf("Your Previous selection has been saved\n\n");


}  


else if(res=='N');
{
   printf("So,then lets play a new game!!!\n");
}

}
      else if(score!=8)
   {  
       struct User user;
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	 // FILE *file=fopen("level3.txt","r");
	  //fscanf(file,"%d",&level);
     // printf("Your Level is : %d",level);  
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
          //break;
        }
     }
      printf("\n");    
   
    
   } 
        else if(score==8)
   {
    struct User user;
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
    // FILE *file=fopen("level3.txt","r");
	// fscanf(file,"%d",&level);
     FILE *file=fopen("users.txt","r");
     if(file==NULL)
     printf("file can not be opened for reading");
     while(fscanf(file,"%s %s %s %d",user.Name,user.ID,user.pass,&user.level) !=EOF)
     {
        if(strcmp(user.pass,pass2)==0)
        {
          printf("Your Level is : %d",user.level); 
         // break;
        }
     }
      
     printf("\n"); 
     int des;
     printf("The special stage of the game has been opened for you, do you want to play it?\n1. yes\n2. NO\n\n");
     scanf("%d",&des);
     if(des==1)
     {
       score=0;	
       printf("The speed at this stage is fast by default\n");
        Sleep(3000);
		x=5;
		y=6;
		ex=1;
		ey=1;
        speedmod=3;

     system("cls");  //clear the page  
     ShowMap5();
     gotoxy( x, y);
	 printf("%s\033[1;33m","@");
     Class5();
     FindWay5(ex,ey,x,y);
     while( running )
     {
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;
     
        if ( GetAsyncKeyState( VK_UP ) )   //Async = hamgaam
		{                       
			if( map5[y-1][x] == 'P' )
			 {
				 y--; 
			     score++;
			 } 
		
			else if( map5[y-1][x] == ' ' ||  map5[y-1][x] == '@' ) 
			      y--;
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			if( map5[y+1][x] == 'P' )
			{ 
				y++;
			    score++;
		    }
			else if( map5[y+1][x] == ' ' || map5[y+1][x] == '@' )
			    y++;
		}

		if ( GetAsyncKeyState( VK_LEFT ) )
		{
			if( map5[y][x-1] == 'P' )
			{
				 x--;
				 score++; 
			} 
			else if( map5[y][x-1] == ' ' || map5[y][x-1] == '@' ) 
			     x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			if( map5[y][x+1] == 'P' )
			{ 
				x++;
			    score++;
		    } 
			else if( map5[y][x+1] == ' ' || map5[y][x+1] == '@' )
			   x++;
		}


        //Back to game screen
		   if(GetAsyncKeyState(VK_HOME))
        {
           break;
        }

	    if( old_x != x || old_y != y ){
			FindWay5( ex,ey,x,y );
		}


		gotoxy( x,y );
	    printf("%s\033[1;33m","@");
		
	    map4[ey][ex] = ' ';  
        gotoxy(ex, ey);  
        cout << "\033[1;31m";  
		/*map3[ex2][ey2]='.';
		gotoxy(ex2,ey2);
		cout<<".";*/
		 if (frame % speedmod == 0 && walk_queue.size() != 0)  
        {  
            ex = walk_queue.back().x;  
            ey = walk_queue.back().y;  
            walk_queue.pop_back();  
        }  
          gotoxy(ex,ey);
		  printf("%c\033[1;31m",char(2));
		  //cout<<"F";
		//printf("%s",GHOST);

		if((ex == x && ey == y ) || score==11){
			break;
		}

      

		gotoxy( 60, 18 );
		gotoxy( 60, 1 );
		cout << score;
		Sleep( 100 );
		frame++;
	 }
FILE *cfile = fopen("change.txt", "r");
if(cfile==NULL)
printf("can not be opened for reading");
fscanf(cfile,"%s",cpass);
FILE *file = fopen("users.txt", "r");
if(file == NULL) {
    printf("Error opening file for reading\n"); 
}
// taghir mikoneh vali brayeh namayesh bayad to file ham taghir bedi
while(fscanf(file, "%s %s %s %d", user.Name, user.ID, user.pass, &user.level) != EOF) {
    if(strcmp(user.pass, cpass) == 0) {
        if(score == 11) {
            user.level++;
        } else {
            user.level = user.level - 3;
        }
         
    }
}

fclose(file); 
fclose(cfile);

changeUsersLevel(p, cpass, user.level);

       if(score!=11)
   {
      system("cls");  
   	  printf("\033[1;31mUnfortunately, you lost the game and your score is : %i",score);  
	  printf("\n");
	  FILE *file=fopen("level3.txt","r");
	  fscanf(file,"%d",&level);
      printf("Your Level is : %d",level);  
      printf("\n");    
   
    
   } 
        else if(score==11)
   {
     system("cls");  
     printf("\033[1;32mCongratulations, you won the game and your score is :%i",score);  
	 printf("\n");
     FILE *file=fopen("level3.txt","r");
	 fscanf(file,"%d",&level);
     printf("Your Level is : %d",level);  
     printf("\n");    
   
         }

     }
     else if(des==2)
     {
        
     }
   
         }
           }

            else 
            {
             printf("\nyou have not save any state yet\n");
            }

             
      }


	  

   }
 continue;
   
}



           else if(found!=1) {
            printf("\033[1;31mInvalid name or password\n");
            printf(" \033[1;33mPlease try again");
            printf("\033[1;37m\n\n");
               }

        
         }
    
    } 
}

   else if(correct!=1)
 {
    printf("\033[1;31mThe password you entered is incorrect\033[0m\n");
    printf(" \033[1;33mPlease try again");
    printf("\n\n");
    Sleep(3000);

 }

}
    return 0; 
} 
 
 
 void printlist()
{
      FILE *file = fopen("users.txt", "r");
      while(fscanf(file,"%s %s %s %d",file_name,file_password,file_ID,&file_level) != EOF)
      {
         printf("%s\t%s\t%s\t%d",file_name,file_password,file_ID,file_level);
         printf("\n");
      }
      fclose(file);
 }



void deletall()
{
    FILE *file=fopen("users.txt","w");
    fclose(file);
}

void deletone()
{
    printf("Enter the name for deletion: ");
    scanf("%s", temp_name);
    printf("Enter the password for deletion: ");
    scanf("%s", temp_password);

    FILE *file = fopen("users.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w"); // file movaghat

    while (fscanf(file, "%s %s %s %d", file_name,file_ID,file_password,&file_level) != EOF)
    {
        if (strcmp(temp_name, file_name) == 0 && strcmp(temp_password, file_password) == 0)
        {
            //we find the user so no need for writing her/his info in the new file
        }
        else
        {
            fprintf(tempFile, "%s %s %s %d\n", file_name, file_password,file_ID,file_level);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt"); // delet main file
    rename("temp.txt", "users.txt"); // chang name

    printf("Deletion was successful");
}

void printone()
{
      printf("Enter the name for print: ");
        scanf("%s", temp_name);
         printf("Enter the password for print: ");
         scanf("%s", temp_password);

      FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        printf("File can not be opened");
    }

    struct User user;
    while (fscanf(file, "%s %s %s %d", user.Name,user.ID,user.pass,&user.level) != EOF) {
        if (strcmp(temp_name, user.Name) == 0 && strcmp(temp_password, user.pass) == 0) {
            printf("User Found: %s %s %s %d\n", user.Name,user.ID,user.pass,user.level);
        }
    }

    fclose(file);
}

struct User* registerUser() {
    struct User* head = NULL;
    struct User* newUser = (struct User*)malloc(sizeof(struct User));

    printf("Enter your name: ");
    scanf("%s", newUser->Name);

    printf("Enter your ID: ");
    scanf("%s", newUser->ID);

    printf("Enter your Password: ");
    scanf("%s", newUser->pass);
    
             newUser->level = 0;

    FILE *file = fopen("users.txt", "r");
    if (file != NULL) {
           int userExists = 0;
    while (fscanf(file, "%s %s %s %d", file_name, file_ID, file_password, &file_level) != EOF) {
        if (strcmp(file_ID, newUser->ID) == 0) {
            userExists = 1;
            break;
        }
    }

    
    if (userExists) {
        printf("User with this information already exists,so use Log in.\n");
        free(newUser);
        return NULL;
    }
       
    }

    fclose(file);


   
    newUser->next = head;
    head = newUser;

    saveToFile(head);

    return head;
}
struct User *gethead(struct User *head )
{
    struct User *ptemp;
    ptemp=head;
    return ptemp;
}

void saveToFile(struct User* head) {
    FILE *file = fopen("users.txt", "a+");
    if (file == NULL) {
        printf("Error in opening file for writing.");
        return;
    }

    struct User* current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %s %d\n", current->Name, current->ID,current->pass,current->level);
        current = current->next;
    }

    fclose(file);
}


void changeUsersLevel(struct User* head, char cpass[50], int Level) {
    if (head == NULL) {
        printf("Error: Head is NULL\n");
        return;
    }

    struct User* current = head;
    while (current != NULL) {
        if (strcmp(current->pass, cpass) == 0) {
            current->level = Level;
            // DeleteUser(&head, pass2); // 
            break; 
        }
        if(current->next != NULL) { 
            current = current->next;
        } else {
            break; 
        }
    }
      deleteUserf(&head,cpass);
      deletf(cpass);

    saveToFile(head);
}

void deletf(char cpass[50])
{
    FILE *file = fopen("users.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w"); // file movaghat

    while (fscanf(file, "%s %s %s %d", file_name,file_ID,file_password,&file_level) != EOF)
    {
        if ((cpass, file_password) == 0)
        {
            //we find the user so no need for writing her/his info in the new file
        }
        else
        {
            fprintf(tempFile, "%s %s %s %d\n", file_name, file_password,file_ID,file_level);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt"); // delet main file
    rename("temp.txt", "users.txt"); // chang name
 
}

void deleteUserf(struct User** head, char* ToRemove) {
    if (*head == NULL) {
        printf("Error: List is empty. Cannot delete.\n");
        return;
    }

    struct User* current = *head;
    struct User* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->Name, ToRemove) == 0) {
            if (prev == NULL) {
                // If the node to delete is the first node
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("User %s deleted successfully.\n", ToRemove);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("User %s not found.\n", ToRemove);
}
struct User* LoadUserInfoFromFile(char* strFileName) { 
    struct User tmp, *pHead = NULL, *pNewItem, *pLastItem; 
    FILE* file;

    file = fopen(strFileName, "r"); 

    if (file == NULL) { 
        return NULL; 
    }

    while (fread(&tmp, sizeof(struct User), 1, file) > 0) {
        pNewItem = (struct User*)malloc(sizeof(struct User)); 
        pNewItem->pBefor = pNewItem->next = NULL; 
        pNewItem->level = tmp.level;

        strcpy(pNewItem->pass, tmp.pass); 
        strcpy(pNewItem->Name, tmp.Name); 
        strcpy(pNewItem->ID, tmp.ID);

        if (pHead == NULL) { 
            pLastItem = pHead = pNewItem; 
        } else { 
            pNewItem->pBefor = pLastItem; 
            pLastItem->next = pNewItem; 
            pLastItem = pNewItem; 
        }
    }

    fclose(file); 
    return pHead;
}


//play function
void AddArray1(int x,int y,int Mc,int back)
{
                 
	if( tmp_map1[y][x] == 'p' || tmp_map1[y][x] == ' ' )
	{
		tmp_map1[y][x] = '#';
	    struct walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = Mc;
		tmp.back = back;
		BFSArray.push_back( tmp );   //ezafeh kardan be vector
	}
}

void AddArray2(int x,int y,int Mc,int back)
{
                 
	if( tmp_map2[y][x] == 'p' || tmp_map2[y][x] == ' ' )
	{
		tmp_map2[y][x] = '#';
	    struct walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = Mc;
		tmp.back = back;
		BFSArray.push_back( tmp );   //ezafeh kardan be vector
	}
}

void AddArray3(int x,int y,int Mc,int back)
{
                 
	if( tmp_map3[y][x] == 'P' || tmp_map3[y][x] == ' ' )
	{
		tmp_map3[y][x] = '#';
	    struct walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = Mc;
		tmp.back = back;
		BFSArray.push_back( tmp );   //ezafeh kardan be vector
	}
}

void AddArray4(int x,int y,int Mc,int back)
{
	if(tmp_map4[y][x]=='p' || tmp_map4[y][x]==' ')
	{
		tmp_map4[y][x]='#';
		struct walk tmp;
		tmp.x=x;
		tmp.y=y;
		tmp.walk_count=Mc;
		tmp.back=back;
		BFSArray.push_back(tmp);
		
	}
}

void AddArray5(int x,int y,int Mc,int back)
{
	if(tmp_map5[y][x]=='p' || tmp_map5[y][x]==' ')
	{
		tmp_map5[y][x]='#';
		struct walk tmp;
		tmp.x=x;
		tmp.y=y;
		tmp.walk_count=Mc;
		tmp.back=back;
		BFSArray.push_back(tmp);
		
	}
}


void Class1()
{
    class entity {
public:
	entity( int x, int y ){ //mojood    //tabeh sazandeh
		this ->x = x; 
		this ->y = y;
	}

	void move_x( int p ){
		if( map1[y][x+p] == ' ' ||  map1[y][x+p] == '@' ) //agh jelosh khali bood  (divar nabood)
		 x += p;
	}

	void move_y( int p ){
		if( map1[y+p][x] == ' ' || map1[y+p][x] == '@' ) 
		y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x()
	{ 
		return x; 
	}
	int get_y()
	{ 
        return y;
    }

	void draw( char p )
	{
		map1[x][y] = p;
		gotoxy( x, y );
	    printf( "%c", p );
	}
    private:
	int x;
	int y;
};

}

void Class2()
{
    class entity {
public:
	entity( int x, int y ){ //mojood    //tabeh sazandeh
		this ->x = x; 
		this ->y = y;
	}

	void move_x( int p ){
		if( map2[y][x+p] == ' ' || map2[y][x+p] == '@' ) //agh jelosh khali bood  (divar nabood)
		 x += p;
	}

	void move_y( int p ){
		if( map2[y+p][x] == ' ' || map2[y+p][x] == '@' ) 
		y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x()
	{ 
		return x; 
	}
	int get_y()
	{ 
        return y;
    }

	void draw( char p )
	{
		map2[x][y] = p;
		gotoxy( x, y );
	    printf( "%c", p );
	}

private:
	int x;
	int y;
};
}

void Class3()
{
    class entity {
public:
	entity( int x, int y ){ //mojood    //tabeh sazandeh
		this ->x = x; 
		this ->y = y;
	}

	void move_x( int p ){
		if( map3[y][x+p] == ' '  ||  map3[y][x+p] == '@') //agh jelosh khali bood  (divar nabood)
		 x += p;
	}

	void move_y( int p ){
		if( map3[y+p][x] == ' ' ||  map3[y+p][x] == '@') 
		y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x()
	{ 
		return x; 
	}
	int get_y()
	{ 
        return y;
    }

	void draw( char p )
	{
		map3[x][y] = p;
		gotoxy( x, y );
	    printf( "%c", p );
	}

     private:
	  int x;
	  int y;
        };


}

void Class4()
{
    class entity {
public:
	entity( int x, int y ){ //mojood    //tabeh sazandeh
		this ->x = x; 
		this ->y = y;
	}

	void move_x( int p ){
		if( map4[y][x+p] == ' '  ||  map4[y][x+p] == '@') //agh jelosh khali bood  (divar nabood)
		 x += p;
	}

	void move_y( int p ){
		if( map4[y+p][x] == ' ' ||  map4[y+p][x] == '@'  ) 
		y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x()
	{ 
		return x; 
	}
	int get_y()
	{ 
        return y;
    }

	void draw( char p )
	{
		map4[x][y] = p;
		gotoxy( x, y );
	    printf( "%c", p );
	}

     private:
	  int x;
	  int y;
        };


}

void Class5()
{
    class entity {
public:
	entity( int x, int y ){ //mojood    //tabeh sazandeh
		this ->x = x; 
		this ->y = y;
	}

	void move_x( int p ){
		if( map5[y][x+p] == ' '  ||  map5[y][x+p] == '@') //agh jelosh khali bood  (divar nabood)
		 x += p;
	}

	void move_y( int p ){
		if( map5[y+p][x] == ' ' ||  map5[y+p][x] == '@' ) 
		y += p;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x()
	{ 
		return x; 
	}
	int get_y()
	{ 
        return y;
    }

	void draw( char p )
	{
		map5[x][y] = p;
		gotoxy( x, y );
	    printf( "%c", p );
	}

     private:
	  int x;
	  int y;
        };


}

void FindWay1(int zx,int zy,int x,int y)
{
    memcpy( tmp_map1, map1, sizeof(map1) );       //rikhtan etelaat
	BFSArray.clear();   //har chi to vector zakhireh shodeh bood paak kard     |  paak |  paak |...|
	struct walk tmp;
	tmp.x = zx;
	tmp.y = zy;
	tmp.walk_count = 0;
	tmp.back = -1; //manzor==(noghteh aghazin hastim va ghableh oon noghteh nabodeh)
	BFSArray.push_back( tmp );  //ezafeh kardan be tah vector

	int i = 0;
	while( i < BFSArray.size() ){ //ta zaman khali shodan BFSArray halgheh edameh darad
		if( BFSArray[i].x == x && BFSArray[i].y == y ){   //dar sorat residan beh  noghat  maghsad
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}
        //barayeh ezafeh kardan ya berooz kardan noghat mojaver dar jostoojoo pahna 
		AddArray1( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray1( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray1( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray1( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}
  
	BFSArray.clear();  //paak kardan vaseh dafaat badi
}

void FindWay2(int zx,int zy,int x,int y)
{
    memcpy( tmp_map2, map2, sizeof(map2) );       //rikhtan etelaat
	BFSArray.clear();   //har chi to vector zakhireh shodeh bood paak kard     |  paak |  paak |...|
	struct walk tmp;
	tmp.x = zx;
	tmp.y = zy;
	tmp.walk_count = 0;
	tmp.back = -1; //manzor==(noghteh aghazin hastim va ghableh oon noghteh nabodeh)
	BFSArray.push_back( tmp );  //ezafeh kardan be tah vector

	int i = 0;
	while( i < BFSArray.size() ){ //ta zaman khali shodan BFSArray halgheh edameh darad
		if( BFSArray[i].x == x && BFSArray[i].y == y ){   //dar sorat residan beh  noghat  maghsad
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}
        //barayeh ezafeh kardan ya berooz kardan noghat mojaver dar jostoojoo pahna 
		AddArray2( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray2( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray2( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray2( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}

	BFSArray.clear();
}
void FindWay3(int zx,int zy,int x,int y)
{
    memcpy( tmp_map3, map3, sizeof(map3) );       //rikhtan etelaat
	BFSArray.clear();   //har chi to vector zakhireh shodeh bood paak kard     |  paak |  paak |...|
	struct walk tmp;
	tmp.x = zx;
	tmp.y = zy;
	tmp.walk_count = 0;
	tmp.back = -1; //manzor==(noghteh aghazin hastim va ghableh oon noghteh nabodeh)
	BFSArray.push_back( tmp );  //ezafeh kardan be tah vector

	int i = 0;
	while( i < BFSArray.size() ){ //ta zaman khali shodan BFSArray halgheh edameh darad
		if( BFSArray[i].x == x && BFSArray[i].y == y ){   //dar sorat residan beh  noghat  maghsad
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}
        //barayeh ezafeh kardan ya berooz kardan noghat mojaver dar jostoojoo pahna 
		AddArray3( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray3( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray3( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray3( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}

	BFSArray.clear();
}

void FindWay4(int zx,int zy,int x,int y)
{
    memcpy( tmp_map4, map4, sizeof(map4) );       //rikhtan etelaat
	BFSArray.clear();   //har chi to vector zakhireh shodeh bood paak kard     |  paak |  paak |...|
	struct walk tmp;
	tmp.x = zx;
	tmp.y = zy;
	tmp.walk_count = 0;
	tmp.back = -1; //manzor==(noghteh aghazin hastim va ghableh oon noghteh nabodeh)
	BFSArray.push_back( tmp );  //ezafeh kardan be tah vector

	int i = 0;
	while( i < BFSArray.size() ){ //ta zaman khali shodan BFSArray halgheh edameh darad
		if( BFSArray[i].x == x && BFSArray[i].y == y ){   //dar sorat residan beh  noghat  maghsad
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}
        //barayeh ezafeh kardan ya berooz kardan noghat mojaver dar jostoojoo pahna 
		AddArray4( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray4( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray4( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray4( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}

	BFSArray.clear();
}

void FindWay5(int zx,int zy,int x,int y)
{
    memcpy( tmp_map5, map5, sizeof(map5) );       //rikhtan etelaat
	BFSArray.clear();   //har chi to vector zakhireh shodeh bood paak kard     |  paak |  paak |...|
	struct walk tmp;
	tmp.x = zx;
	tmp.y = zy;
	tmp.walk_count = 0;
	tmp.back = -1; //manzor==(noghteh aghazin hastim va ghableh oon noghteh nabodeh)
	BFSArray.push_back( tmp );  //ezafeh kardan be tah vector

	int i = 0;
	while( i < BFSArray.size() ){ //ta zaman khali shodan BFSArray halgheh edameh darad
		if( BFSArray[i].x == x && BFSArray[i].y == y ){   //dar sorat residan beh  noghat  maghsad
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}
        //barayeh ezafeh kardan ya berooz kardan noghat mojaver dar jostoojoo pahna 
		AddArray5( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray5( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray5( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray5( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );
		i++;
	}
  
	BFSArray.clear();  //paak kardan vaseh dafaat badi
}

void ShowMap1()
{
   
    for(int i=0;i<5;i++)
    {
        printf("%s\n",map1[i]);
    }
    
}


void ShowMap2()
{    
    
  

    for(int i=0;i<8;i++)
    {
        printf("%s\n",map2[i]);
    }
}

void ShowMap3()
{   
      for(int i=0;i<10;i++)
    {
        printf("%s\n",map3[i]);
    }

}

void ShowMap4()
{ 
	//FILE *file=fopen("GoldenMap","r");
     for(int i=0;i<18;i++)
    printf("%s\n",map4[i]);
	 //fclose(file);
}	

void ShowMap5()
{
    for(int i=0;i<18 ;i++)
    {
        printf("%s\n",map5[i]);
    }
}
  
////tabeh namayesh mokhtasat 
//chon marboot be mokhtasat hast bayad type short basheh 
void gotoxy(short x,short y)
{
    HANDLE NewPostion =GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position= { x , y };
    SetConsoleCursorPosition( NewPostion, Position ) ;

}


//offer function
void welcome()
{   
	 //_setmode(_fileno(stdout), _O_U16TEXT);
     //wcout << L"\u2764";
	  system("Color D0");
	 printf("%c\t",char(3));
	 printf("%c\t",char(1));
	 printf("%c\t",char(2));
     printf("%c\t",char(3));
	 printf("%c\t",char(1));
	 printf("%c\t",char(2));
	 printf("%c\t",char(4));
	 printf("%c\t",char(5));
	 printf("%c\t",char(6));
     printf("%c\t",char(7));
	 printf("%c\t",char(8));
	 printf("%c\t",char(9));
     printf("%c\t",char(10));
	 printf("%c\t",char(11));
	 printf("%c\t",char(12));
     printf("%c\t",char(13));
	 printf("%c\t",char(14));
	 printf("%c\t",char(15));
     printf("%c\t",char(3));
	 printf("%c\t",char(1));
	 printf("%c\t",char(2));
     printf("%c\t",char(3));
	 printf("%c\t",char(1));
	 printf("%c\t",char(2));
	 printf("%c\t",char(4));
	 printf("%c\t",char(5));
	 printf("%c\t",char(6));
     printf("%c\t",char(7));
	 printf("%c\t",char(8));
	 printf("%c\t",char(9));
     printf("%c\t",char(10));
	 printf("%c\t",char(11));
	 printf("%c\t",char(12));
     printf("%c\t",char(13));
	 printf("%c\t",char(14));
	 printf("%c\n",char(15));
     printf("%c\n",char(250));


    

	printf("\t\t\033[1;37mWelcome to PAC_MAN game\n\t\t\033[1;33mI hope you enjoy playing\n\t\t\033[1;34mThis game is equipped with the creator's password\n\t\t\033[1;32m Please enter the password to enter the game :\n");
	 printf("\033[1;37m_______________________________________________________________________________________________________________________\n");
}
void help()
{
    cout << "\033[1;36m\nEnter 1 for delete a Player";
    cout<<  "\033[1;34m\nEnter 2 if you want to delet all Users";
    cout << "\033[1;36m\nEnter 3 to print list of Users";
    cout << "\033[1;34m\nEnter 4 to print a player ";
    cout << "\033[1;36m\nEnter 0 if you want to start playing : ";
}

void play()
{
   printf("\033[1;31mInstruction:\n\033[1;33m1. Arrow Keys to move your hero\n\033[1;33m2. Eat the dots produced by the Eater to gain poins\n\033[1;33m3. Don't get caught by the Eater\n4. If you want to stop the game while playing,Press the home key to return to the game screen\n\n");  
   printf("\033[1;32mH -> Hard\n\033[1;32mN -> Normal\n\033[1;32mE -> Easy\n\033[1;32mG -> GoldenMap\nB -> Back to the main screen\nR -> Return to previously selected map\n\nInput : \n");  
    
   
}
void log()
{   printf("\033[1;35mIf you are not a member of the game before, please register to enter\n");
    printf("\033[1;34m1. Login\n \033[1;32m2. Register\n\033[1;33mEnter your choice:\n ");
}

void speed()
{
    printf("\n\033[1;31mEnter 4 for fast speed ghosts\n");
	printf("\n\033[1;33mEnter 5 for normal speed ghosts\n");
	printf("\nEnter 7 for slow speed ghosts\n");
	
}



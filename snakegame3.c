#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void Start();
void outer();
void food1();
void food2();
void move1();
void bend();
void Right();
void Left();
void Up();
void Down();
void bendDown();
void bendUp();
void bendRight();
void bendLeft();
void clearscreen();
void Print();
void gotoxy(int, int);
void delay(unsigned int);
void CheckExit();
void cross();
void CheckScore();
void Restart();
char* names[11][11];
void Exit();
int Score=0;
int ch1,ch2;
int bot,bot1,signal;
int a=100,b=9,x;
int length=10,len=0;
int Life=3;
char enter;
float g;
struct game
{
    int x;
    int y;
    int Direction;
};
typedef struct game game;
game food,head[1000];

void main()
{
    printf("NAME OF PLAYER :");
        scanf("%s",&names[1]);
    system("cls");
    Start();
    head[0].Direction=RIGHT;
    move1();
    getch();
}

void outer()
{
    printf("\n\n\n\n           ");
    printf("Name: %s",names[1]);
    printf("                     Life: %d",Life);
    printf("\n");
    printf("           ");
    for(int i=0;i<76;i++)
    {
         printf("_");
    }
    printf("\n");
    for(int i=0;i<29;i++)
    {
        printf("          |                                                                            |\n");
    }
        printf("          |                                                                            |");
    printf("\n");
    printf("          ");
    for(int i=0;i<78;i++)
    {
         printf("*");
    }
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void food1()
{
    repeat:
    srand(time(0));
    food.x=(rand()%(86-11 +1))+11;
    food.y=(rand()%(35-6 +1))+6;
        for(int j=0;j<length;j++){
        if(food.x==head[j].x && food.y==head[j].y)
            goto repeat;}
}
void food2()
{
    gotoxy(food.x,food.y);
    printf("X");
}
void move1()
{
    int f=0,h=0;
    g=0;
    a=100,b=9;
    system("cls");
    outer();
    head[0].Direction==RIGHT;
    int t=0;
    for(int i=length-1;i>-1;i--)
    {
        head[i].x=50+t;
        head[i].y=20;
        t++;
        if(head[i].x==86){
            f=1;
            h=i;
            break;}
    }
    do{
    if(f==1){
    f=0;
        head[h].x=head[h+1].x;
        head[h].y=head[h+1].y+1;
        head[0].Direction=DOWN;
    int n=1;
    for(int i=h-1;i>-1;i--)
    {
        head[i].x=head[h].x-n;
        head[i].y=head[h].y;
        n++;
        if(head[i].x==12)
        {
            f=1;
            h=i;
            break;
        }
    }
    head[0].Direction=LEFT;
    }

    if(f==1)
    {
    f=0;
        head[h].x=head[h+1].x;
        head[h].y=head[h+1].y+1;
        head[0].Direction=DOWN;
    int n=1;
    for(int i=h-1;i>-1;i--)
    {
        head[i].x=head[h].x+n;
        head[i].y=head[h].y;
        n++;
        if(head[i].x==86)
        {
            f=1;
            h=i;
            break;
        }
    }
    head[0].Direction=RIGHT;
    }

    }while(f==1);
    signal=0;
    Print();
    food1();
    food2();
    bend();
}
void Right()
{
    head[0].Direction=RIGHT;
    while(!kbhit()){
    clearscreen();
    for(int k=length-1;k>-1;k--)
    {
        head[k].x++;
        head[k].y=head[0].y;
    }

    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
        }
    bend();
}
void Down()
{
    head[0].Direction=DOWN;
    while(!kbhit()){
    clearscreen();
    for(int k=length-1;k>-1;k--)
    {
        head[k].y++;
        head[k].x=head[length-1].x;
    }

    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
    }
    bend();
}
void Up()
{
    head[0].Direction=UP;
    while(!kbhit()){
    clearscreen();
    for(int k=length-1;k>-1;k--)
    {
        head[k].y--;
        head[k].x=head[0].x;
    }

    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
    }
    bend();
}
void Left()
{
    head[0].Direction=LEFT;
    while(!kbhit()){
    clearscreen();
    for(int k=length-1;k>-1;k--)
    {
        head[k].x--;
        head[k].y=head[length-1].y;
    }

    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
        }
    bend();
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void bend()
{
    if(signal==0)
    {
        gotoxy(13,9);
        printf("Press any arrow key to continue>>>>");
    }

    ch1 = getch();
    ch2 = 0;
    if(signal==0){
        gotoxy(13,9);
        printf("                                   ");
        signal=1;
        food2();}
    if (ch1 == 0xE0) {
            ch2=getch();
            if(ch2==DOWN)
            {
                if(head[0].Direction==RIGHT || head[0].Direction==LEFT  || head[0].Direction==DOWN)
                    bendDown();
                if(head[0].Direction==UP)
                    bendUp();
            }
            if(ch2==RIGHT)
            {
                if(head[0].Direction==DOWN || head[0].Direction==UP || head[0].Direction==RIGHT)
                    bendRight();
                if(head[0].Direction==LEFT)
                    bendLeft();
            }
            if(ch2==LEFT)
            {
                if(head[0].Direction==DOWN || head[0].Direction==UP || head[0].Direction==LEFT)
                    bendLeft();
                if(head[0].Direction==RIGHT)
                    bendRight();
            }
            if(ch2==UP)
            {
                if(head[0].Direction==RIGHT || head[0].Direction==LEFT || head[0].Direction==UP)
                    bendUp();
                if(head[0].Direction==DOWN)
                    bendDown();
            }
}
}
void Print()
{
        for(int l=length-1;l>0;l--)
        {
            gotoxy(head[l].x,head[l].y);
            printf("*");
        }
        gotoxy(head[0].x,head[0].y);
        printf("O");
        gotoxy(10,38);
        printf("%d",length);
}
void CheckExit()
{
    unsigned int f;
    for(int l=length-1;l>0;l--)
    {
        if(head[0].x==head[l].x && head[0].y==head[l].y)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
            Life--;
            if(Life==0){
            Exit();
            }
            Restart();
            move1();
    }

}
void CheckScore()
{
        if(food.x==head[0].x && food.y==head[0].y)
        {
            int s=food.x;
            int d=food.y;
            food1();
            Score++;
            length1();
            food2();
            if(s>food.x)
                a=s-food.x;
            else if(s<food.x)
                a=food.x-s;
            if(d<food.y)
                b=food.y-d;
            else if(d>food.y)
                b=d-food.y;
            len=0;
        }
        x=a+b;
        if(len>x)
        g+=0.1;
            {
            gotoxy(78,4);
            printf("Score:%2d",Score);
            }
       if(g>2.0){
            length1();
       g=0;}
}
void Start()
{
    printf("\n\n\n\n           ");
    printf("Name: %s",names[1]);
    printf("                     Life: %d",Life);
    printf("                            Score: %d",Score);
    printf("\n");
    printf("           ");
    for(int i=0;i<76;i++)
    {
         printf("_");
    }
    printf("\n");
    for(int i=0;i<30;i++)
    {
        if(i==15)
        printf("          |           Welcome to the mini Snake game.(press any key to continue)       |\n");
        else
        printf("          |                                                                            |\n");
    }
        printf("          |                                                                            |");
    printf("\n");
    printf("          ");
    for(int i=0;i<78;i++)
    {
         printf("*");
    }
    printf("\n \n");
    getch();
    system("cls");
    printf("\n\n\n\n           ");
    system("cls");
    printf("\n\n\n\n           ");
    printf("Name: %s",names[1]);
    printf("                     Life: %d",Life);
    printf("                            Score: %d",Score);
    printf("\n");
    printf("           ");
    for(int i=0;i<76;i++)
    {
         printf("_");
    }
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("          |                                                                            |\n");
    }
        printf("          | Game instructions:                                                         |\n");
        printf("          | -> Use arrow keys to move the snake.                                       |\n");
        printf("          | -> You will be provided foods at the several coordinates of the screen     |\n");
        printf("          |  which you have to eat. Everytime you eat a food the length of the snake   |\n");
        printf("          |  will be increased by 1 element and thus the score.                        |\n");
        printf("          | -> Here you are provided with three lives. Your life will decrease as you  |\n");
        printf("          |  hit the wall or snake's body.                                             |\n");
        printf("          | -> You can pause the game in its middle by pressing any key. To continue   |\n");
        printf("          |  the paused game press any other key once again.                           |\n");
        printf("          | -> You should use shortest path while approaching towards your food.       |\n");
        printf("          |  Otherwise snake length will be increased.                                 |\n");
        printf("          | -> If you want to exit press esc.                                          |\n");
        printf("          | Press any key to play game...                                              |\n");
    for(int i=18;i<31;i++)
    {
        printf("          |                                                                            |\n");
    }
    printf("          ");
    for(int i=0;i<78;i++)
    {
         printf("*");
    }
    printf("\n\nPress any key to play game...");
    getch();
    system("cls");
}
void clearscreen()
{
    bot=head[length-1].x;
    bot1=head[length-1].y;
    gotoxy(head[length-1].x,head[length-1].y);
    printf(" ");
}
void bendDown()
{
    int j=1;
    head[0].Direction=DOWN;
    while(!kbhit()){
    do{
    clearscreen();
    for(int k=length-1;k>-1+j;k--)
    {
        head[k].x=head[k-1].x;
        head[k].y=head[k-1].y;
    }
    int n=j;
    for(int k=1;k<j+1;k++)
    {
        head[-1+k].x=head[j].x;
        head[-1+k].y=head[j].y+n;
        n--;
    }
    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
    j++;
    if(!kbhit()==0)
    break;
    }while(j<length);
    break;
    }
    if(j==length)
    Down();
    else
    bend();
}
void bendRight()
{
    int j=1;
    head[0].Direction=RIGHT;
    while(!kbhit()){
    do{
    clearscreen();
    for(int k=length-1;k>-1+j;k--)
    {
        head[k].x=head[k-1].x;
        head[k].y=head[k-1].y;
    }
    int n=j;
    for(int k=1;k<j+1;k++)
    {
        head[-1+k].x=head[j].x+n;
        n--;
        head[-1+k].y=head[j].y;
    }

    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
    j++;
    if(!kbhit()==0)
        break;
    }while(j<length);
    break;
    }
    if(j==length)
        Right();
    else
        bend();
}
void bendLeft()
{
    int j=1;
    head[0].Direction=LEFT;
    while(!kbhit()){
    do{
    clearscreen();
    for(int k=length-1;k>-1+j;k--)
    {
        head[k].x=head[k-1].x;
        head[k].y=head[k-1].y;
    }
    int n=j;
    for(int k=1;k<j+1;k++)
    {
        head[-1+k].x=head[j].x-n;
        n--;
        head[-1+k].y=head[j].y;
    }

    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
    j++;
    if(!kbhit()==0)
        break;
    }while(j<length);
    break;
    }
    if(j==length)
        Left();
    else
        bend();
}
void bendUp()
{
    int j=1;
    head[0].Direction=UP;
    while(!kbhit()){
    do{
    clearscreen();
    for(int k=length-1;k>-1+j;k--)
    {
        head[k].x=head[k-1].x;
        head[k].y=head[k-1].y;
    }
    int n=j;
    for(int k=1;k<j+1;k++)
    {
        head[-1+k].x=head[j].x;
        head[-1+k].y=head[j].y-n;
        n--;
    }
    len++;
    CheckExit();
    cross();
    CheckScore();
    Print();
    delay(70);
    j++;
    if(!kbhit()==0)
        break;
    }while(j<length);
    break;
    }
    if(j==length)
        Up();
    else
        bend();
}
void Exit()
{
    getch();
    system("cls");
    printf("Well Done %s.\n\nYour score is %d and length is %d\n",names[1],Score,length);
    printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
    getch();
    exit(0);
}
void Restart()
{
    system("cls");
    printf("\n\n\n\n           ");
    printf("Name: %s",names[1]);
    printf("\n");
    printf("           ");
    for(int i=0;i<76;i++)
    {
         printf("_");
    }
    printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("          |                                                                            |\n");
    }
        printf("          |                  ******************************************                |\n");
        printf("          |                  | Score: %2d                              |                |\n",Score);
        printf("          |                  | Lifes Left: %d                          |                |\n",Life);
        printf("          |                  |                                        |                |\n");
        printf("          |                  | Press Enter to continue.....           |                |\n");
        printf("          |                  |                                        |                |\n");
        printf("          |                  ******************************************                |\n");
    for(int i=18;i<31;i++)
        printf("          |                                                                            |\n");
    printf("          ");
    for(int i=0;i<78;i++)
    {
         printf("*");
    }
    printf("\n \n");
    enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
}
void length1()
{
    length++;
    head[length-1].x=bot;
    head[length-1].y=bot1;
}
void cross()
{
     if(head[0].x==87)
    {
        clearscreen();
        head[0].x=86;
        for(int k=length-1;k>0;k--)
        {
            head[k].x=head[k-1].x;
            head[k].y=head[k-1].y;
        }
        head[0].x=11;

        len++;
        CheckScore();
        CheckExit();
        cross();
        Print();
        delay(70);
        bendRight();
    }
    if(head[0].x==10)
    {
        clearscreen();
        head[0].x=11;
        for(int k=length-1;k>0;k--)
        {
            head[k].x=head[k-1].x;
            head[k].y=head[k-1].y;
        }
        head[0].x=86;

        len++;
        CheckScore();
        CheckExit();
        cross();
        Print();
        delay(70);
        bendLeft();
    }
    if(head[0].y==36)
    {
        clearscreen();
        head[0].y=35;
        for(int k=length-1;k>0;k--)
        {
            head[k].x=head[k-1].x;
            head[k].y=head[k-1].y;
        }
        head[0].y=6;

        len++;
        CheckScore();
        CheckExit();
        cross();
        Print();
        delay(70);
        bendDown();
    }
    if(head[0].y==5)
    {
        clearscreen();
        head[0].y=6;
        for(int k=length-1;k>0;k--)
        {
            head[k].x=head[k-1].x;
            head[k].y=head[k-1].y;
        }
        head[0].y=35;
        len++;
        CheckScore();
        CheckExit();
        cross();
        Print();
        delay(70);
        bendUp();
    }
}

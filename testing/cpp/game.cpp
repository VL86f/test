#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <tuple>
using namespace std;

void one_player (int pile,int pile_max,int sum,int pro)
{int z,x;
for( x=1;pile<pile_max;x++)
{clear();
printw("Stones: ");
printw("%d\n" ,pile);
if(x%2!=0)
{printw("You turn\n");
z=getch();}
else
{printw("Computer turn\n");
refresh();
sleep(2);
if(z==1)
z=49;
else
z=50;}
if(z==49)
pile=pile+sum;
else if(z==50)
pile=pile*pro;
else
{x--;}
printw("Now in a heap of: ");
printw("%d" ,pile);
printw(" stones out of ");
printw("%d\n", pile_max);
refresh();
sleep(2);

if((pile>=pile_max)&&(x%2!=0))
sleep(3);
clear();}

if(x%2==0)
printw("You win. \n");
else
printw("Computer win. \n");
refresh();
sleep(1);
printw("In a heap: ");
printw("%d", pile);
printw(" stones.\n");
refresh();
sleep(2);
printw("Press any key to continue.\n");
getch();
clear();}

void two_players (int pile,int pile_max,int sum,int pro)
{int z,x;
for( x=1;pile<pile_max;x++)
{printw("Stones: ");
printw("%d\n" ,pile);
if(x%2!=0)
printw("Player 1 turn\n");
else
printw("Player 2 turn\n");
z=getch();
if(z==49)
pile=pile+sum;
else if(z==50)
pile=pile*pro;
else
{x--;}
if(pile>=pile_max)
sleep(4);
clear();}
if(x%2==0)
printw("Player 1 win. \n");
else
printw("Player 2 win. \n");
refresh();
sleep(1);
printw("In a heap: ");
printw("%d", pile);
printw(" stones.\n");
refresh();
sleep(2);
printw("Press any key to continue.\n");
getch();
clear();}


auto manual_mode()
{int a,b,c,d;
echo();
printw("1. The number of stones in the heap that must be reached or exceeded.\n");
scanw("%d",&a);
printw("2. How many stones can be thrown into a pile? \n");
scanw("%d",&b);
printw("3. How many times can you increase the pile? \n");
scanw("%d",&c);
printw("4. The initial amount of stones in the heap? \n");
scanw("%d",&d);
noecho();
clear();
tuple <int, int, int, int> ex;
return make_tuple(a,b,c,d);
}




void random_mode(){
int a,b,c,d,z,j=0;
bool two=false;
while(j==0)
{printw("Who do you want to play with?\n");
printw("1. With a computer\n");
printw("2. With the second player\n");
z=getch();
clear();
switch(z)
{case 50:
 {two=true;
 j=1;
 break;}
 case 49:
 {
 j=1;
 break;}
 default:
 {clear();
 break;}}}
z=0;
while(z==0)
{a=rand() % 500 +1;
b=rand() % 10 +1;
c=rand() % 10 +1;
d=rand() % a/4 +1;
c++;
j=0;
 while(j==0)
{printw("The game will end when there are %d",a);
printw(" stones in the heap \n");
printw("You can add to the heap %d",b);
printw(" stones.\n");
printw("Or increase the pile by y %d",c);
printw(" times\n");
printw("Now in a pile of %d",d);
printw(" stones\n");
refresh();
sleep(2);
printw("\nPress Enter to continue.\n");
printw("Or, Press ESC to go to the main menu.\n");
printw("Or, Press m if you want to enter data manually. \n");
printw("Or, Press r to generate other data.\n");
z=getch();
clear();
switch(z)
{case 109:
{auto cort=manual_mode();
a=get<0>(cort);
b=get<1>(cort);
c=get<2>(cort);
d=get<3>(cort);
break;}
case 10:
{j=1;
break;}
case 27:
{z=1;
j=1;
break;}
case 114:
{j=1;
z=0;}
}
clear();}}
if(z==10)
{if(two==true)
two_players(d,a,b,c);
else
one_player(d,a,b,c);
}}

int main()
{initscr();
keypad(stdscr, true);
noecho();
int z;
bool test =false;
srand(time(0));
while(test==false)
{printw("Welcome to the game for Linux\n");
printw("To find out the rule of the game, press 1\n");
printw("To start the game click 2\n");
printw("To exit the game now press 3\n");
z=getch();
switch(z)
{case 50:
 {clear();
random_mode();
 break;}
 case 49:
 {printw("Excuse me. But the rules of the game will be added later.\n");
 refresh();
 sleep(1);
 printw("Press any key to continue.\n");
 getch();
 clear();
 break;}
 case 64:
 {clear();
  printw("This feature has been reduced. \n");
  refresh();
  sleep(2);
  clear();
 break;}
 case 51:
 {test=true;
 break;}
 default:
 {clear();
 break;}}}
endwin();
return 0;}

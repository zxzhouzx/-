#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
 char map[10][11]=
 {
	  {"**########"},//*表示路  #表示障碍   E表示出口
	  {"#**#***#*#"},
	  {"#**#***#*#"},
	  {"#****##**#"},
	  {"#*####***#"},
	  {"#***#***##"},
	  {"#*#***#**#"},
	  {"#*###*##*#"},
	  {"##*******E"},
	  {"##########"},
 }; 
void print_map()
{
     for(int i=0;i<10;i++)
		 puts(map[i]);
}
void show_cursor(int x,int y)
{
	COORD pos;
    pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int curX,curY;

void main()
{
	printf("按任意键开始游戏!");
	getch();
    system("cls");//清屏
   while(1)
   {
       print_map();
       show_cursor(curX,curY);
	   char t=getch(); 
      switch(t) 
	  {
		case 'a':                                                                //向左移 
			if( (curX-1)>=0 && (map[curY][curX-1]=='*'||map[curY][curX-1]=='E') )
			 curX -= 1; 
             break;
		case 'd':	                                                            //向右移          
			if((curX+1)<10 && (map[curY][curX+1]=='*'||map[curY][curX+1]=='E') )
			curX += 1; 
			break;
		case 'w':	                                                            //向上移    
			if((curY-1)>=0 && (map[curY-1][curX]=='*'||map[curY-1][curX]=='E') )
			curY -= 1;
			break;
		case 's':	                                                             //向下移    
			if( (curY+1)<10 && (map[curY+1][curX]=='*'||map[curY+1][curX]=='E') )
			curY += 1; 
			break;
		default: 
			break;
	  }
     system("cls");//清屏
     if(curY==8 && curX==9)
	 {
		printf("你已找到出口!\n游戏结束!\n");
        break;
	 }
   }
}

#include<math.h>
#include<ncurses.h>
#include<time.h>


char grid[30][100];
int leftTop = 8 , rightTop = 0 , x=10 , y=10 , slope = 1 , game=1 , dir=1 ;

void initGrid ( )
{
	int i , j;
	for (  i=0 ; i<30 ; i++ )
		for (  j=0 ; j<100 ; j++ )
			grid[i][j] = ' ';

	for (  i = 0 ; i<10 ; i++ )
	{
		grid [leftTop+i][0] = ']';
		grid [rightTop+i][99] = '[';
	}

}

void advanceBall ()
{
	if ( (y==0 || y== 99) && grid [x][y] == ' ')
			game = 0;
	else if ( grid[x][y] == ']')
		slope*=-1;
  else if ( grid[x][y] == '[')
		slope*=-1;
	else if ( x==0)
		dir = 1;
	else if ( x==29)
		dir=0;
	
	grid[x][y] = ' ';
	if (dir ==1)
	  x++;
	else
		x--;
	if ( slope == 1 )
		y++;
	else
		y--;
	grid[x][y]='o';
}



void printGrid ( )
{
	printw("%d\t%d\t%d\t%d\n",x,y,dir,slope);
	int i , j;
	for (  i=0 ; i<30 ; i++ )
	{
		for (  j=0 ; j<100 ; j++ )
		{
			if ( j==0 )
				printw("|");
			printw("%c",grid[i][j]);
			if (j==99)
				printw("|");
		}
		printw("\n");
	}
}

int main()
{
	nocbreak();
	char c , v;
	initGrid();
	initscr();
	halfdelay(1);
	printGrid();
	while (game)
	{
		v='h';
		c = getch();
		v=c;
		switch (c)
		{
			case 'w'  :
			{
				if ( leftTop!=0)
					leftTop--;
			}
			break;
			case 's':
			{
				if (leftTop!=20)
					leftTop++;
			}
			break;
			case 'p' :
			{
				if ( rightTop !=0)
					rightTop--;
			}
			break;
			case'l' :
			{
				if ( rightTop!=20)
					rightTop++;
			}
			break;
			default:
			{
      }
			break;
		}
		
		erase();
	  initGrid();
		advanceBall();
		printGrid();

  }

  getch();
	endwin();
	return 0;
}


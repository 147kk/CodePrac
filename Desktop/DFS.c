#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5


int maze[MAX_ROW][MAX_COL] = 
{
	{0, 1, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 1, 0}	
};

int visit[MAX_ROW][MAX_COL] = 
{
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1}
};

typedef struct
{
	int row;
	int col;
}point;

point stack[MAX_ROW * MAX_COL] = {0};
int stack_len = 0;



void push(point p)
{
	stack_len++;
	stack[stack_len] = p;
}

void pop(void)
{
	stack[stack_len].row = 0;
	stack[stack_len].col = 0;
	stack_len--;
}
void visited(point p)
{
	visit[p.row][p.col] = -2;
}



int main(void)
{
	point position = {0,0};
	
	for(int i = 0; i < 5; i++)
	{
		for(int k = 0; k < 5; k++)
			printf("%d",maze[i][k]);
		printf("\n");
	}
	printf("This is Maze\n\n");
	
	push(position);
	visit[0][0] = -2;
	while(0 != stack_len)
	{
		if(((MAX_ROW - 1) == position.row) && ((MAX_COL - 1) == position.col))
			break;
			
		if((position.row > 0) && (0 == maze[position.row - 1][position.col]) && (-2 != visit[position.row - 1][position.col])) /* Up */
		{
			position.row--;
			push(position);
			visited(position);
			
		}
		else if((position.row < (MAX_ROW - 1)) && (0 == maze[position.row + 1][position.col]) && (-2 != visit[position.row + 1][position.col])) /* Down */
		{
			position.row++;
			push(position);
			visited(position);
			
		}
		else if((position.col > 0) && (0 == maze[position.row][position.col - 1]) && (-2 != visit[position.row][position.col - 1])) /* Left */
		{
			position.col--;
			push(position);
			visited(position);
			
		}
		else if((position.col < (MAX_COL - 1)) && (0 == maze[position.row][position.col + 1]) && (-2 != visit[position.row][position.col + 1])) /* Right */
		{
			position.col++;
			push(position);
			visited(position);
			
		}
		else 
		{	
			pop();
			position = stack[stack_len];
		}
		
	} 
	
	if(0 == stack_len)
	{
		printf("There is No Path");
	}
	
	for(int i = 0; i < 5; i++)
	{
		for(int k = 0; k < 5; k++)
			printf("%d",visit[i][k]);
		printf("\n");
	}
	printf("This is Maze\n\n");

}


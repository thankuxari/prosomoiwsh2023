/* Knowledge Information Spread - Sample Code*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define NOTINFORMED 0
#define INFORMED 1

 
int main() 
{
	int x, y, totalNodes, totalInformedNodes, timestep;
	
	int grid[N][N]={NOTINFORMED};
	totalNodes = N*N;
	
	FILE *fptr;
	fptr = fopen("knowledge-info-spread.csv", "w"); 
	
	srand(time(NULL));
	x = rand()%N;
	y = rand()%N;

	grid[x][y]=INFORMED;
	totalInformedNodes = 1;
	timestep = 0;
	
	while(totalInformedNodes<totalNodes)
	{	
		x=rand()%N;
		y=rand()%N;
		
		if (grid[x][y]==NOTINFORMED){
			grid[x][y]=INFORMED;
			totalInformedNodes++;
		}
		
		timestep++;
		fprintf(fptr, "%d;%d\n", timestep, totalInformedNodes);
		
	}
	
	fclose(fptr);
	return 0;
}

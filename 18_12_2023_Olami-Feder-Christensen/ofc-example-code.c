#include <stdlib.h>
#include <stdio.h>
#define FOUT 0.001
#define FC 4

int main()
{
	float current[10][10], next[10][10];
	int i, j, distribution[100]={0}, t=1000000, num, min = 0, max = 4;
	FILE *fptr;

	fptr = fopen("ofc.csv", "w");

	for (i=0; i<10; i++){
		for (j=0; j<10; j++){
			double range = (max - min); 
			double div = RAND_MAX / range;
			current[i][j] = min + (rand() / div);
			next[i][j] = current[i][j];
			printf("%f\n",current[i][j]);
		}
	}
	while (t>0){
		num = 0;
		for (i=0; i<10; i++){
			for (j=0; j<10; j++){
				current[i][j] += FOUT;
				next[i][j] += FOUT;
				if (current[i][j] >= FC){
					num++;
					if (i==0)
						next[i+1][j] += 0.25*current[i][j];
					else if (i==9)
						next[i-1][j] += 0.25*current[i][j];
					else{
						next[i+1][j] += 0.25*current[i][j];
						next[i-1][j] += 0.25*current[i][j];
					}
					if (j==0)
						next[i][j+1] += 0.25*current[i][j];
					else if (j==9)
						next[i][j-1] += 0.25*current[i][j];
					else{
						next[i][j+1] += 0.25*current[i][j];
						next[i][j-1] += 0.25*current[i][j];
					}
					next[i][j] = 0;
				}
			}
		}
		for (i=0; i<10; i++){
			for (j=0; j<10; j++){
				current[i][j] = next[i][j];
			}
		}
		if(num > 0)
			distribution[num-1]++;
		t--;
	}
	for (i=0; i<100; i++){
		fprintf(fptr,"%d, %d\n", i+1, distribution[i]);
	}
	fclose(fptr);
	return 0;
}


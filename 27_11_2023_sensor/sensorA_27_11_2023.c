#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 //Αριθμός sensors


int main(){

    srand(time(NULL));

    FILE *fptr;

    fptr = fopen("sensor.txt","w");

    //Δισδιάστατος πίνακας N * N διαστάσεις
    int sensor[N][N] = {{0},{0}};

    //Random sensor κάνει receive το information
    sensor[rand()%N][rand()%N] = 1;

    //Αύξηση του Counter των informed
    int informedCounter = 1;

    int step = 0;

    //Διάδοση πληροφορίας στους άλλους sensors
    while(informedCounter < N*N){
        int rand1 = rand()%N;
        int rand2 = rand()%N;
        if(sensor[rand1][rand2]==0){
            sensor[rand1][rand2]= 1;
            informedCounter++;
        }
        step++;
        
        //printf("Num of informed sensor on step(%d): %d \n",step,informedCounter);
        fprintf(fptr,"Num of informed sensor on step(%d) %d \n",step,informedCounter);
    }
    return 0;
}
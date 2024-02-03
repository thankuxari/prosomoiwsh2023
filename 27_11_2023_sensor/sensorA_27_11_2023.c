#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFORMED 1 // Κατάσταση 1  = ο sensor είναι informed
#define NOTINFORMED 0 // Κατάσταση 0 = Ο sensor δεν είναι informed
#define N 50 //Αριθμός sensors


int main(){

    srand(time(NULL));

    FILE *fptr;

    fptr = fopen("sensor.txt","w");

    //Δισδιάστατος πίνακας N * N διαστάσεις
    int sensor[N][N] = {NOTINFORMED};

    //Random sensor κάνει receive το information
    sensor[rand()%N][rand()%N] = INFORMED;

    //Αύξηση του Counter των informed
    int informedCounter = 1;

    int step = 0;

    //Διάδοση πληροφορίας στους άλλους sensors
    while(informedCounter < N*N){
        int rand1 = rand()%N;
        int rand2 = rand()%N;
        if(sensor[rand1][rand2]==NOTINFORMED){
            sensor[rand1][rand2]= INFORMED;
            informedCounter++;
        }
        step++;
        
        //printf("Num of informed sensor on step(%d): %d \n",step,informedCounter);
        fprintf(fptr,"%d;%d \n",step,informedCounter);
    }
    return 0;
}
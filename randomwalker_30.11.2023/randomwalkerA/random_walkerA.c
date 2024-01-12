#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STEPS 50 //Αριθμός βημάτων του περιπατητή

int main(){

    srand(time(NULL));

    //Initialize file pointer
    FILE *fptr;

    //Αρχικό Position του περιπατητή
    int STARTING = 500; 

    //Άνοιγμα pointer για γράψημο στο randomwalkerA.txt αρχείο
    fptr = fopen("randomwalkerA.txt","w");

    //Calculate τα Steps του περιπατητή
    for(int i = 0; i < STEPS; ++i)
    {
        int nextstep = rand() % 2;


        // 0 = Αριστερά    1 = Δεξία
        if(nextstep == 0)
        {
            STARTING--;
        }else if(nextstep == 1)
        {
            STARTING++;
        }
        
        //Uncomment για κάθε step του περιπατητή
        //printf("At step:%d: Position: %d \n",i,STARTING);
    }
    
    //Print το Final Step του περιπατητή
    fprintf(fptr,"Final Position:%d",STARTING);

    return 0;

}

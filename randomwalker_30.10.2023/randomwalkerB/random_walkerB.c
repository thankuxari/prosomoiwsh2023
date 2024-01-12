#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STEPS 10 //Αριθμός βημάτων του περιπατητή
#define WALKERS 1000 //Αριθμός περιπατητών

int main(){

    srand(time(NULL));

    //Initialize file pointer
    FILE *fptr;

    //Αρχικό Position του περιπατητή
    int STARTING = 500; 

    //Άνοιγμα pointer για γράψημο στο randomwalkerA.txt αρχείο
    fptr = fopen("randomwalkerB.txt","w");

   //Loop για κάθε έναν περιπατητή
    for(int j = 0; j < WALKERS; ++j){

        //Initialise το αρχικό position του περιπατητή για κάθε έναν περιπατητή που μπαίνει στην loop
        STARTING = 500;

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
            //printf("Walker:%d At step:%d: Position: %d \n",j,i,STARTING);
        }

        //Print το Final Step του περιπατητή
        fprintf(fptr,"Walker:%d Final Position:%d \n",j,STARTING);
    }
    
    return 0;

}

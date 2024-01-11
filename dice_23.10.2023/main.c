#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROLLS 100000 //Initialize τις πόσες φορές θα επαναληφθεί η ζαρία

int main(){
    srand(time(NULL));

    //Initialize file pointer
    FILE *fptr;

    //Άνοιγμα pointer για γράψημο στο dice.txt αρχείο
    fptr = fopen("dice.txt","w");

    //Πίνακας που κάνει store τα faces του ζαριού
    int result[6] = {0};

    //Roll την ζαρία και αποθήκευση του αποτελέσματος στον πίνακα
    for(int i = 1;i <= ROLLS;++i)
    {
        int roll = rand() % 6 + 1;

        //Αύξηση του counter(πίνακα) για κάθε face του ζαριού
        result[roll - 1]++;
    }


    //Print το output για κάθε face στο file
    for(int i = 1;i <= 6;++i)
    {
        fprintf(fptr,"%d : %d \n",i,result[i - 1]);
    }
    fclose(fptr);
    return 0;
}
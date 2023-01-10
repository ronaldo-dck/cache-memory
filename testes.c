#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

char mode = 't';
char chamada[100];
char ordem[5];



for(int j = 0; j < 20; j++)
{
    if(j%2)
        mode = 'o';

        
        sprintf(ordem, "%d", j);
        sprintf(chamada, "./cacheMemory %s %s %s %s %c",ordem,ordem,ordem,ordem, mode);
        system(chamada);

}




}
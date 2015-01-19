/*
   
    gcc -I./includes -c hfcal.c -o hfcal.o
    gcc -I./includes -c elliptical.c -o elliptical.o
    
            //ligação estática 
            ar -rcs ./libs/libhfcal.a hfcal.o
            gcc elliptical.o -L./libs -lhfcal -o elliptical
            ./elliptical

                //código independente de posição
                gcc -I./includes -fPIC -c hfcal.c -o hfcal.o

            //ligação dinâmica
            gcc -shared hfcal.o -o ./libs/libhfcal.so
            gcc elliptical.o -L./libs -lhfcal -o elliptical 
            export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs
            ./elliptical
*/



#include <stdio.h>
#include <hfcal.h>

int main (void)
{
    display_calories (115.2, 11.3, 0.79);
}

// binary search: iterative
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NMBRS 1000000

long int bin_it(long int k, const long int* a, long int l, long int r);
/* Trying to find the integer 'k' in the array 'a', the index of the array runs from 'l' to 'r'*/
int main(void)
{
    long int a[NMBRS];
    srand(time(NULL));

    // put even numbers into the array
    for(long int i = 0; i<10*NMBRS; i++){
        a[i] = 2*i;
    }

    //do many searches for a random number
    for(long int i = 0; i<10*NMBRS; i++){
        long int n = rand()%NMBRS;
        // if even return positve index n/2 e
        if((n%2) == 0){
            assert(bin_it(n, a, 0, NMBRS-1) == n/2);

        }
        // else return a negative as the number cant be found as no odd nos
        else{
            assert(bin_it(n, a, 0, NMBRS-1) < 0);
        }
    }
    return 0;
}

long int bin_it(long int k, const long int* a, long int l, long int r)
{
    while(l <= r ){
        long int m = (l+r)/2; //find mid point
        if(k == a[m]){   //if number we're searching for is the mid point return m 
            return m;
        }
        else{
            //keeping rhs to search
            if (k > a[m]){
                l = m+1; //l which starts at 0 becomes the new mid point +1
            }
            else{ // if k is less than midpoint it must in left hand side of array so r become midpoint - 1
                r = m - 1;

            }
        }
    }
    return -1;
}
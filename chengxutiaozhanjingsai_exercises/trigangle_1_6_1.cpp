using namespace std;
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX_N 100

int n, a[MAX_N];


void solve()
{
    int ans = 0, len = 0, mas = 0, rest = 0;

    for ( int i = 0; i < n; i++)
    {
        for ( int j = i + 1; j < n; j++ )
        {
            for ( int k = j + 1; k < n; k++ )
            {
                len = a[i] + a[j] + a[k];
                mas = max( a[i], max( a[j], a[k]));
                rest = len - mas;

                if ( rest > mas )
                    ans = max( ans, len );
            }
        }
    }

    printf("%d\n", ans );
}

/* O(nlogn) */
void solve1( int *a, int n )
{

    for( int i = n -1; i > 1; i-- )
    {
        printf("solve1 %d, %d, %d\n", a[i], a[i - 1], a[i-2]);
        if( a[i] < a[i-1] + a[i-2] )
        {
            printf(" solve1 %d\n", a[i] + a[i-1] + a[i - 2] );
            return;
        }
        else
        {
            solve1( a, n-1 );
        }
    }
    
}

int main( int argc, char *argv[] )
{
    //*
    n = 5;
    int b[MAX_N] = { 2, 3, 4, 5, 10};
    //*/


    /*
    n = 4;
    int b[MAX_N] = { 4, 5, 10, 20 };
    */
    memcpy(a , b, MAX_N );

    solve();

    printf("solve1 %d, %d, %d\n", a[0], a[1], a[2]);
    sort( a, a + n);
    printf("sort solve1 %d, %d, %d\n", a[0], a[1], a[2]);
    
    solve1( a, n );
    return 0;
}



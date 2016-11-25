/**
 * @file permitation_2_1_6.cpp
 * @brief special input for permutation n!
 * @author yimo
 * @version 0.1.1
 * @date 2016-11-24
 */

#define MAX_N  10
bool used[MAX_N];
int perm[MAX_N];

// generate n!
void permutation1( int pos, int n )
{
    if( pos == n )
    {
        /* operate on perm */
        return;
    }

    // focus on perm[pos], decide use 0~n-1 which one
    for( int i = 0; i < n; i++ )
    {
        if( !used[i])
        {
            perm[pos] = i;
            used[i] = true;
            permutation1( pos+1, n);
            used[i] = false;
        }
    }
    return;
}

#include <algorithm>

// can use even have duplicate elements
// next_permutation generate by dict sequence
int perm2[MAX_N];

void permutation2( int n )
{
    for( int i = 0; i < n; i++)
    {
        perm2[i] = i;
    }
    do
    {
        //do to perm2

    }while( next_permutation( perm2, perm2 +n ));
    return;
}




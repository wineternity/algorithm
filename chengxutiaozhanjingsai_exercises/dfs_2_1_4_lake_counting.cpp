/**
 * @file dfs_2_1_4.cpp
 * @brief 
 * DFS ( deep first search )
   Description
   
   Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. 
   
   Given a diagram of Farmer John's field, determine how many ponds he has.
   Input
   
   * Line 1: Two space-separated integers: N and M 
   
   * Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.
   Output
   
   * Line 1: The number of ponds in Farmer John's field.
   Sample Input
   
   10 12
   W........WW.
   .WWW.....WWW
   ....WW...WW.
   .........WW.
   .........W..
   ..W......W..
   .W.W.....WW.
   W.W.W.....W.
   .W.W......W.
   ..W.......W.
   Sample Output
   
   3
 * @author yimo
 * @version 0.1.1
 * @date 2016-11-21
 */

#include <cstdio>
#define N 10
#define M 12

void check_neighbour( int a[N][M], int i, int j )
{
    if( i < 0 || i >= N || j < 0 || j >= M )
        return;

    if( a[i][j] == 1 )
    {
        a[i][j] = 0;
        /* use a while loop for
         * i -1, ~ 1
         * j -1 ~ 1
         * to instead of this
         */
        check_neighbour( a, i - 1, j );
        check_neighbour( a, i - 1, j - 1 );
        check_neighbour( a, i - 1, j + 1 );
        check_neighbour( a, i, j - 1 );
        check_neighbour( a, i, j + 1 );
        check_neighbour( a, i + 1, j );
        check_neighbour( a, i + 1, j - 1 );
        check_neighbour( a, i + 1, j + 1 );
    }

}


int main( int argc, char * argv )
{
    int count = 0;
    int a[N][M] = {
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                    { 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    { 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
                    { 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                    { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                 };

    for( int i = 0; i < N; i ++ )
    {
        for( int j = 0; j < M; j++ )
        {
           if( a[i][j] == 1)
           {
               check_neighbour( a, i, j ); 
               count++;
           }
        }
    }

    printf("%d\n", count );
   
}

/**
 * @file dfs_2_1_4.cpp
 * @brief 
 * DFS ( deep first search )
 * in a1, a2, ,,, an, search a whehter some of them can added up to k
 * 1<=n <=20, 10*e-9<<a<=10*e7   k's range  same to a
 * input sample:
 * n=4, a={1,2,4,7} k=13    -> Yes (13=2+4+7)
 * n=4, a={1,2,4,7} k=15    -> No
 * @author yimo
 * @version 0.1.1
 * @date 2016-11-20
 */

#include <cstdio>

int a[4] = { 1, 2, 4, 7 };

bool check_sum( int k, int start, int end )
{
    if( start == end )
    {
        if( k == 0 )
            return true;
        else
            return false;
    }
    else
    {
        if( check_sum( k, start + 1 , end ))
        {
            printf("a[%d] %d ", start, 0 );
            return true;
        }
        if( check_sum( k - a[start], start + 1, end ))
        {
            printf("a[%d] %d ", start, a[start]);
            return true;
        }

        return false;
    }
}

bool check_sum2( int k, int sum, int start, int end )
{
    if( start == end )
        return  k == sum;
    if( check_sum2( k, sum,  start + 1 , end ))
    {
        printf("a[%d] %d ", start, 0 );
        return true;
    }
    if( check_sum2( k, sum + a[start], start + 1, end ))
    {
        printf("a[%d] %d ", start, a[start]);
        return true;
    }

    return false;
}

int main( int argc, char * argv )
{

    int k = 13;
    if( check_sum( k, 0, 4 ))
        printf("Yes\n");
    else
        printf("No\n");

    k = 15;
    if( check_sum( k, 0, 4 ))
        printf("Yes\n");
    else
        printf("No\n");

    k = 13;
    if( check_sum2( k, 0, 0, 4 ))
        printf("Yes\n");
    else
        printf("No\n");

    k = 15;
    if( check_sum2( k, 0, 0, 4 ))
        printf("Yes\n");
    else
        printf("No\n");

}

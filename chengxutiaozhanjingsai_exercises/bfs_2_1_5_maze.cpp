/**
 * @file bfs_2_1_5.cpp
 * @brief 
 * BFS ( breadth first search )
   Description
   给定一个大小为N×M的迷宫。迷宫由通道和墙壁组成，每一步可以向邻接的上下左右四格
   的通道移动。请求出从起点到终点所需的最小步数。请注意，本题假定从起点一定可以移动
   到终点。
   限制条件
    N, M ≤ 100
    
Sample:
N=10, M=10（迷宫如下图所示。'#'，'.'，'S'，'G'分别表示墙壁、通道、起点和终点）
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#

output
22

   
 * @author yimo
 * @version 0.1.1
 * @date 2016-11-21
 */

#include <cstdio>
#include <queue.h>
#define N 10
#define M 10

/* use pair<int, int>
 * and a d[N][M] to count path. If can not reached, use INF=1000000000 to show unreachiable
 * */
typedef struct 
{
    int x;
    int y;
    int path_count;
}spot_t;
queue<spot_t> q;

int find_shortest_path( char a[N][M] )
{
    spot_t s, org;
    int i, j;

    while( q.size() )
    {
        org = q.front();
        i = org.x;
        j = org.y;


        /* define dx={ 1, 0, -1, 0 } dy={ 0, 1, 0, -1} to use while loop */
        if( i > 0 && a[i - 1][j] == 'G')
        {
            return org.path_count + 1;
        }
        else if( i > 0 && a[i - 1][j] == '.')
        {
            s.x = i - 1;
            s.y = j;
            s.path_count = org.path_count + 1;
            q.push(s);
        
        }
        if( i < N && a[i + 1][j] == 'G')
        {
            return org.path_count + 1;
        }
        else if( i < N && a[i + 1][j] == '.')
        {
            s.x = i + 1;
            s.y = j;
            s.path_count = org.path_count + 1;
            q.push(s);
        }
            
        if( j > 0 && a[i][j - 1] == 'G')
        {
            return org.path_count + 1;
        }
        else if( j > 0 && a[i][j - 1] == '.')
        {
            s.x = i;
            s.y = j - 1;
            s.path_count = org.path_count + 1;
            q.push(s);
        }

        if( j > 0 && a[i][j + 1] == 'G')
        {
            return org.path_count + 1;
        }
        else if( j < M && a[i][j + 1] == '.')
        {
            s.x = i;
            s.y = j + 1;
            s.path_count = org.path_count + 1;
            q.push(s);
        }

        q.pop();
    }

    return 0;
}


int main( int argc, char * argv )
{
    int count = 0;
    char a[N][M] = {
                    {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#' },
                    {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#' },
                    {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#' },
                    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.' },
                    {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#' },
                    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#' },
                    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#' },
                    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.' },
                    {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.' },
                    {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#' }
                 };

    for( int i = 0; i < N; i++ )
    {
        for( int j = 0; j < M; j++ )
        {
            if( a[i][j] == 'S' )
            {
                spot_t s;
                s.x = i;
                s.y = j;
                s.path_count = 0;
                q.push(s);
                count = find_shortest_path( a );
                break;
            }


        }
    }


    printf("%d\n", count );
   
}

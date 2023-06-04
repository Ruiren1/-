#include<stdio.h>
int main(void)
{
    /*********Begin*********/
    int i, j, ti, tj,ti2, tj2, m, n, max, min, i2, j2;
    int Array[10][10] = { 0 };
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &Array[i][j]);
        }

    }
    for (i = 0; i < m; i++)
    {
        max = Array[i][0];
        for (j = 1; j < n; j++)
        {
            if (Array[i][j] > max)
            {
                max = Array[i][j];
                ti = i;
                tj = j;
            }
        }
        min = Array[0][tj];
        for (j2 = 0; j2 < n; j2++)
        {
            if (Array[ti][j2] < min)
            {
                min = Array[ti][j2];
                ti2 = ti;
                tj2 = j2;
            }

        }
        if (Array[ti][tj] == min)
        {
            printf("Array[%d][%d]=%d", ti, tj, min);
            return 0;
        }

    }
    printf("None");


    /*********End**********/
    return 0;
}
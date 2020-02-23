#include "lemin.h"

int *ways_steps(t_path  *path)
{
    int *rez;
    int i;

    i = -1;
    rez = (int*)malloc(sizeof(int) * path->step_elems);
    while(++i < path->step_elems)
        rez[i] = path->steps[i] + path->ways[i][0] - 1;
    return(rez);
}


int  *min_gap(int *mas, int *rez, int size)
{
    int avg;
    int i;
    int temp;

    avg = 0;
    i = -1;
    while(++i < size)
        avg += rez[i];
    avg /= i;
    i = -1;
    while ( ++i < size)
    {
        if (rez[i] == avg)
            continue;
        if (rez[i] > avg)
        {
            temp = rez[i] - avg;
            rez[i] -=temp;
            mas[i] -=temp;
        }
        if (rez[i] < avg)
        {
            temp = avg - rez[i];
            rez[i] +=temp;
            mas[i] +=temp;
        }
    }
    i = -1;
    temp = 0;
    while(++i < size)
        temp += mas[i];
    temp = g_ants - temp;
    while (--temp > -1)
        mas[temp]++;
    return (mas);
}


t_path *balancer(t_path *path)
{
    int *rez;

    rez = ways_steps(path);
    path->steps = min_gap(path->steps, rez, path->step_elems);
	free(rez);
    rez = ways_steps(path);
    return (path);
}

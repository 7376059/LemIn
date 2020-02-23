#include "lemin.h"



int *steps_creator(int count, int *size, int flag)
{
    static  int *rez;
    int         i;
    
    if(flag == 1)
        rez = NULL;
    if (rez == NULL && flag == 0)
    {
        rez = (int*)malloc(sizeof(int) * count);
        *size = count;
        i = -1;
        while (++i < count)
            rez[i] = 0;
    }
    if (flag == 0)
    {    
        i = -1;
        while (++i < count)
            rez[i]++;
    }
    return(rez);
}


int set_koef(void)
{
    if (g_ants < 100)
        return (1);
    if (g_ants < 500)
        return (2);
    if (g_ants < 1000)
        return (4);
    if (g_ants < 40000)
        return (8);
    if (g_ants < 80000)
        return (7);
    if (g_ants < 160000)
        return (8);
    return (9);

}

t_path *counter(t_path *path)
{
    if(path->size > 1)
        return(counter2(path));
    path->steps = (int*)malloc(sizeof(int) * 1);
    path->steps[0] = g_ants;
    path->step_elems = 1;
    path->final_steps = g_ants + path->ways[0][0];
    return (path);
}


t_path *counter2(t_path *path)
{
    int ants;
    int first;
    int count;
    int temp;
    int rez;
    int koef;

    ants = g_ants;
    rez = 0;
    
    koef = set_koef();
    while (ants > 0)
    {
        count = 1;
        first = ants + path->ways[0][0] - 1;
        while(first > path->ways[count][0])
        {
            temp = first - path->ways[count][0];
            temp /= count;
            first = temp + path->ways[count][0] - 1 + (temp * koef) / 10;
            count++;
            if (count > path->size - 1)
                break ;
        }
        ants -= count;
        rez++;
        path->steps = steps_creator(count, &path->step_elems, 0);
    }
    path = balancer(path);
    path->final_steps = path->steps[0] + path->ways[0][0] - 1;    // path->wats[0] - 2 bilo
    steps_creator(0, 0, 1);
    return(path);
}

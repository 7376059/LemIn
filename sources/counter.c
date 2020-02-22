#include "lemin.h"
/*
t_path *init_path(void)
{
	t_path *rez;

    rez = (t_path*)malloc(sizeof(t_path));
    rez->size = 3;
    rez->ways = (int**)malloc(sizeof(char*) * 10);
    rez->ways[0] = (int*)malloc(sizeof(int) * 3);
    rez->ways[0][0] = 3;
    rez->ways[0][1] = 0;
    rez->ways[0][2] = 1;

    rez->ways[1] = (int*)malloc(sizeof(int) * 6);
    rez->ways[1][0] = 3;
    rez->ways[1][1] = 2;
    rez->ways[1][2] = 3;
    rez->ways[1][3] = 1;

    rez->ways[2] = (int*)malloc(sizeof(int) * 6);
    rez->ways[2][0] = 4;
    rez->ways[2][1] = 5;
    rez->ways[2][2] = 6;
    rez->ways[2][3] = 7;
    rez->ways[2][4] = 1;
	
    rez->ways[3] = (int*)malloc(sizeof(int) * 6);
    rez->ways[3][0] = 6;

    rez->ways[4] = (int*)malloc(sizeof(int) * 6);
    rez->ways[4][0] = 6;

    rez->ways[5] = (int*)malloc(sizeof(int) * 6);
    rez->ways[5][0] = 6;

    rez->ways[6] = (int*)malloc(sizeof(int) * 6);
    rez->ways[6][0] = 6;

    rez->ways[7] = (int*)malloc(sizeof(int) * 6);
    rez->ways[7][0] = 6;

    rez->ways[8] = (int*)malloc(sizeof(int) * 6);
    rez->ways[8][0] = 6;
    return (rez);
}
*/
int *steps_creator(int count, int *size, int flag)
{
    static  int *rez;
    int         i;
    
    //int flag = 0;

    if(flag == 1)
    {
        //free(rez);
        rez = NULL;

    }
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
      //  printf("kek\n");
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
    //printf("%d\n", path->final_steps);
    steps_creator(0, 0, 1);
    return(path);
}

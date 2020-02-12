#include "lemin.h" 
/*

80    3123     L1-get_name[i]  i = 
      545678
60
20
  L1-1 L2-4
  L1-2 L2-5 L3-1 L4-4
  L1-3 L2-6 L3-2 L4-5 L5-1 L6-4
  L2-7 L3-3 L4-6 L5-2 L6-5 L7-1 L8-4
  L2-8 L4-7 L5-3 L6-6 L7-2 L8-5 L9-1 L10-4




*/



int **set_numbers(int *steps, int size)
{
    int **rez;
    int i;
    int j;
    int ants;

    i = -1;
    rez = (int**)malloc(sizeof(int*) * size);
    while(++i < size)
        rez[i] = (int*)malloc(sizeof(int) * steps[i]);
    i = 0;
    ants = 1;
    //printf("\nsize = %d\n", size);
    int check = size;

    while(ants <= g_ants)
    {
        j = -1;
        while(++j < check)
        {   
            rez[j][i] = ants;
            ants++;
            if(ants > g_ants)
                break;
        }
        i++;
        if (check > 1)
        {
            if (i >= steps[check - 1])
            {
             //   printf("i = %d check = %d steps[check] = %d\n", i, check, steps[check] );
                check--;
            
            }
        }

    }
    return (rez);

}

void ants_output(int **ways, int **numbers, int *steps, int size)
{
    int i;

    i = -1;
    while (++i < steps[0])
    {

    }
}


void moover(t_path *path, char **names)
{
    int **numbers;

    numbers = set_numbers(path->steps, path->step_elems);
    
    int i;
    int j;

    i = -1; 
    while (++i < path->step_elems)
    {
       j = -1;
       while (++j < path->steps[i])
            printf("%d ", numbers[i][j]);
        
       printf("\n");
    }


}

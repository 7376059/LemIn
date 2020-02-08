#include "lemin.h"



t_path *init_path(void)
{
	t_path *rez;

    rez = (t_path*)malloc(sizeof(t_path));
    rez->size = 5;
    rez->ways = (int**)malloc(sizeof(char*) * 5);
    rez->ways[0] = (int*)malloc(sizeof(int) * 3);
    rez->ways[0][0] = 60;
    rez->ways[0][1] = 0;
    rez->ways[0][2] = 4;


    rez->ways[1] = (int*)malloc(sizeof(int) * 6);
    rez->ways[1][0] = 100;
    rez->ways[1][1] = 0;
    rez->ways[1][1] = 1;
    rez->ways[1][3] = 2;
    rez->ways[1][4] = 3;

    rez->ways[2] = (int*)malloc(sizeof(int) * 6);
    rez->ways[2][0] = 110;


    rez->ways[3] = (int*)malloc(sizeof(int) * 6);
    rez->ways[3][0] = 114;

    rez->ways[4] = (int*)malloc(sizeof(int) * 6);
    rez->ways[4][0] = 130;
    return (rez);
}



int one_way(int ants, int length)
{
    return(ants + length - 1);
}

/*

        60    по первому    139 
80   s      e
        100                 40 : 2 = 20
                            20 + 100 - 1 = 119
                            60 + 60 - 1 = 119
                            

        119
         119 - 110 = 9
        9 : 3 = 3 

        3 + 110 - 1 = 112


        60    по первому             55 + 60 - 1   114
80   s      e
        100                             15 + 100 - 1 = 114
 
        110                            5 + 100 - 1  114
примерно 5 муравьев по пути после итерации алго на 77 еще 2 пустим по пути 11 например 

-----------
смотрим 4 путь дальше
 по алго 
 заебись все расписал как по маслу
// не проебать остаток от деления на 2
 
    
*/



t_path *counter(t_path *path)
{
    int ants;
    int first;
    int count;
    int temp;
    int rez;
    int test[5];

    test[0] = 0;
    test[1] = 0;
    test[2] = 0;
    test[3] = 0;

    test[4] = 0;
    ants = g_ants;
    rez = 0;
    
    printf("ants = %d\n",ants );
    while (ants > 0)
    {
      //  printf("kek\n");
        count = 1;
        first = one_way(ants, path->ways[0][0] - 1);
        while(first > path->ways[count][0] - 1)
        {
            temp = first - path->ways[count][0] - 1;
            temp /= count;
            first = one_way(temp, path->ways[count][0] - 1);
            count++;
            if (count > path->size - 1)
                break ;

        }
        ants -= count;
        rez++;
        count--; 
        while(count > -1)
        {
            test[count]++;
            count--;
        }
    }
        printf("1 - %d\n2 - %d\n3 - %d\n4 - %d\n5 - %d\n", test[0], test[1], test[2], test[3], test[4]);
    path->final_steps = rez + path->ways[0][0] - 1;
    return(path);

}


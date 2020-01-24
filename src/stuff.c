# include "lemin.h"

void print_names(t_graph *gr)
{
	int i;
	i = -1;
	printf("Names:\n");
	while(++i < gr->vector->elems)
		printf("%d  %s\n", i, gr->vector->names[i]);
}


void print_edges(t_graph *gr)
{
	t_edge *temp;
	
	temp = gr->edges;
	printf("Edges:\n");
	while(temp)
	{
		printf("%d-%d cost = %d\n", temp->a, temp->b, temp->cost);
		temp = temp->next;
	}
}

t_graph *init_graph()
{
    t_graph *rez;

    rez = (t_graph*)malloc(sizeof(t_graph));
    rez->vector = init_vector();
    rez->edges = NULL;
    return (rez);
}

void clear_mas(char **mas)
{
    int i;

    i = -1;
    while (mas[++i])
        free(mas[i]);
    free(mas);
}


int get_mas_length(char **mas)
{
    int i;

    i = -1;
    while(mas[++i])
        ;
    return (i);
}

void throw_error(t_graph *gr)
{
    // чистим структуруi
	
	int i;
	i = -1;
	while (++i < gr->vector->elems)
	{
		printf("%d  %s\n", i, gr->vector->names[i]);
	}
    write(1, "Error\n", 6);
    exit(0);
}

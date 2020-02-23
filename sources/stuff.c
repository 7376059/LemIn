#include "lemin.h"
void    print_way(char **names)
{
	int ver;

	ver = g_end;

	while (ver != -1)
	{
		printf("%s", names[ver]);
		if ((ver = g_parent[ver]) != -1)
			printf(" --- ");
	}
	printf("\n");
}


void clear_edge(t_edge *edge)
{
	t_edge *fast;
	t_edge *slow;

	if(!(edge))
	       return;
	fast = edge->next;
	slow = edge;
	while(fast)
	{
		free(slow);
		slow = fast;
		fast = fast->next;
	}
	free(slow);
}

void clear_graph(t_graph *gr)
{
	int i;
	t_vertex *fast;
	t_vertex *slow;
		
	i = -1;
	if(!(gr) || !(gr->vertex))
		return;
	while(++i < gr->vector->elems)
		free(gr->vector->names[i]);
	free(gr->vector->names);
	free(gr->vector);
	fast = gr->vertex->next;
	slow = gr->vertex;
	while(fast)
	{
		clear_edge(slow->edges);
		free(slow);
		slow = fast;
		fast = fast->next;
	}
	
		clear_edge(slow->edges);
		free(slow);
		free(gr);
}

void    print_graph(t_graph *gr)
{
	print_names(gr);

	printf("\nstart_room  = %d\nend_room = %d\n", g_start, g_end);
	printf("\nsize = %d\nelems = %d\n\n", gr->vector->size, gr->vector->elems);

	//print_edges(gr);

	printf("\nFinito La Comedia\n");
}

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
	t_vertex *temp;
	t_edge  *temp2;

	temp = gr->vertex;
	printf("Spisok:\n");
	while(temp)
	{
		printf ("Vertex: %d\n", temp->room);
		temp2 = temp->edges;
		printf("  Edges:");
		while(temp2)
		{
			printf ("\n    to: %d (%d)", temp2->to, temp2->cost);
			temp2 = temp2->next;
		}
		printf("\n");
		temp = temp->next;
	}
}

t_graph *init_graph()
{
	t_graph *rez;

	rez = (t_graph*)malloc(sizeof(t_graph));
	rez->vector = init_vector();
	rez->vertex = NULL;
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
	write(1, "Error\n", 6);
	clear_graph(gr);
	exit(0);
}

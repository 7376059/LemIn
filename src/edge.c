#include "lemin.h"

t_edge *init_edge(int a, int b)
{
	t_edge *rez;
	
	rez = (t_edge*)malloc(sizeof(t_edge));
	rez->cost = 1;
	rez->a = a;
	rez->b = b;
	rez->next = NULL;
	return (rez);
}

t_edge *add_edge(t_edge *start, int a, int b)
{
	t_edge *temp;
	t_edge *new;

	temp = start;
	new = init_edge(a, b);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (start);
}


#include "lemin.h"

t_vector	*init_vector()
{
	t_vector *rez;

	rez = (t_vector*)malloc(sizeof(t_vector));
	rez->size = 10000; // протестить с 1
	rez->elems = 0;
	rez->names = (char**)malloc(sizeof(char*) * rez->size);
	return(rez);
}


t_vector *realloc_vector(t_vector *temp, char *line)
{
	t_vector *new;
	int i;

	i = -1;
	new = (t_vector*)malloc(sizeof(t_vector));
	new->names = (char**)malloc(sizeof(char*) * temp->size * 2);
	new->size = temp->size * 2;
	new->elems = temp->elems;
	while (++i < temp->elems)
		new->names[i] = temp->names[i];
	new = vector_push(new, line);
	return (new);
}

t_vector *vector_push(t_vector *temp, char *line)
{
	if (temp->elems < temp->size)
	{
		temp->names[temp->elems] = ft_strdup(line);
		temp->elems++;
	}
	else
		temp = realloc_vector(temp, line);
	return (temp);
}

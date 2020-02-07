/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:18:10 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/07 19:01:25 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

int g_ants;
int g_start;
int g_end;

int g_INF;

int	*g_dest;
int *g_visit;
int	*g_parent;

int g_size; // ?
int	**g_ways; // ?

typedef struct s_path
{
	int size; //размер массива ways
	int **ways; // [0]104 все муравьи пройдут за 1 ход за 1 
		     // [1]501234
}	t_path;


typedef struct s_vector
{
	int	size;	// текущий полный размер вектра
	int elems; // кол-во заполненых элементов
	char **names; // массив с именами
}			 t_vector;

typedef struct s_edge
{
	int to;
	int cost;
	struct s_edge *next;
}			  t_edge;


typedef struct s_vertex
{
	int room;
	struct s_edge	*edges;
	struct s_vertex	*next;
}				t_vertex;



typedef struct s_graph 
{	
	struct s_vertex	*vertex;
	struct s_vector *vector;
}				t_graph;

void    print_graph(t_graph *gr);
void	print_way(char **names);

void	algo_suurbale(t_graph *graph);
void	algo_dijkstra(t_graph *graph);

t_vector *realloc_vector(t_vector *temp, char *line);
t_vector *vector_push(t_vector *temp, char *line);
t_vector    *init_vector();
t_edge *add_edge(t_edge *start, int a);
t_edge *init_edge(int a);
t_vertex *add_vertex(t_vertex *start, int number);
t_vertex *init_vertex(int number);


t_graph *start_parser(t_graph *gr);
t_graph *init_graph();
void print_edges(t_graph *gr);
void print_names(t_graph *gr);

void throw_error(t_graph *gr);
int get_mas_length(char **mas);
void clear_mas(char **mas);
t_path *init_path(void);
int counter(t_path *path);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:18:10 by dgrady            #+#    #+#             */
/*   Updated: 2020/02/23 18:09:29 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

int g_ants;
int g_start;
int g_end;

int g_INF;

int	*g_dest;
int *g_visit;
int	*g_parent;

typedef struct s_path
{
	int size;

    int max_ways;
    int max_path;
	int **ways;
	            
    int step_elems;
    int *steps;

    int final_steps;
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

void	ants_mover(t_path *path, char **names);
void	save_best_choice(t_path **best_choice, t_path *path);
void    add_way(t_path **path);
void    init_path(t_path **paths);
void    sort_paths(t_path **path);
void    detect_common_edge(t_path **path);

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
t_graph *init_graph(void);
void print_edges(t_graph *gr);
void print_names(t_graph *gr);

void throw_error(t_graph *gr);
int get_mas_length(char **mas);
void clear_mas(char **mas);
t_path *counter(t_path *path);
t_path *counter2(t_path *path);
t_path *balancer(t_path *path);
int		get_number(t_graph *gr, char *name);
int		get_ants(char *line, t_graph *gr);
int		validate_name(char **name);
void	clear_graph(t_graph *gr);
void    clear_mas(char **mas);

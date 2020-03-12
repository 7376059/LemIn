/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:18:10 by dgrady            #+#    #+#             */
/*   Updated: 2020/03/12 23:45:19 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

int g_ants;
int g_start;
int g_end;

int g_print_paths;

int g_infinity;

int	*g_dest;
int *g_visit;
int	*g_parent;

typedef struct s_graph
{
	int max_size_matrix;
	int amount_vertices;
	int	elems_in_matrix;

	int	*source_vertices;

	int	*duplicated_vertices;

	int **links_in_matrix;
	int **adjacency_matrix;
}	t_graph;

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

typedef struct s_list_graph
{
	struct s_vertex	*vertex;
	struct s_vector *vector;
}				t_list_graph;

void	ants_mover(t_path *path, char **names);
void	save_best_choice(t_path *best_choice, t_path *path);
void    add_way(t_path *path, int *source_vertices);
void    init_path(t_path **paths);
void    sort_paths(t_path *path);
void    detect_common_edge(t_path **path);

void detect_crossing_paths(t_path *path);

void    print_graph(t_list_graph *gr);
void	print_way(char **names);

void	algo_suurbale(t_list_graph *graph);
void	algo_dijkstra_list(t_list_graph *graph); // delete
void  algo_dijkstra(int **links, int **matrix, int size_matrix, int *source_vertices);

t_vector *realloc_vector(t_vector *temp, char *line);
t_vector *vector_push(t_vector *temp, char *line);
t_vector    *init_vector();
t_edge *add_edge(t_edge *start, int a);
t_edge *init_edge(int a);
t_vertex *add_vertex(t_vertex *start, int number);
t_vertex *init_vertex(int number);

void	clear_int_array(int **ways, int size);


t_list_graph *start_parser(t_list_graph *gr);
t_list_graph *init_list_graph(void);
void print_edges(t_list_graph *gr);
void print_names(t_list_graph *gr);

void throw_error(t_list_graph *gr);
int get_mas_length(char **mas);
void clear_mas(char **mas);
void counter(t_path *path);
void counter2(t_path *path);
void balancer(t_path *path);
int		get_number(t_list_graph *gr, char *name);
int		get_ants(char *line, t_list_graph *gr);
int		validate_name(char **name);
void	clear_graph_list(t_list_graph *gr);
void    clear_mas(char **mas);

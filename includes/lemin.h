/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:18:10 by dgrady            #+#    #+#             */
/*   Updated: 2020/01/19 17:28:40 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
#include <fcntl.h>

int g_ants;
int g_rooms;
int g_size;
int g_start;
int g_end;

typedef struct s_graph
{	
	char  **matrix;
	char  **names;

}				t_graph;

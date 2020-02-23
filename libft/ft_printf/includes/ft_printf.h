/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:52:31 by efriesen          #+#    #+#             */
/*   Updated: 2020/02/22 19:38:56 by efriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../../includes/libft.h"

int				ft_printf(const char *str, ...);
char			*itoa_base_sign(long long int value, int base);
char			*itoa_base_unsign(unsigned long long int value, int base);
int				ft_analyze(const char *str);
int				is_zero(char *str);
int				get_base(char t);
void			param_set_default(void);
char			*str_assembly(va_list lst);
char			*precision_modific_int(char *str);
char			*precision_modific_str(char *str);
char			*width_modific(char *str);
char			*flag_modific_int(char *str);
char			*str_float(va_list lst);
char			*mod_size_h_hh(va_list lst, char t, int base);
char			*mod_size_l_ll(va_list lst, char t, int base);
char			*no_mod_size(va_list lst, char t, int base);
char			*flag_plus_mod(char *str);
void			flag_space_mod(char *str);
char			*flag_zero_mod(char *str);
char			*flag_hash_mod(char *str);
int				g_flag;
int				get_type(const char *str);
int				not_valid_exit(const char *str);
int				get_size_2(const char *str);
char			*round_help(char *str, double x);

typedef struct	s_param {
	int			f_minus;
	int			f_plus;
	int			f_space;
	int			f_zero;
	int			f_hash;

	int			width;
	int			precision;

	int			mod_h;
	int			mod_hh;
	int			mod_l;
	int			mod_ll;
	int			mod_bl;

	char		type;
	void		*data;

}				t_param;

t_param			*g_param;
#endif

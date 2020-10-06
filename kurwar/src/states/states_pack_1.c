/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_pack_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by wclayton          #+#    #+#             */
/*   Updated: 2020/02/19 17:46:43 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lc.h"
# define IDI_NAHUY_PIDARAS_TAK_NELZYA NULL

t_oper *st_comment(char *buf)
{
    if (*buf == '\n')
        return (FSM(buf + 1));
    else
        return (st_comment(buf + 1));
}

t_oper *st_pnorpc(char *buf)
{
    if (!ft_strncmp(COMMENT_CMD_STRING, (const char *)buf, ft_strlen(COMMENT_CMD_STRING)))
        return (st_getpc(buf + ft_strlen(COMMENT_CMD_STRING)));
    else if (!ft_strncmp(NAME_CMD_STRING, (const char *)buf, ft_strlen(NAME_CMD_STRING)))
        return (st_getpn(buf + ft_strlen(NAME_CMD_STRING)));
    else
        return (st_error());
    
    
}

t_oper *st_getpc(char *buf)
{
    if (*buf == ' ' || *buf == '\t')
        return (st_getpc(buf + 1));
    else if (*buf == '"')
        return (st_recpc(buf + 1));
    else
        return (st_error());
}

t_oper *st_recpc(char *buf)
{
    int i;
    char *pc;

    i = 0;
    while (buf[i] != '"' && buf[i])
        ++i;
    if (buf[i] == '\0')
        return (st_error());
    else
    {
        if (!(pc = (char*)malloc(sizeof(char) * i + 1)))
            return (st_error());
    }
    
}

t_oper *st_error(void)
{
    exit(IDI_NAHUY_PIDARAS_TAK_NELZYA);
}
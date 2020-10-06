/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fsm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by wclayton          #+#    #+#             */
/*   Updated: 2020/05/15 18:05:34 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lc.h"

typedef enum states {
    INITIAL,
    GOTPN,
    GOTPC,
    GOTPNPC,
    LABELOROP,
    LABEL,
    OP,
    COMMENT,
    PNORPC,
    STRTOKEN1,
    STRTOKEN2,
    OPNAME,
    ARG1INDLAB,
    ARG1DIRLAB,
    ARG1IND,
    ARG1DIR,
    ARG1REG,
    ARG2INDLAB,
    ARG2DIRLAB,
    ARG2IND,
    ARG2DIR,
    ARG2REG,
    ARG3INDLAB,
    ARG3DIRLAB,
    ARG3IND,
    ARG3DIR,
    ARG3REG,
    ERR
} t_states;



int is_label(char c)
{
    int i;

    i = 0;
    while (LABEL_CHARS[i])
    {
        if (c == LABEL_CHARS[i])
            return (c);
        
    }
    return (0);
}

int check_labelness(char *buf)
{
    int flag = 0;

    while (*buf && *buf != LABEL_CHAR && flag >= 0)
    {
        if (!is_label(*buf) || *buf == ' ' || *buf == '\t')
            flag = 0;
        ++buf;
    }
    return (flag);
}

int oper_lst_pushback(t_com com, t_oper **oper)
{
    t_oper *tmp;

    if (!(tmp = (t_oper*)malloc(sizeof(t_oper))))
            return (-1);
    tmp->com = com;
    if (*oper != 0)
    {
        tmp->off = (*oper)->last->off + tmp->com.size;
        (*oper)->last->next = tmp;
    }
    else
    {
            tmp->off = 0;
            *oper = tmp;
            (*oper)->last = *oper;
            (*oper)->next = NULL;
    }
    return (1);
}

int label_action(char *buf, t_oper** oper)
{
    t_com forward;
    size_t len;

    len = 0;
    forward.code = -1;
    forward.label.offset = -1;
    while (*(buf + len) != LABEL_CHAR)
        ++len;
    if (!ft_strncpy(forward.label.name, buf, len) 
        || !oper_lst_pushback(forward, oper))
        return (-1);
    return (len + 1);
}

//wrapper
char *readf(int fd)
{
    char *buf;
    char *out;
    char *tmp;

    while (read(fd, buf, 1000))
    {
        tmp = out;
        if (!(out = ft_strjoin(out, buf)))
            return (0);
        if (tmp)
            free(tmp);
    }  
    return (out);
}

int comment_action(char *buf)
{
    int i;

    i = 0;
    while (*(buf + i) != '\n' && *(buf + i))
        ++i;
    return (i);
}

int name_action(char *buf, t_oper **oper)
{
    int err;
    int len;
    int out;
    t_nc conf;

    len = 0;
    err = 0;
    out = 0;
    while (*buf && *buf != '"')
    {
        ++buf;
        ++out;
    }
    if (!(*buf))
        err = 1;
    while (*(buf+len) && *(buf + len) != '"')
        ++len;
    ft_strncpy(buf, conf.name, len);
    if (!(*buf))
        err = 1;
    if (err == 1)
        return (-1);
    out += len;
    return (out);
}

int pcom_action(char *buf, t_oper **oper)
{
    int err;
    int len;
    int out;
    t_nc conf;  

    len = 0;
    err = 0;
    out = 0;
    while (*buf && *buf != '"')
    {
        ++buf;
        ++out;
    }
    if (!(*buf))
        err = 1;
    while (*(buf+len) && *(buf + len) != '"')
        ++len;
    ft_strncpy(buf, conf.comment, len);
    if (!(*buf))
        err = 1;
    if (err == 1)
        return (-1);
    out += len;
    return (out);
}

int get_args(char *buf, t_com *com)
{
    int i;
    int out;
    int len;
    int err;

    i = 0;
    out += ft_strlen(op_tab[(*com).code].name);
    buf += out;
    while (i < op_tab[(*com).code].count_args && !err)
    {
        //op :arg1, rarg2, %arg3 #asdas//
        while (*buf && (*buf == ' ' || *buf == '\t'))
        {
            ++out;
            ++buf;
        }
        while (*(buf + len) != SEPARATOR_CHAR && *(buf + len) != '\n' 
                && *(buf + len) != COMMENT_CHAR && *(buf + len) != '\t'
                && *(buf + len) != ' ' && *(buf + len))
            ++len;
        if (!ft_strncpy((*com).args[i].arg_val, buf, len))
            err = 1;
        out += len;
        buf += len;

        if (i + 1 != op_tab[(*com).code].count_args)
        {
            while (*buf && (*buf == ' ' || *buf == '\t'))
            {
                ++buf;
                ++out;
            }
            if (*buf != SEPARATOR_CHAR)
                err = 1;
        }
        else
        {
            while (*buf && (*buf == ' ' || *buf == '\t')
                    && *buf != '\n' && *buf != COMMENT_CHAR)
            {
                ++buf;
                ++out;
            }
            if (*buf != '\n' && *buf != COMMENT_CHAR)
                err = 1;
        }
        ++i;
    }
}

int get_on(char *buf)
{
    int i;
    int out;

    out = -1;
    i = 0;
    while (op_tab[i].name)
    {
        if (!ft_strncmp(op_tab[i].name, buf, ft_strlen(op_tab[i].name)))
            out = i + 1;
        ++i;
    }
    return (out);
}

int op_action(char *buf, t_oper** oper)
{
    int out;
    t_com com;

    if (!(com.code = get_on(buf)) || !(out = get_args(buf, &com)))
        ;
        //|| !val_args_1(com))


    //if arg | op_tab[i].args[j] == op_tab[i].args[j]
    return (out);
}



int labop_action(char* buf, t_oper** oper)
{
    int out = 0;
    if (check_labelness(buf))
        out += label_action(buf, oper);
    else
        out += op_action(buf, oper);
    return (out);
}

void  FSM(char *buf)
{
    t_oper *oper;
    t_states state = INITIAL;
    oper = (t_oper*)malloc(sizeof(t_oper));
    int got_pn, got_pc;
    got_pn = 0;
    got_pc = 0;

    while (got_pn == 0 || got_pc == 0)
    {
        if (*buf == COMMENT_CHAR)
            buf = buf + comment_action(buf);
        else if (*buf == ' ' || *buf == '\t' || *buf == '\n' )
            ++buf;
        else if (!ft_strncmp(buf,".name", 5))
            buf += name_action(buf, &oper);
        else if (!ft_strncmp(buf,".comment", 8))
            buf += pcom_action(buf, &oper);
    }
    
    while (*buf)
    {
        if (*buf == COMMENT_CHAR)
            buf += comment_action(buf);
        else if (*buf == ' ' || *buf == '\t' || *buf == '\n')
            ++buf;
        else if (is_label(*buf))
            buf += labop_action(buf, &oper);
        else 
            state = ERR;
        if (state == ERR)
            break;
    }
    
}

int parse_inp(int fd)
{
    char *buf;
    t_oper *opchain;
        
    if (!(buf = readf(fd)) || !(opchain = (t_oper*)malloc(sizeof(opchain))))
        return (0);
    FSM(buf);
}

int main(void)
{
    int fd;
    
    if (!(fd = open("test", O_RDONLY)) || !parse_inp(fd))
        return (EXIT_FAILURE);
    else
        return (EXIT_SUCCESS);
    



}
#include "../inc/lc.h"
# include "./libft/libft.h"
#include "stdio.h"
#include "string.h"


t_oper* gen(void);

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}


void	int32_to_bytecode(char *data, int32_t pos, int32_t value, size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (u_int8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void trans_start(t_oper* oper, t_nc nc)
{
	int fd = open("test.cor", O_RDWR|O_CREAT| O_TRUNC, 0777);
	int len;
	int pos;
	char *buf;
	pos = 0;

	len = 52;
	buf = ft_strnew(len);
	
	int32_to_bytecode(buf, pos, COREWAR_EXEC_MAGIC, 4);
	pos +=4;
	ft_memcpy(&buf[pos], nc.name, ft_strlen(nc.name));
	
	write(fd, buf, len);

}


char *get_exec_code(t_oper *oper)
{

	t_oper *temp;

	temp = oper;

	while(temp)
	{
		/*
		printf("offset = %d\n", temp->offset);
		printf("code = %d\n", temp->com.code);
		printf("size = %d\n", temp->com.size);
		printf("arg_val = %s\n", temp->com.args[0].arg_val);
		printf("arg_code = %d\n", temp->com.args[0].arg_type);
		printf("############\n");
		*/
		temp = temp->next;
	}

	return (NULL);
}






int main(void)
{

	t_oper* oper = gen();
	t_nc nc  = {"BATMANAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\ndsfsg", "This city"};	

	char a = 'B';
    //printf("%d\n",COREWAR_EXEC_MAGIC);
	//printf("%s\n", ft_itoa_base(a, 16));
	//trans_start(oper, nc);
	 get_exec_code(oper);
	return 0;
}

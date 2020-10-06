#include "./lc.h"
# include "./libft/libft.h"
#include "stdio.h"
#include "string.h"



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


t_oper* gen(void)
{
    t_oper *oper1;
    oper1 = (t_oper*)malloc(sizeof(t_oper));

    t_label *l1 = (t_label*)malloc(sizeof(t_label));
    l1->offset = 0;
    l1->name = "loop";

    t_com *sti = (t_com*)malloc(sizeof(t_com));
    sti->label = *l1;
    sti->code = 11;
    sti->size = 7;

    //t_arg args =(t_arg)malloc(    sizeof(t_arg));

    //t_arg args1[3] = {{"r1", T_REG}, {"%:live", T_DIR}, {"%1", T_DIR}};

    t_arg *args1 = (t_arg*)malloc(sizeof(t_arg));
    t_arg *args2 = (t_arg*)malloc(sizeof(t_arg));
    t_arg *args3 = (t_arg*)malloc(sizeof(t_arg));

    args1->arg_val = "r1";
    args1->arg_type = T_REG;
    args1->next = args2;

    args2->arg_val = "%:live";
    args2->arg_type = T_DIR;
    args2->next = args3;

    args3->arg_val = "%1";
    args3->arg_type = T_DIR;
    args3->next = 0;

    sti->args = args1;

    oper1->com = *sti;
    oper1->offset = 0;
    oper1->next = NULL;


    printf("%d\n", oper1->com.args->arg_type);
    printf("%s\n", oper1->com.args->arg_val);
	

    printf("%d\n", oper1->com.args->next->arg_type);
    printf("%s\n", oper1->com.args->next->arg_val);

    printf("%d\n", oper1->com.args->next->next->arg_type);
    printf("%s\n", oper1->com.args->next->next->arg_val);
    //printf("%s\n", oper1->com.args[1].arg_val);
    //printf("%s\n", oper1->com.args[2].arg_val);
    return(oper1);
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
	
	//t_arg args1[3] = {{"r1", T_REG}, {"%:live", T_DIR}, {"%1", T_DIR}};
	t_arg *temp;
	int count;

	temp = oper->com.args;
	count = 0;

	while(temp)
	{
		temp = temp->next;
		
	}

	return (NULL);
}

int main(void)
{

	t_oper* oper = gen();
	//t_nc nc  = {"BATMANAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\ndsfsg", "This city"};	

	//char a = 'B';
    //printf("%d\n",COREWAR_EXEC_MAGIC);
	//printf("%s\n", ft_itoa_base(a, 16));
	//trans_start(oper, nc);

	get_exec_code(oper);
	return 0;
}


// .name       "Batman"
// .comment    "This city needs me"
// loop:
//         sti r1, %:live, %1
// live:
//         live %0
//         ld %0, r2
//         zjmp %:loop


include "../inc/lc.h"
#include <stdio.h>

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

	//t_arg args =(t_arg)malloc(	sizeof(t_arg));
		
    //t_arg args1[3] = {{"r1", T_REG}, {"%:live", T_DIR}, {"%1", T_DIR}};

	t_arg *args1 = (t_arg*)malloc(sizeof(t_arg)*3);
	args1[0].arg_val = "r1";
	args1[0].arg_type = 1;

	sti->args = args1;
	
    oper1->com = *sti;
    oper1->offset = 0;
    oper1->next = NULL;

		
	//printf("%s\n", oper1->com.label.name);
	//printf("%s\n", oper1->com.args[0].arg_val);
	printf("%d\n", oper1->com.args[0].arg_type);
	
	//printf("%s\n", oper1->com.args[1].arg_val);
	//printf("%s\n", oper1->com.args[2].arg_val);
    return(oper1);
}

t_nc nc = {"Batman", "This city needs me"};



// .name       "Batman"
// .comment    "This city needs me"
// loop:
//         sti r1, %:live, %1
// live:
//         live %0
//         ld %0, r2
//         zjmp %:loop

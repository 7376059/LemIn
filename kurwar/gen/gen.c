#include "lc.h"

t_oper* gen(void)
{
    t_oper *oper1;
    t_oper *oper2;
    t_oper *oper3;
    t_oper *oper4;

    oper1 = (t_oper*)malloc(sizeof(t_oper));
    oper2 = (t_oper*)malloc(sizeof(t_oper));
    oper3 = (t_oper*)malloc(sizeof(t_oper));
    oper4 = (t_oper*)malloc(sizeof(t_oper));

    t_arg args1 = {{"r1", T_REG}, {"%:live", T_DIR}, {"%1", T_DIR}};
    t_arg args2 = {{"%0", T_DIR}};
    t_arg args3 = {{"%0", T_DIR}, {"r2", T_REG}};
    t_arg args4 = {{"%:loop", T_DIR}};

    t_com sti = {
        {0, "loop"}, args1, 11, 7
    };
    
    t_com live = {
        {7, "live"}, args2, 0, 5
    };

    t_com ld = {
        {0, 0}, args3, 1, 7
    };

    t_com zjmp = {
        {0,0}, args4, 9, 3
    };

    oper1->com = sti;
    oper2->com = live;
    oper3->com = ld;
    oper4->com = zjmp;

    oper1->offset = 0;
    oper2->offset = 7;
    oper3->offset = 12;
    oper4->offset = 19;

    
    oper1->next = oper2;
    oper2->next = oper3;
    oper3->next = oper4;
    oper4->next = 0;

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

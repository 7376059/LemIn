make -C ../libft
gcc src/try_fsm.c src/get_next_line.c src/op.c -L../libft -lft -Iinc
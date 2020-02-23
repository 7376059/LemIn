cmake_minimum_required(VERSION 3.13)

project(lem-in)
include_directories(./library)
FILE(GLOB LIBFT_SRCS ./library/srcs/*.c)
FILE(GLOB LIBFT ./library/ft_printf/srcs/*.c)

set(FOO "
        ./sources/algo_dijkstra.c
        ./sources/algo_suurbale.c
        ./sources/ants_mover.c
        ./sources/balancer.c
        ./sources/counter.c
        ./sources/edge_vertex.c
        ./sources/parser.c
        ./sources/main.c
        ./sources/path_functions_1.c
        ./sources/path_functions_2.c
        ./sources/stuff.c
        ./sources/stuff2.c
        ./sources/vector.c"
        )

add_executable(lem-in FOO  ./library/includes/libft.h ./library/ft_printf/includes/ft_printf.h includes/lemin.h ${LIBFT_SRCS} ${LIBFT})
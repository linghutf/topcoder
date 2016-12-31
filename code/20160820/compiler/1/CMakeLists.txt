cmake_minimum_required(VERSION 2.8)

add_custom_command(COMMAND flex)

flex -o simp.yy.c simp.l
gcc simp.yy.c -o simp -lfl

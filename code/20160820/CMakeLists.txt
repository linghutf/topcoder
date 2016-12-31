cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER "g++")
add_definitions("-g")
add_definitions("-std=c++11")

find_package(Boost COMPONENTS system regex REQUIRED)

#file(GLOB RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TARGET_SRC)
#add_executable()

add_executable(swap swap.cc)

add_executable(swapc swap.c)

add_executable(duplicate duplicate.cc)

add_executable(binary_search binary_search.cc)

add_executable(const_te const_te.cc)

add_executable(memcpy memcpy.cc)

add_executable(quicksort quicksort.cc)
add_executable(mysort sort.cc)

add_executable(z-algo z-algo.cc)

add_executable(cstr_test cstr_test.c)

add_executable(epoll_test epoll_test.cc)

add_executable(epoll2 epoll_test2.cc)

add_executable(reverse_list reverse_list.cc)

#add_executable(read_file read_file.c)

add_executable(num_of_bit num_of_bit.c)

add_executable(swap_oe swap_odd_even.cc)

add_executable(snake snake.cc)

add_executable(permutation permutation.cc)

add_executable(max_conti_sum max_conti_sum.cc)

add_executable(reverse_word str_arr.cc)

add_executable(topk min_k.cc)

add_executable(stack_heap_test stack_heap_diff.cc)

add_executable(erase_vec erase_vec.cc)

add_executable(exchane_arr meituan.cc)

add_executable(smart_ptr test_sp.cc)
target_link_libraries(smart_ptr pthread)

add_executable(touzi touzi.cc)

add_executable(mq_test mq_test.cc)
target_link_libraries(mq_test rt pthread)

add_executable(shm_test shm_test.cc)
target_link_libraries(shm_test rt pthread)

add_executable(atoi atoi.cc)

add_executable(five_colors five_color_shortest_dis.cc)

add_executable(fifa fifa.cc)
add_executable(max_hurt max_hurt.cc)

add_executable(make_pair make_pair.cc)

#add_executable(regex_test regex_test.cc) # ERROR
add_executable(regex_test_std regex_test_std.cc)

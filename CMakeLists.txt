cmake_minimum_required(VERSION 3.9)
project(Algorithm C)

set(CMAKE_C_STANDARD 99)

add_executable(Algorithm main.c insertion_sort/insertion_sort.c insertion_sort/insertion_sort.h common/common.h common/common.c select_sort/select_sort.h select_sort/select_sort.c merge_sort/merge_sort.h merge_sort/merge_sort.c search_bin/search_bin.h search_bin/search_bin.c Problems/1/solution.h Problems/1/solution.c bubble_sort/bubble_sort.h bubble_sort/bubble_sort.c Problems/2/solution.h Problems/2/solution.c Problems/3/find-max-subarray.h Problems/3/find-max-subarray.c)
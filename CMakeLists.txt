cmake_minimum_required(VERSION 3.10)
project(20S-3353-PA04)
set (EXE_NAME Project4)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "positions12.txt")
set (input02 "positions25.txt")
set (input03 "positions100.txt")
set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
add_executable(${EXE_NAME} main.cpp Search.cpp Tour.cpp TourManager.cpp Town.cpp Population.cpp Genetic.cpp Naive.cpp AdjacencyList.cpp)
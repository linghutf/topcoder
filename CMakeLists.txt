cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE ${TARGETLIST} RELATIVE ${CMAKE_CURRENT_SRC_DIR} "*.cc")

foreach(TARGET ${TARGETLIST})
    string(LENGTH ${PROJECT_SOURCE_DIR} module_prefix_length)

    get_filename_component(name ${TARGET} PATH)
    MESSAGE(STATUS ${name})
    #add_executable(${name} TARGET)
endforeach()


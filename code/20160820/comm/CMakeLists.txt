cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-g")

find_package(Protobuf REQUIRED)

file(GLOB PROTO_AGENS ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${PROTO_AGENS})

message(STATUS "file:" ${PROTO_HDRS})
# 获取该文件目录
get_filename_component(PARENT_DIR ${PROTO_HDRS} DIRECTORY)
# 获取该文件名
get_filename_component(FILENAME ${PROTO_HDRS} NAME)

# 判断当前目录是否存在该文件
#if(EXISTS ${PARENT_DIR}/${FILENAME}) # 避免移动到当前文件夹
if(EXISTS ${PROTO_SRCS} AND (NOT ${PARENT_DIR} EQUAL ${CMAKE_CURRENT_SOURCE_DIR})) # 直接判断是否存在,并且不是源码目录
    # 移动生成文件
    message(STATUS "move files...")
    execute_process(COMMAND mv ${PROTO_HDRS} ${PROTO_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/
        RESULT_VARIABLE MOVE_ERR
        )
    # 判断是否移动成功
    if(NOT MOVE_ERR)
        message(STATUS "move successfully...")
    endif()
endif()

add_executable(netty_asi netty_asi.cc ${PROTO_SRCS})
target_link_libraries(netty_asi ${PROTOBUF_LIBRARIES} pthread)

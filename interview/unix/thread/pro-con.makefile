CC = g++
CXXFLAGS = -std=c++17
LIBS = -lpthread -lboost_thread -lboost_system

all:main

main: pro-con.cc
	$(CC) $(CXXFLAGS) $^ -o $@ $(LIBS)

test: main
	./$<

clean: main
	@rm $^

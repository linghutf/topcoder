cc = g++
cxxflags = -std=c++11
libs = -lpthread
objs:= produce-consumer

all: produce-consumer.o
	$(cc) $(cxxflags) $< $(libs) -o $(objs)

produce-consumer.o: produce-consumer.cc
	$(cc) $(cxxflags) -c $< -o $@

clean:
	@rm $(objs)
	@rm *.o

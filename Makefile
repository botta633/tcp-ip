CC=g++
CPPFLAGS="-std=c++20"
TARGET:test.exe
OBJS=GLList/glthreads.o \
	     graphs/graph.o	\
	     topologies.o
test.exe:testapp.o ${OBJS}
	${CC} ${CPPFLAGS} -c test


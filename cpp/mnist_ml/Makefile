CC=g++
INCLUDE_DIR:= ${MNIST_ML_ROOT}/include
SRC := ${MNIST_ML_ROOT}/src
CFLAGS := -shared -std=c++20 -g
LIB_DATA := libdata.so
LIB_DATA_WIN := libdata.a
LIB_DATA_DLL := libdata.dll
LIB_DATA_DLL_A := libdata.dll.a

# for win

dll : libdir objdir win_obj/data_handler.o win_obj/data.o
	${CC} ${CFLAGS} -O2 -static-libgcc -static-libstdc++ -o ${MNIST_ML_ROOT}/lib/${LIB_DATA_DLL} obj/*.o

win : libdir objdir win_obj/data_handler.o win_obj/data.o
	ar rcs ${MNIST_ML_ROOT}/lib/${LIB_DATA_WIN} obj/*.o
	rm -r ${MNIST_ML_ROOT}/obj

win_obj/data_handler.o : ${SRC}/data_handler.cc
	${CC} ${CFLAGS} -o obj/data_handler.o -I ${INCLUDE_DIR} -c ${SRC}/data_handler.cc

win_obj/data.o : ${SRC}/data.cc
	${CC} ${CFLAGS} -o obj/data.o -I ${INCLUDE_DIR} -c ${SRC}/data.cc
# for bash

all : ${LIB_DATA}

${LIB_DATA} : libdir objdir obj/data_handler.o obj/data.o
	${CC} ${CFLAGS} -o ${MNIST_ML_ROOT}/lib/${LIB_DATA} obj/*.o
	rm -r ${MNIST_ML_ROOT}/obj

libdir :
	mkdir -p ${MNIST_ML_ROOT}/lib 

objdir :
	mkdir -p ${MNIST_ML_ROOT}/obj

obj/data_handler.o : ${SRC}/data_handler.cc
	${CC} -fPIC ${CFLAGS} -o obj/data_handler.o -I${INCLUDE_DIR} -c ${SRC}/data_handler.cc

obj/data.o : ${SRC}/data.cc
	${CC} -fPIC ${CFLAGS} -o obj/data.o -I${INCLUDE_DIR} -c ${SRC}/data.cc

clean:
	echo ${MNIST_ML_ROOT}
	rm -r ${MNIST_ML_ROOT}/lib
	rm -r ${MNIST_ML_ROOT}/obj

# compile entire folder with include header : g++ -std=c++20 -I ./include/ -O main ./src/* 
# compile one file: g++ -std=c++20 main.cpp -o main
# include lib folder: g++ -std=c++20 src/main.cpp -I include -L lib -ldata -o main.exe
# include lib file: g++ -std=c++20 src/main_test_lib.cpp -I include lib/libdata.a -o main.exe
NAME := friday
SRC := ${NAME}.cpp
OUTPUT := ${NAME}.out
CXX := clang++
RM := /bin/rm

all: install


install: ${src}
	@${CXX} -o ${NAME} -O2 ${SRC}

clean:
	@${RM} -f ${OUTPUT} ${NAME}

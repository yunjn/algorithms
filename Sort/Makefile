CCX = g++
DEBUG = -g
OBJS = test
all:${OBJS}

test:t_sort.cc
	$(CCX) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	-rm test
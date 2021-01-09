CCX = g++
DEBUG = -g
OBJS = sq_list.out
all:${OBJS}

sq_list.out:t_sq_list.cc
	$(CCX) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	rm *.out
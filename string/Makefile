CCX = g++
DEBUG = -g
OBJS = t_string.out
all:${OBJS}

t_string.out:t_string.cc
	$(CCX) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	rm *.out
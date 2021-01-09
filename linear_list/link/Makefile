CCX = g++
DEBUG = -g
OBJS = link_list.out
all:${OBJS}

link_list.out:t_link_list.cc
	$(CCX) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	rm *.out
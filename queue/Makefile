CCX = g++
DEBUG = -g
OBJS = t_link_queue.out t_circle_queue.out
all:${OBJS}

t_link_queue.out:t_link_queue.cc
	$(CCX) $^ -o $@ ${DEBUG}

t_circle_queue.out:t_circle_queue.cc
	$(CCX) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	rm *.out
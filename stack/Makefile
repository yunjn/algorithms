CCX = g++
DEBUG = -g
OBJS = t_sq_stack.out t_link_stack.out
all:${OBJS}

t_sq_stack.out:t_sq_stack.cc
	$(CCX) $^ -o $@ ${DEBUG}

t_link_stack.out:t_link_stack.cc
	$(CCX) $^ -o $@ ${DEBUG}

.PHONY:clean
clean:
	rm *.out
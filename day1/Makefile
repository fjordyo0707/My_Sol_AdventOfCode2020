# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_ADDFILE

SRCS = main.c day1.c
OBJS = $(SRCS:%.c=%.o)

# diff -w means do not care about space

day1_solution: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o day1_solution

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 

test1: day1_solution 
	./day1_solution	input/basic_test

clean: # remove all machine generated files
	rm -f day1_solution *.o output*
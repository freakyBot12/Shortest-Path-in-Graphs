CC = gcc
CFLAGS = -Wall -Wextra

build: test1 test2 test3

run-best:
	./test3

run-p1:
	./test1

run-p2:
	./test2

test1:
	$(CC) $(CFLAGS) algo1.c graph_tester1.c ListGraph.c LinkedList.c -o test1

test2:
	$(CC) $(CFLAGS) algo2.c graph_tester2.c -o test2

test3:
	$(CC) $(CFLAGS) algo3.c graph_tester3.c ListGraph.c LinkedList.c Stack.c -o test3

.PHONY: clean

clean:
	rm -rf test1 test2 test3 test.in test.out

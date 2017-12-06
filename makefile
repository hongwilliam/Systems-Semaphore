all: semaphore.c
	gcc semaphore.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out

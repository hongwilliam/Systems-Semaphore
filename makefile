all: semaphore.c
	gcc semaphore.c

run: all
	./a.out -c 4
	./a.out -v
	./a.out -c 3
	./a.out -v
	./a.out -r

clean:
	rm *.o
	rm *~
	rm a.out

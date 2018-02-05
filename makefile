all: pixel.o
	gcc -o runo pixel.o

main.o: pixel.c pixel.h
	gcc -c pixel.c

run: all
	./runo

clean:
	rm -rf *.o *. *~ *.ppm *.jpg runo

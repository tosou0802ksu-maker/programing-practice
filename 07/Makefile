//2554709 黒田蒼史 5月21日作成

all: queen

queen: queen.o module1.o module2.o
	gcc -Wall -o queen queen.o module1.o module2.o

queen.o: queen.c common.h module1.h module2.h
	gcc -Wall -c queen.c

module1.o: module1.c common.h module1.h
	gcc -Wall -c module1.c

module2.o: module2.c common.h module2.h
	gcc -Wall -c module2.c

clean:
	rm -f *.o queen
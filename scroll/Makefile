INCLUDE = $(INCLUDE_NOPI)
LDFLAGS = $(LDFLAGS_NOPI)

INCLUDE_NOPI := 
LDFLAGS_NOPI := -lncurses

all: scroll

scroll: input.o display.o main.o
	cc -o $@ $^ $(LDFLAGS)

input.o: input.c
	cc -o $@ -c $< $(INCLUDE)

display.o: display.c
	cc -o $@ -c $< $(INCLUDE)

main.o: main.c scroll.h
	cc -c $<

clean: 
	rm -f *.o scroll

run:	
	./scroll

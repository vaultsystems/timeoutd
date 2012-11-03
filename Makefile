CFLAGS=-g -Wall

timeoutd:	timeoutd.o Makefile debug.o
	$(CC) $(CFLAGS) -o timeoutd -L/usr/X11R6/lib timeoutd.o debug.o -lXss -lXext

timeoutd.o:	timeoutd.c Makefile debug.h
	$(CC) $(CFLAGS) -o timeoutd.o -c timeoutd.c -DTIMEOUTDX11

install: timeoutd
	install -o root -g root -m 2111 timeoutd /usr/bin/timeoutd
	install -o man -g root -m 444 timeoutd.8 /usr/share/man/man8
	install -o man -g root -m 444 timeouts.5 /usr/share/man/man5

clean:
	rm timeoutd timeoutd.o TAGS *~

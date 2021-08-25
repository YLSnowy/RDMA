# compile:
# 	gcc -Wall -g -std=gnu99 bw_template.c -o verbs-demo -libverbs -pthread -lrdmacm

# run:
# 	./verbs-demo -d mlx5_0

# clean:
# 	rm -rf verbs-demo


CC=gcc
CFLAGS=-Wall  -g  -std=gnu99
INCLUDES=
LDFLAGS=-libverbs
LIBS=-pthread -lrdmacm

SRCS=bw_template.c
OBJS=$(SRCS:.c=.o)
PROG=verbs-demo

all: $(PROG)

debug: CFLAGS=-Wall -g 
debug: $(PROG)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

clean:
	$(RM) *.o *~ $(PROG)

compile:
	gcc bw_template.c -o bw_template.o -libverbs

server:
	./bw_template.o -d mlx5_0

client:
	./bw_template.o -d mlx5_0 host

clean:
	rm -rf bw_template.o

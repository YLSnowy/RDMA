compile:
	gcc bw_template.c -o bw_template.o -libverbs -pthread -lrdmacm

run:
	./bw_template.o -d mlx5_0 -e 5 server

clean:
	rm -rf bw_template.o

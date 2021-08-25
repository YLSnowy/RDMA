compile:
	gcc bw_template.c -o bw_template.o -libverbs -pthread -lrdmacm

run:
	./bw_template.o -d mlx5_0 server $1 $2 $3 $4 $5

clean:
	rm -rf bw_template.o

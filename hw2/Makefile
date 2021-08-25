compile:
	gcc -Wall -g -std=gnu99 bw_template.c -o verbs-demo -libverbs -pthread -lrdmacm

run:
	./verbs-demo -d mlx5_0

clean:
	rm -rf verbs-demo

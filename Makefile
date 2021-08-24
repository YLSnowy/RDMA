server:
	g++ -O0 -g -lm server.cpp -o server

client:
	g++ -O0 -g -lm client.cpp -o client

clean:
	rm -rf server client


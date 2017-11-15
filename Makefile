bin/alternate.so: bin/alternate.o
	gcc -shared -o bin/alternate.so bin/alternate.o

bin/alternate.o: src/alternate.cpp
	gcc -c -g -O0 -fPIC src/alternate.cpp -o bin/alternate.o

clean:
	rm -f bin/*.o bin/*.so

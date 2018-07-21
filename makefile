Main.o: 
	g++ -std=c++11 -o made *.cpp
run: Main.o
	./made
clean:
	rm -f made

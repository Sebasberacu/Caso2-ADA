all:
	g++ insertionSort.cpp quickSort.cpp freeTextSearch.cpp main.cpp -o run
	./run
build:
	g++ insertionSort.cpp quickSort.cpp freeTextSearch.cpp main.cpp -o run

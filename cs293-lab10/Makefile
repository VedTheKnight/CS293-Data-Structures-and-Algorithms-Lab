.PHONY: all test clean

COMPILE = g++ -std=c++20

part1:
	$(COMPILE) main.cpp -o p1
	./p1 < inputs/p1-input.txt > result.txt
	diff -Bw result.txt output/p1-output.txt
	rm -rf part1

part2:
	$(COMPILE) main.cpp -o p2
	./p2 < inputs/p2-input.txt > result.txt
	diff -Bw result.txt output/p2-output.txt
	rm -rf part2

part3:
	$(COMPILE) main.cpp -o p3
	./p3 < inputs/p3-input.txt > result.txt
	diff -Bw result.txt output/p3-output.txt
	rm -rf part3

clean:
	rm -rf p1 p2 p3 result.txt
	rm -rf *~

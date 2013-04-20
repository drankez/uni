VPATH = supporting-files
IDIR = supporting-files

ifs: main.o ifs.o matrix.o image.o
	g++ $^ -o $@

main.o: main.C
	g++ -c $^ -o $@

ifs.o: ifs.C
	g++ -c $^ -o $@

matrix.o: matrix.C
	g++ -c $^ -o $@

image.o: image.C
	g++ -c $^ -o $@

clear:
	rm -rf *o ifs
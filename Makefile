output: main.o AssociativeArray.h
	g++ main.o AssociativeArray.o -o run

main.o: main.cpp
	g++ -c main.cpp

AssociativeArray.h: AssociativeArray.cpp AssociativeArray.h
	g++ -c AssociativeArray.cpp

clean:
	rm *.o run *~

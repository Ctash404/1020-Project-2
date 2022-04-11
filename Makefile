COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) database.txt

$(PROGRAM): main.cpp Quiz.cpp printResult.cpp
	$(COMPILER) $(OPTIONS) main.cpp Quiz.cpp printResult.cpp -o $(PROGRAM)

clean:
	rm *.out
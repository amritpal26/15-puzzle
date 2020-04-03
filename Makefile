CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3 -g

puzzle: obj/main.o obj/Board.o

obj/main.o: src/main.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Board.o: src/Board.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin:
	mkdir -p $@

.PHONY: clean
clean:
	rm -r bin/ obj/ databases/*.dat
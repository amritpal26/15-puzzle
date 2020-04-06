CXX = g++
CXXFLAGS = -std=c++17 -g
# CXXFLAGS = -std=c++17 -Wall -O3 -g

puzzle: obj/main.o obj/Board.o obj/PatternDatabase.o obj/Pattern.o obj/Search.o| bin
	$(CXX) $(CXXFLAGS) -o bin/puzzle $^

obj/main.o: main.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<
obj/PatternDatabase.o: src/PatternDatabase.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Pattern.o: src/Pattern.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Board.o: src/Board.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Search.o: src/Search.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<

obj:
	mkdir -p $@

bin:
	mkdir -p $@


.PHONY: clean
clean:
	rm -r obj/ bin/
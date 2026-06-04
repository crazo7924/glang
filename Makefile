CXX = g++
LLVM_CXXFLAGS = $(shell llvm-config --cxxflags)
LLVM_LDFLAGS = $(shell llvm-config --ldflags --system-libs --libs core mcjit native)
CXXFLAGS = -O3 -g -std=c++17 $(LLVM_CXXFLAGS) -Wno-deprecated-register -Wno-c++11-narrowing -Isrc
LDFLAGS = $(LLVM_LDFLAGS)

SRCS = src/main.cpp src/parser.cpp src/lexer.cpp src/codegen.cpp src/ast.cpp
OBJS = $(SRCS:.cpp=.o)

glangc: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

src/parser.cpp src/parser.hpp: src/parser.y
	bison -d -o src/parser.cpp $<

src/lexer.cpp: src/lexer.l src/parser.hpp
	flex -o $@ $<

src/main.o: src/main.cpp src/parser.hpp
src/parser.o: src/parser.cpp src/parser.hpp
src/lexer.o: src/lexer.cpp src/parser.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f glangc src/parser.cpp src/parser.hpp src/lexer.cpp $(OBJS)

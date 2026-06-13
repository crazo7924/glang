CXX ?= clang++
LLVM_CXXFLAGS = $(shell llvm-config --cxxflags)
LLVM_LDFLAGS = $(shell llvm-config --ldflags --system-libs --libs core mcjit native)
CXXFLAGS = -O3 -g -std=c++17 $(LLVM_CXXFLAGS) -Wno-deprecated-register -Wno-c++11-narrowing -Isrc
LDFLAGS = $(LLVM_LDFLAGS)

SRCS = src/main.cc src/parser.cc src/lexer.cc src/codegen.cc src/ast.cc
OBJS = $(SRCS:.cc=.o)
TARGET = glang

all: $(TARGET)

glang: $(OBJS)
	@echo glang time...
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	@echo Done!

src/parser.cc src/parser.hh: src/parser.y
	@bison -d -o src/parser.cc $<

src/lexer.cc: src/lexer.l src/parser.hh
	@flex -o $@ $<

src/main.o: src/main.cc src/parser.hh
src/parser.o: src/parser.cc src/parser.hh
src/lexer.o: src/lexer.cc src/parser.hh

%.o: %.cc
	@echo Compiling $@
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(TARGET)
	@echo "running test.g"
	@echo
	@./$(TARGET) test.g

clean:
	@echo Cleaning...
	@rm -f $(TARGET) src/parser.cc src/parser.hh src/lexer.cc $(OBJS)
	@echo Done!

.PHONY: clean glang test

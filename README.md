# glang - A Good Language

`glang` is a simple language compiler and JIT executor built with Flex, Bison, and LLVM. This project demonstrates the fundamental concepts of compiler design, including lexical analysis, parsing, abstract syntax tree (AST) generation, and LLVM IR code generation.

## Features

*   **Lexical Analysis**: Handles tokens like identifiers, integers, floats, strings, keywords, operators, and delimiters.
*   **Parsing**: Supports function declarations, variable declarations, assignments, conditional statements (if/else), loops (while), and return statements.
*   **Abstract Syntax Tree (AST)**: Generates a hierarchical representation of the source code.
*   **LLVM IR Code Generation**: Converts the AST into LLVM Intermediate Representation, which can then be compiled to machine code or executed via JIT.
*   **Built-in Functions**: Includes `print` (for integers, floats, and strings) and `read` (for integers).
*   **String Literals**: Supports string literals with escape sequence processing and warning for unknown escape sequences.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need the following tools installed on your system:

*   **Clang/g++**: A C++ compiler (preferably Clang for better compatibility with LLVM).
*   **Flex**: A tool for generating lexical analyzers.
*   **Bison**: A tool for generating parsers.
*   **LLVM**: The LLVM compiler infrastructure, including `llvm-config`. The project is tested with LLVM version 22.
*   **Make**: A build automation tool.

On a Debian/Ubuntu-based system, you might install them with:

```bash
sudo apt-get update
sudo apt-get install build-essential flex bison clang llvm-$(llvm-config --version | cut -d'.' -f1)-dev
```

**Note**: Replace that `llvm-$(llvm-config --version | cut -d'.' -f1)-dev` with the appropriate LLVM development package name for your system and LLVM version (e.g., `llvm-22-dev`).

On RHEL/Fedora based systems, it will be:

```bash
sudo dnf install clang flex bison llvm-devel
```
### Building `glang`

0.  **Clone the repository**:
    ```bash
    git clone <repository-url>
    cd glang
    ```

1.  **Build the compiler**:
    ```bash
    make
    ```
    This will compile the lexer, parser, AST, and code generation components, and link them with the LLVM libraries to produce the `glang` executable.
## Usage

### Compiling and Running a Program

To compile and JIT run a `glang` source file (e.g., `test.g`):

```bash
./glang <source_file>
```

Example:

```bash
./glang test.g
```

### Emitting LLVM IR

You can also emit the LLVM IR for a `glang` program using the `--emit-llvm` flag:

```bash
./glang <source_file> --emit-llvm
```

Example:

```bash
./glang test.g --emit-llvm
```

### Emitting Object File

To emit an object file (`output.o`), use the `-c` or `--object` flag:

```bash
./glang <source_file> -c
```

Example:

```bash
./glang test.g -c
```

### Running Tests

The project includes a simple test target in the `Makefile` to compile and run `test.g`:

```bash
make test
```

## Project Structure

*   `src/ast.hh`, `src/ast.cc`: Defines the Abstract Syntax Tree (AST) nodes and their implementations.
*   `src/codegen.hh`, `src/codegen.cc`: Handles the generation of LLVM IR from the AST.
*   `src/lexer.l`: Flex lexical analyzer definition.
*   `src/parser.y`: Bison parser definition.
*   `src/main.cc`: Main entry point of the compiler.
*   `Makefile`: Build script for the project.
*   `test.g`: A sample `glang` program for testing.
*   `glang_v*_spec.txt`: The language specification.

## Contributing

Feel free to fork the repository and contribute.

# Monty ByteCode Interpreter

## Overview

The Monty ByteCode Interpreter is a program written in the C programming language that allows you to execute Monty scripts. Monty is a scripting language that uses a unique stack-based approach and relies on a specific set of instructions to manipulate the stack. The interpreter reads Monty byte code files, which typically have the `.m` extension, and executes the instructions they contain.

## Features

### Supported Instructions

The interpreter supports a variety of instructions, including:

- `push`: Push a value onto the stack.
- `pall`: Print all values on the stack.
- Other Monty-specific instructions for stack manipulation.

### Handling Whitespace and Comments

The interpreter handles whitespace gracefully, allowing for any number of spaces before or after opcodes and their arguments. It also ignores comments and additional text after the opcode or its required argument, making the code more flexible and readable.

### Error Handling

The interpreter provides error handling to catch and report common issues such as:

- Stack errors (e.g., attempting to pop from an empty stack).
- Invalid or unknown opcodes.
- Syntax errors in the Monty byte code file.

### Execution

The interpreter reads Monty byte code files line by line, parses the instructions, and executes them accordingly. It keeps track of the stack state and processes instructions in the specified order.

### Reporting Results

The interpreter can display the results of the executed Monty code, such as printed values or error messages, making it easy to debug and understand the program's behavior.

## Usage

To use the Monty ByteCode Interpreter, you can follow these steps:

1. Compile the interpreter program.
2. Run the interpreter, providing the Monty byte code file as an argument.

```shell
$ gcc *.c -o monty
$ ./monty bytecodes/your_script.m
```
# get_next_line

## About the Project

The `get_next_line` project is all about creating a function that allows you to read content line by line from a file descriptor. The project requires a good understanding of file operations and how data is managed in operating systems. This is essential knowledge for any programmer, as file manipulation is a common task for data handling and persistence. The main goal of this project is to code a function that reads and returns one line at a time from a text file.

## Static Variables and Functions

The `get_next_line` function uses static variables and functions for maintaining state across multiple function calls. Static variables are variables that retain their values between function calls. In the context of this project, they are used to keep track of the current state of file reading.

Static functions, on the other hand, are functions that are only accessible within the same source file where they are defined. In this project, static functions are used for utility purposes and are not exposed to external code. They help in achieving the task of reading lines from a file descriptor.

It's important to understand how static variables and functions work to grasp the inner workings of the `get_next_line` function.

## Usage

### Requirements

To use the `get_next_line` function, you need the GCC compiler and some standard C libraries.

### Instructions

#### Using it in your code

1. Include the `get_next_line` header in your code:

    ```c
    #include "get_next_line.h"
    ```

2. When compiling your code, add the source files and specify the buffer size using the `-D` flag:

    ```shell
    gcc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
    ```

#### Testing

To test the `get_next_line` function, follow these steps:

1. Edit the `get_next_line.c` file and uncomment the main function and headers inside it.

2. Optionally, you can edit `test.txt` files to provide different text for testing various cases.

3. Compile your code with the desired buffer size (replace "xx" with the size you want to test):

    ```shell
    gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
    ```

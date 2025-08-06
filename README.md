<h1>
	<p align="center">get_next_line</p>
	<img align="right" alt="Final Grade: 100/ 100%" src="https://img.shields.io/badge/-%20100%20%2F%20100-success">
</h1>
<p align="center">
	<b><i>Reading a line from a file descriptor is far too tedious.</b></i>
</p>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/mortinso/get_next_line">
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/mortinso/get_next_line">
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/mortinso/get_next_line">
</p>

<details>
	<summary><h2>Table of Contents</h2></summary>

<table>
<tr>
<td>

1. [Overview](https://github.com/mortinso/get_next_line/#overview) 
2. [Installation](https://github.com/mortinso/get_next_line/#installation)

   2.1. [Requirements](https://github.com/mortinso/get_next_line/#requirements)

   2.2. [Build Instructions](https://github.com/mortinso/get_next_line/#build-instructions)
3. [Usage](https://github.com/mortinso/get_next_line/#usage)

	3.1. [Syntax](https://github.com/mortinso/get_next_line/#syntax)

	3.2. [Return Value](https://github.com/mortinso/get_next_line/#return-value)
	
	3.3. [Buffer Size](https://github.com/mortinso/get_next_line/#buffer-size)
</td>
</tr>
</table>
</details>

## Overview
This project entailed the development of a function that when called repeatedly (E.g., using a loop) should allow the user to read the text file pointed to by the file descriptor (`fd`), one line at a time. It works by reading [`BUFFER_SIZE`](https://github.com/mortinso/get_next_line/#buffer-size) characters of `fd` at a time, and returning a line when it finds either a newline character or the EOF.

We were not allowed to use `lseek()` or global variables, so this was a great way to learn about static variables in C.

> [!NOTE]
> This project has been added to [my Libft](https://github.com/mortinso/Libft).

## Installation
### Requirements
- OS: Linux (for the Makefile, the source code works in any OS)
- make

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/mortinso/get_next_line.git
   ```
2. Include the header in your files:
	```C
	#include "<PATH>/get_next_line.h"
	```
2. Compile it with your project:
   ```bash
   cc -Wall -Wextra -Werror -D <files>.c get_next_line.c get_next_line_utils.c
   ```

## Usage
> [!WARNING]
> `get_next_line()` exhibits undefined behavior if the file associated with the `fd` is modified after the last call, while read() has not yet reached the EOF.
> It also exhibits undefined behavior when reading a binary file.
### Syntax
```
char *get_next_line(int fd);
```
- **fd**: The file descriptor to read from.

### Return Value
- Returns the read line on success.
- Retuns `NULL` if there's nothing else to read, or if an error occurs.

### Buffer Size
The buffer size of `read()` can be defined to a custom value at compilation time (Default is 10). Here we set it to 42:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c get_next_line.c get_next_line_utils.c
```
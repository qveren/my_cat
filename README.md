# my_cat

`my_cat` is a simple implementation of the Unix `cat` command in C.  
It reads one or more files and outputs their contents to the standard output (stdout).  
If no files are provided, it reads from standard input (stdin).

---

## Features

- Read a single file  
- Read multiple files sequentially  
- Read from stdin if no files are given  
- Supports text and binary files  
- Buffered reading for better performance (4096 bytes at a time)  
- Error handling for file opening and reading  

---

## Compilation

Compile the program using gcc:

```bash
gcc -o my_cat my_cat.c
```
Usage

Read a single file:
```bash
./my_cat file.txt
```
Read multiple files:
```bash
./my_cat file1.txt file2.txt file3.txt
```
Read from stdin:
```bash
./my_cat
```
Read from stdin via a pipe:
``` bash
echo "Hello world" | ./my_cat
```

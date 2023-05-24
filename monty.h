#ifndef MONTY_H
#define MONTY_H

#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
/**
* struct stack_s - doubly connected list portrayal of a stack (or line)
* @n: integer
* @prev: points to the previous component of the stack (or queue)
* @next: points to the next component of the stack (or queue)
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its capabilities
* @opcode: the opcode
* @f: function to handle the opcode
* Description: opcode and its capabilities
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
* struct bus_s - ...
* @arg: ...
* @file: ...
* @content: ...
* @lifi: ...
* Descritption: ...
*/
typedef struct bus_s
{
char *arg;
FILE *file;
char *content;
int lifi;
} bus_t;
extern bus_t bus;
void addnode(stack_t **head, int n);
void m_pall(stack_t **head, unsigned int c);
void m_push(stack_t **head, unsigned int c);
int m_execute(char *content, stack_t **head, unsigned int c, FILE *file);
int main(int argc, char *argv[]);
#endif

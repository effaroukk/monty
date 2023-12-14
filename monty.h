#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define _GNU_SOURCE


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
void free_nodes(void);
stack_t *new_node(int n);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
void mont_print_stack(stack_t **mont_stack, unsigned int mont_line_number);
void monty_pop_top(stack_t **monty_stack, unsigned int monty_line_number);
void monty_print_top(stack_t **monty_stack, unsigned int monty_line_number);













#endif /*MONTY*/

#include "monty.h"

/**
 * mont_print_stack - Adding a node to the stack.
 * @mont_stack: A double pointer to the top node of the stack.
 * @mont_line_number: line number of the opcode.
 */
void mont_print_stack(stack_t **mont_stack, unsigned int mont_line_number)
{
	stack_t *mont_tmp;

	(void) mont_line_number;
	if (mont_stack == NULL)
		exit(EXIT_FAILURE);
	mont_tmp = *mont_stack;
	while (mont_tmp != NULL)
	{
		printf("%d\n", mont_tmp->n);
		mont_tmp = mont_tmp->next;
	}
}

/**
 * monty_add_to_stack - Adds a node to the stack.
 * @monty_new_node: Pointer to the new node.
 * @monty_ln: Integer representing the line number of the opcode.
 */
void monty_add_to_stack(stack_t **monty_new_node, __attribute__((unused))unsigned
		int monty_ln)
{
	stack_t *monty_tmp;

	if (monty_new_node == NULL || *monty_new_node == NULL)
		exit(EXIT_FAILURE);
	if (monty_head == NULL)
	{
		monty_head = *monty_new_node;
		return;
	}
	monty_tmp = monty_head;
	monty_head = *monty_new_node;
	monty_head->next = monty_tmp;
	monty_tmp->prev = monty_head;
}

/**
 * monty_pop_top - Adds a node to the stack.
 * @monty_stack: Pointer to a pointer pointing to the top node of the stack.
 * @monty_line_number: Integer representing the line number of the opcode.
 */
void monty_pop_top(stack_t **monty_stack, unsigned int monty_line_number)
{
	stack_t *monty_tmp;

	if (monty_stack == NULL || *monty_stack == NULL)
		more_err(7, monty_line_number);

	monty_tmp = *monty_stack;
	*monty_stack = monty_tmp->next;
	if (*monty_stack != NULL)
		(*monty_stack)->prev = NULL;
	free(monty_tmp);
}

/**
 * monty_print_top - Prints the top node of the stack.
 * @monty_stack: Pointer to a pointer pointing to the top node of the stack.
 * @monty_line_number: Integer representing the line number of the opcode.
 */
void monty_print_top(stack_t **monty_stack, unsigned int monty_line_number)
{
	if (monty_stack == NULL || *monty_stack == NULL)
		more_err(6, monty_line_number);
	printf("%d\n", (*monty_stack)->n);
}


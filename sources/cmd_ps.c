#include "push_swap.h"

static t_stack	*ps_print_lst(t_stack *stack)
{
	printf("\n\n");
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		printf("stack %p -> ", stack);
		printf("stack->content %d\n ", *stack->content);
		printf("      stack->previous %p -> ", stack->previous);
		printf("      stack->next %p\n ", stack->next);
		stack = stack->next;
	}
	printf("stack %p -> ", stack);
	printf("stack->content %d\n ", *stack->content);
	printf("      stack->previous %p -> ", stack->previous);
	printf("      stack->next %p\n ", stack->next);
	return (NULL);
}

/*sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there 
is only one or no elements).*/
int	cmd_sa(t_game *game)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_a->next == NULL || game->stack_a == NULL)
		return (0);
	swap = game->stack_a;
	game->stack_a = game->stack_a->next;
	swap->next = game->stack_a->next;
	swap->previous = game->stack_a;
	game->stack_a->next = swap;
	game->stack_a->previous = NULL;
	
	temp = swap->next;
	temp->previous = swap;

	write(1, "sa\n", 3);
	ps_print_lst(game->stack_a);
	return (0);
}

/*ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.*/

int	cmd_ra(t_game *game)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_a == NULL || game->stack_a->next == NULL)
		return (0);
	swap = game->stack_a;
	while (game->stack_a->next != NULL)
		game->stack_a = game->stack_a->next;
	swap->previous = game->stack_a->previous;
	game->stack_a->previous = NULL;
	game->stack_a->next = swap->next;
	swap->next = NULL;
	
	temp = swap->previous;
	temp->next = swap;
	write(1, "ra\n", 3);
	ps_print_lst(game->stack_a);
	return (0);
}
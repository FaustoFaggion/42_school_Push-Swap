#include "push_swap.h"

/*sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there 
is only one or no elements).*/

int	cmd_sa(t_game *game)
{
	t_stack	*swap;

	if (game->stack_a->next == NULL)
		return (0);

	swap = game->stack_a;
	game->stack_a = game->stack_a->next;
	swap->next = game->stack_a->next;
	swap->previous = game->stack_a;
	game->stack_a->next = swap;
	write(1, "sa\n", 3);
	return (0);
}

/*ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.*/

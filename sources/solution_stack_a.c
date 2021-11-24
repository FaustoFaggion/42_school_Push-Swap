#include "push_swap.h"

static t_stack	*ps_print_lst(t_stack *stack)
{
	printf("\n");
	if (!stack)
	{
		printf("stack %p -> ", stack);
		printf("\n");
		return (NULL);
	}
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
	printf("\n");
	return (NULL);
}

//Verify if stack_a > stack_a->next
void	check_top_next(t_game *game)
{
	t_stack	*next_a;
	t_stack	*next_b;
	
	next_a = game->stack_a->next;
	if(*game->stack_a->content > *next_a->content)
	{
		if (game->stack_b != NULL && game->stack_b->next != NULL)
		{
			next_b = game->stack_b->next;
			if (*game->stack_b->content < *next_b->content)
				cmd_ss(game);
			else
				cmd_sa(game);
		}
		else
			cmd_sa(game);
	}
	else
		printf("top < next");
	ps_print_lst(game->stack_a);
	ps_print_lst(game->stack_b);
}

static void	check_top_botton_b(t_game *game, int i)
{
	printf("check_top_botton B\n");
	if (*game->top_b->content < *game->botton_b->content)
	{
		if (i == 0)
			cmd_rrr(game);
		else if (i == 1)
			cmd_rr(game);
	}
	else
	{
		if (i == 0)
			cmd_rra(game);
		else if (i == 1)
			cmd_ra(game);
	}

	
}

static void	check_top_botton(t_game *game, int i)
{
	printf("check_top_botton\n");
	if (*game->top_a->content < *game->botton_a->content)
	{
		if (i == 0)
			cmd_pb(game);
		else if (i == 1)
		{
			if (game->stack_b == NULL || game->stack_b->next == NULL)
				cmd_ra(game);
			else
				cmd_rrr(game);
		}
	}
	else
	{
		if (i == 0)
		{
			if (game->stack_b == NULL || game->stack_b->next == NULL)
				cmd_pb(game);	
			else
				check_top_botton_b(game, i);	
		}
		else if (i == 1)
			cmd_ra(game);
	}
}


static void	check_botton_pos(t_game *game, int i)
{
	int	a;
	int	b;
	
	a = *game->botton_a->pos - *game->size_b;
	if (a < 0)
		a= a * -1;
	b = *game->botton_a->pos - *game->size_a;
	if (b < 0)
		b = b * -1;
	printf("check_botton_pos\n");
	if (a <= b)
	{
		if (i == 0)
			check_top_botton(game, 0);
		else if (i == 1)
			cmd_rra(game);
	}
	else
	{
		if (i == 0)
			cmd_pb(game);
		else if (i == 1)
			check_top_botton(game, 1);
	}
}

void	check_top_pos(t_game *game)
{
	int	a;
	int	b;
	
	a = *game->top_a->pos - *game->size_b;
	if (a < 0)
		a = a * -1;
	b = *game->top_a->pos - *game->size_b;
	if (b < 0)
		b = b * -1;
	if (a <= b)
		check_botton_pos(game, 0);		
	else
		check_botton_pos(game, 1);	
	ps_print_lst(game->stack_a);
	ps_print_lst(game->stack_b);	
}

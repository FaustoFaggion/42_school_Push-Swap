/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_ps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/22 23:53:36 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	check_stack_a(t_game *game)
{
	t_stack	*temp;
	t_stack	*next;
	
	printf("check_stack_a\n");
	if (game->stack_a == NULL)
		return (1);
	if (game->stack_a->next == NULL)
		return (1);
	temp = game->stack_a;
	next = game->stack_a->next;
	while(*next->content > *temp->content)
	{
		if (next->next == NULL)
				return (1);
		temp = next;
		next = temp->next;
	}
	return (0);
}

static int	check_stack_b(t_game *game)
{
	t_stack	*temp;
	t_stack	*next;
	
	printf("check_stack_b\n");
	if (game->stack_b == NULL)
		return (1);
	if (game->stack_a->next == NULL)
		return (1);

	// Se stack_b > stack_b && stack_a estiver desordenada
	temp = game->stack_a;
	next = game->stack_a->next;
	while(*next->content > *temp->content)
	{
		if (next->next == NULL)
				return (1);
		temp = next;
		next = temp->next;
	}
	return (0);
}

int	solution_ps2(t_game *game)
{
	int		steps;
	int		flag;
	int		i;
	
	ps_print_lst(game->stack_a);
	
	steps = 0;
	flag = 0;
	while (flag < 5)
	{
		while (check_stack_a(game) != 1)
		{
			check_top_next(game);
			if (check_stack_a(game) != 1)
				check_top_pos(game);
		}
		while (check_stack_b(game) != 1)
		{
			check_top_next(game);
			if (check_stack_a(game) != 1)
				check_top_pos(game);
		}
		flag++;
		printf("\n\nflag : %d - ", flag);
		
	}
	printf("\n\nsteps : %d - ", steps);
	printf("size: %d - ", *game->size);
	printf("size A: %d - ", *game->size_a);
	printf("size B: %d\n\n", *game->size_b);
	i = 0;
	while (i < *game->size)
	{
		printf("%d - ", game->sequence[i]);
		i++;
	}
	return (0);
}
	
/*
static int	check_stack_a(t_game *game)
{
	t_stack	*temp;
	t_stack	*next;
	
	printf("check_stack_a\n");
	if (game->size_a == NULL)
		return (1);
	if (game->stack_a->next == NULL)
		return (1);
	temp = game->stack_a;
	next = game->stack_a->next;
	while(*next->content > *temp->content)
	{
		if (next->next == NULL)
				return (1);
		temp = next;
		next = temp->next;
	}
	return (0);
}

*/
/*
static	int	check(t_game *game)
{
	t_stack *temp;
	t_stack *temp_next;
	
	temp = game->stack_a;
	temp_next = game->stack_a->next;
	while (temp->next != NULL)
	{
		if (*temp->content > *temp_next->content)
			return (0);
		temp = temp_next;
		temp_next = temp_next->next;
		printf("%d", *temp->content);
		if (temp->next != NULL)
			printf("%d", *temp_next->content);
	}
	return (1);
}
*/

//Verify if stack_a > stack_a->next
/*static void	check_top_next(t_game *game)
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
			{
				printf("top > next stack && top b < next b linha 99\n");
				cmd_ss(game);
			}
			else
			{
				cmd_sa(game);
				printf("top > next stack && top b > next b\n");
			}
		}
		else
		{
			cmd_sa(game);
			printf("top > next && stack B == NULL\n");
		}
	}
	else
	{
		printf("top < next");
	}
	ps_print_lst(game->stack_a);
	ps_print_lst(game->stack_b);
}

static void	check_top_botton_b(t_game *game, int i)
{
	printf("check_top_botton B\n");
	if (*game->top_b->content < *game->botton_b->content)
	{
		if (i == 0)
		{
			printf("top B < botton B\n");
			cmd_rrr(game);
		}
		else if (i == 1)
		{
			printf("top B < botton B\n");
			cmd_rr(game);
		}
	}
	else
	{
		if (i == 0)
		{
			printf("top B > botton B\n");
			cmd_rra(game);
		}
		else if (i == 1)
		{
			printf("top B > botton B\n");
			cmd_ra(game);
		}
	}

	
}

static void	check_top_botton(t_game *game, int i)
{
	printf("check_top_botton\n");
	if (*game->top_a->content < *game->botton_a->content)
	{
		if (i == 0)
		{
			printf("top A < botton A i= 0\n");
			cmd_pb(game);
		}
		else if (i == 1)
		{
			if (game->stack_b == NULL || game->stack_b->next == NULL)
			{
				printf("top A < botton A i= 1 B= NULL\n");
				cmd_ra(game);
			}
			else
			{
				
				cmd_rrr(game);
			}
		}
	}
	else
	{
		if (i == 0)
		{
			if (game->stack_b == NULL || game->stack_b->next == NULL)
			{	
				printf("top A > botton A Stack B = NULL\n");
				cmd_pb(game);
			}	
			else
			{
				check_top_botton_b(game, i);	
				printf("top A > botton A Stack B != NULL\n");
			}
		}
		else if (i == 1)
		{
			cmd_ra(game);
		}
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
		{
			printf("botton_a - b menor i = 0\n");
			check_top_botton(game, 0);
		}
		else if (i == 1)
		{
			cmd_rra(game);
		}
	}
	else
	{
		if (i == 0)
		{
			printf("botton_a - a menor i = 0\n");
			cmd_pb(game);
		}	
		else if (i == 1)
		{
			printf("botton_a - a menor i= 1\n");
			check_top_botton(game, 1);
		}
	
	}
}

static void	check_top_pos(t_game *game)
{
	int	a;
	int	b;
	
	a = *game->top_a->pos - *game->size_b;
	if (a < 0)
		a = a * -1;
	b = *game->top_a->pos - *game->size_b;
	if (b < 0)
		b = b * -1;
	printf("check_top_pos\n");
	if (a <= b)
	{
		printf("top_a - b menor i= 0\n");
		check_botton_pos(game, 0);		
	}
	else
	{
		printf("top_a - a menor i = 1\n");
		check_botton_pos(game, 1);	
	}
	ps_print_lst(game->stack_a);
	ps_print_lst(game->stack_b);	
}

int	solution_ps2(t_game *game)
{
	int		steps;
	int		flag;
	int		i;
	
	ps_print_lst(game->stack_a);
	
	steps = 0;
	flag = 0;
	while (flag < 5)
	{
		while (check_stack_a(game) != 1)
		{
			check_top_next(game);
			if (check_stack_a(game) != 1)
				check_top_pos(game);
		}
		flag++;
		printf("\n\nflag : %d - ", flag);
		
	}
	printf("\n\nsteps : %d - ", steps);
	printf("size: %d - ", *game->size);
	printf("size A: %d - ", *game->size_a);
	printf("size B: %d\n\n", *game->size_b);
	i = 0;
	while (i < *game->size)
	{
		printf("%d - ", game->sequence[i]);
		i++;
	}
	return (0);
}
*/
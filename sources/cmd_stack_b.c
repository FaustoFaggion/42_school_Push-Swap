/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:48:42 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/29 10:40:45 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sb : swap b - swap the first 2 elements at the top of stack b.
		Do nothing if there is only one or no elements).*/
int	cmd_sb(t_game *game, int i)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_b == NULL)
		return (0);
	if (game->stack_b->next == NULL)
		return (0);
	swap = game->stack_b;
	game->stack_b = game->stack_b->next;
	temp = game->stack_b->next;
	swap->previous = swap->next;
	swap->next = game->stack_b->next;
	game->stack_b->next = swap;
	game->stack_b->previous = NULL;
	if (temp != NULL)
		temp->previous = swap;
	if (i == 1)
		write(1, "sb\n", 3);
	game->top_b = game->stack_b;
	game->next_b = game->top_b->next;
	game->botton_b = ps_lstlast(game->stack_b);
	return (0);
}

/*rb : rotate b - shift up all elements of stack b by 1.
		The first element becomes the last one.*/
int	cmd_rb(t_game *game, int i)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_b == NULL)
		return (0);
	if (game->stack_b->next == NULL)
		return (0);
	swap = game->stack_b;
	temp = game->stack_b;
	while (temp->next != NULL)
		temp = temp->next;
	game->stack_b = game->stack_b->next;
	game->stack_b->previous = NULL;
	swap->previous = temp;
	swap->next = NULL;
	temp->next = swap;
	if (i == 1)
		write(1, "rb\n", 3);
	game->top_b = game->stack_b;
	game->next_b = game->top_b->next;
	game->botton_b = ps_lstlast(game->stack_b);
	return (0);
}

/*rrb : reverse rotate b - shift down all elements of stack b by 1.
		The last element becomes the first one.*/
int	cmd_rrb(t_game *game, int i)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_b == NULL)
		return (0);
	if (game->stack_b->next == NULL)
		return (0);
	swap = game->stack_b;
	while (game->stack_b->next != NULL)
		game->stack_b = game->stack_b->next;
	game->stack_b->next = swap;
	temp = game->stack_b->previous;
	temp->next = NULL;
	game->stack_b->previous = NULL;
	swap->previous = game->stack_b;
	if (i == 1)
		write(1, "rrb\n", 4);
	game->top_b = game->stack_b;
	game->next_b = game->top_b->next;
	game->botton_b = ps_lstlast(game->stack_b);
	return (0);
}

static void	fill_game(t_game *game)
{
	write(1, "pa\n", 3);
	if (game->stack_b != NULL)
	{
		game->top_b = game->stack_b;
		game->next_b = game->top_b->next;
		game->botton_b = ps_lstlast(game->stack_b);
	}
	if (game->stack_a != NULL)
	{
		game->top_a = game->stack_a;
		game->next_a = game->stack_a->next;
		game->botton_a = ps_lstlast(game->stack_a);
	}
	game->size_b = game->size_b - 1;
	game->size_a = game->size_a + 1;
}

/*pa : push a - take the first element at the top of b and put it at
		the top of a. Do nothing if b is empty.*/
int	cmd_pa(t_game *game)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_b == NULL)
	{
		game->top_b = NULL;
		game->botton_b = NULL;
		return (0);
	}
	swap = game->stack_b;
	if (game->stack_b->next != NULL)
	{
		game->stack_b = swap->next;
		game->stack_b->previous = NULL;
	}
	else if (game->stack_b->next == NULL)
		game->stack_b = NULL;
	temp = game->stack_a;
	game->stack_a = swap;
	game->stack_a->next = temp;
	game->stack_a->previous = NULL;
	if (temp != NULL)
		temp->previous = game->stack_a;
	fill_game(game);
	return (0);
}

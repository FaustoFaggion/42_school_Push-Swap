/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:46:17 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/29 13:53:38 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd(t_game *game, char cmd[3])
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		cmd_sa(game, 1);
	if (ft_strncmp(cmd, "ra", 2) == 0)
		cmd_ra(game, 1);
	if (ft_strncmp(cmd, "rra", 3) == 0)
		cmd_rra(game, 1);
	if (ft_strncmp(cmd, "pb", 2) == 0)
		cmd_pb(game);
	if (ft_strncmp(cmd, "sb", 2) == 0)
		cmd_sb(game, 1);
	if (ft_strncmp(cmd, "rb", 2) == 0)
		cmd_rb(game, 1);
	if (ft_strncmp(cmd, "rrb", 3) == 0)
		cmd_rrb(game, 1);
	if (ft_strncmp(cmd, "pa", 2) == 0)
		cmd_pa(game);
}

static void	fill_game(t_game *game, char cmd[3])
{
	if (game->stack_a != NULL)
	{
		game->top_a = game->stack_a;
		game->next_a = game->top_a->next;
		game->botton_a = ps_lstlast(game->stack_a);
	}
	if (game->stack_b != NULL)
	{
		game->top_b = game->stack_b;
		game->next_b = game->stack_b->next;
		game->botton_b = ps_lstlast(game->stack_b);
	}
	if (ft_strncmp(cmd, "pb", 2) == 0)
	{
		write(1, "pb\n", 3);
		game->size_a = game->size_a - 1;
		game->size_b = game->size_b + 1;
	}
}

/*sa : swap a - swap the first 2 elements at the top of stack a.
		Do nothing if there  is only one or no elements).*/
int	cmd_sa(t_game *game, int i)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_a == NULL)
		return (0);
	if (game->stack_a->next == NULL)
		return (0);
	swap = game->stack_a;
	game->stack_a = game->stack_a->next;
	temp = game->stack_a->next;
	swap->previous = swap->next;
	swap->next = game->stack_a->next;
	game->stack_a->next = swap;
	game->stack_a->previous = NULL;
	if (temp != NULL)
		temp->previous = swap;
	if (i == 1)
		write(1, "sa\n", 3);
	fill_game(game, "sa");
	return (0);
}

/*ra : rotate a - shift up all elements of stack a by 1.
		The first element becomes the last one.*/

int	cmd_ra(t_game *game, int i)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_a == NULL)
		return (0);
	if (game->stack_a->next == NULL)
		return (0);
	swap = game->stack_a;
	temp = game->stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	game->stack_a = game->stack_a->next;
	game->stack_a->previous = NULL;
	swap->previous = temp;
	swap->next = NULL;
	temp->next = swap;
	if (i == 1)
		write(1, "ra\n", 3);
	fill_game(game, "ra");
	return (0);
}

/*rra : reverse rotate a - shift down all elements of stack a by 1.
		The last element becomes the first one.*/

int	cmd_rra(t_game *game, int i)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_a == NULL)
		return (0);
	if (game->stack_a->next == NULL)
		return (0);
	swap = game->stack_a;
	while (game->stack_a->next != NULL)
		game->stack_a = game->stack_a->next;
	game->stack_a->next = swap;
	temp = game->stack_a->previous;
	temp->next = NULL;
	game->stack_a->previous = NULL;
	swap->previous = game->stack_a;
	if (i == 1)
		write(1, "rra\n", 4);
	fill_game(game, "rra");
	return (0);
}

/*pb : push b - take the first element at the top of a and put it at 
		the top of b. Do nothing if a is empty.*/
int	cmd_pb(t_game *game)
{
	t_stack	*swap;
	t_stack	*temp;

	if (game->stack_a == NULL)
	{
		game->top_a = NULL;
		game->botton_a = NULL;
		return (0);
	}
	swap = game->stack_a;
	if (game->stack_a->next != NULL)
	{
		game->stack_a = swap->next;
		game->stack_a->previous = NULL;
	}
	else if (game->stack_a->next == NULL)
		game->stack_a = NULL;
	temp = game->stack_b;
	game->stack_b = swap;
	game->stack_b->next = temp;
	game->stack_b->previous = NULL;
	if (temp != NULL)
		temp->previous = game->stack_b;
	fill_game(game, "pb");
	return (0);
}

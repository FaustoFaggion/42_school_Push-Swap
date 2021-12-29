/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:41:09 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/29 10:21:36 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Function discover the biggest and smallest numbers, then take the median
	point */
void	cut_point(t_game *game, t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	game->major = 0;
	while (temp != NULL)
	{
		if (temp->pos > game->major)
			game->major = temp->pos;
		temp = temp->next;
	}
	temp = stack;
	game->minor = game->major;
	while (temp != NULL)
	{
		if (temp->pos < game->minor)
			game->minor = temp->pos;
		temp = temp->next;
	}
	game->cut_point = game->minor + ((game->major - game->minor) / 2);
}

/*	Function check if there is any number on the stack with a position smaller
	than cut_point */
int	check_pos(t_game *game, char c)
{
	t_stack	*temp;

	if (c == 'a')
	{
		temp = game->stack_a;
		while (temp != NULL)
		{
			if (temp->pos <= game->cut_point)
				return (0);
			temp = temp->next;
		}
	}
	if (c == 'b')
	{
		temp = game->stack_b;
		while (temp != NULL)
		{
			if (temp->pos > game->cut_point)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

/* Function verify if the stack A is ordered */
int	check_stack_a(t_game *game)
{
	t_stack	*temp;
	t_stack	*temp_next;

	temp = game->stack_a;
	temp_next = game->stack_a->next;
	while (temp->next != NULL)
	{
		if (temp->pos != (temp_next->pos - 1))
			return (0);
		temp = temp_next;
		temp_next = temp_next->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:23:12 by fausto            #+#    #+#             */
/*   Updated: 2021/12/28 19:30:55 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			temp = stack;
			stack = stack->next;
			free(temp);
		}
		free(stack);
	}
}

static void	free_array(int *array)
{
	if (array != NULL)
		free(array);
}

int	exit_ps(t_game *game)
{
	free_stack(game->stack_a);
	free_stack(game->stack_b);
	free_array(game->args);
	return (0);
}

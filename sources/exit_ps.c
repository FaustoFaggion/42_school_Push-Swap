/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:23:12 by fausto            #+#    #+#             */
/*   Updated: 2021/11/22 11:44:22 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack *temp;

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

static void	free_size(int *size)
{
	if (size != NULL)
		free(size);
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
	free_size(game->size);
	free_size(game->size_a);
	free_size(game->size_b);
	free_array(game->args);
	free_array(game->sequence);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:23:12 by fausto            #+#    #+#             */
/*   Updated: 2021/11/20 11:39:35 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_ps(t_game *game)
{
	t_stack *temp;
	
	if (game->args != NULL)
		free(game->args);
	if (game->stack_a != NULL)
	{
		while (game->stack_a->next != NULL)
		{
			temp = game->stack_a;
			game->stack_a = game->stack_a->next;
			free(temp);
		}
		free(game->stack_a);
	}
	if (game->stack_b != NULL)
	{
		while (game->stack_b->next != NULL)
		{
			temp = game->stack_b;
			game->stack_b = game->stack_b->next;
			free(temp);
		}
		free(game->stack_b);
	}
	return (0);
}

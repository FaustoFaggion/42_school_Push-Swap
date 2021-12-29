/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:08:34 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/29 10:56:24 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Function place the first number in the botton of stack */
static void	pos_1(t_game *game)
{
	if (check_stack_a(game) != 0)
		cmd_pa(game);
	else
	{
		cmd_pa(game);
		cmd_ra(game, 1);
	}
}

/*	Function send numbers smaller then median point to stack A.
	Assign a cut point in the last number of the chunck sent to stack A */
void	run_b(t_game *game)
{
	while (check_pos(game, 'b') != 1)
	{
		if (game->botton_b->pos == game->botton_a->pos + 1
			|| game->botton_b->pos == 1)
			cmd_rrb(game, 1);
		if (game->top_b->pos == 1)
			pos_1(game);
		else if (game->top_b->pos >= game->cut_point)
			cmd_pa(game);
		else
		{
			if (game->top_b->pos == game->botton_a->pos + 1)
			{
				cmd_pa(game);
				cmd_ra(game, 1);
			}
			else
				cmd_rb(game, 1);
		}
	}
	game->top_a->cut_point = 1;
}

/*	Function send the numbers from A to B from only one chunck of numbers.
	This chuncks where marked on run_b function by setting a value 1 on the
	cut_pont of the last numbers of the chunck sent to A.*/
void	to_b(t_game *game)
{
	if (game->top_a->pos != game->botton_a->pos + 1)
		cmd_pb(game);
	else
		cmd_ra(game, 1);
	if (game->size_b == 1 && game->top_a->cut_point == 1)
		cmd_pb(game);
	while (game->top_a->cut_point != 1)
	{
		if (game->top_a->pos != game->botton_a->pos + 1)
			cmd_pb(game);
		else
			cmd_ra(game, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:08:34 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/31 11:50:06 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Function place the first number in the botton of stack */
static void	pos_1(t_game *game)
{
	if (check_stack_a(game) != 0)
		cmd(game, "pa");
	else
	{
		cmd(game, "pa");
		cmd(game, "ra");
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
			cmd(game, "rrb");
		if (game->top_b->pos == 1)
			pos_1(game);
		else if (game->top_b->pos >= game->cut_point)
			cmd(game, "pa");
		else
		{
			if (game->top_b->pos == game->botton_a->pos + 1)
			{
				cmd(game, "pa");
				cmd(game, "ra");
			}
			else
				cmd(game, "rb");
		}
	}
	game->top_a->cut_point = 1;
}

/*	Function send the numbers from A to B from only one chunck of numbers.
	This chuncks where marked on run_b function by setting a value 1 on the
	cut_pont of the last numbers of the chunck sent to A.*/
void	to_b(t_game *game)
{
	game->top_a->cut_point = 0;
	if (game->top_a->pos != game->botton_a->pos + 1)
		cmd(game, "pb");
	else
		cmd(game, "ra");
	if (game->size_b == 1 && game->top_a->cut_point == 1)
	{
		game->top_a->cut_point = 0;
		cmd(game, "pb");
	}
	while (game->top_a->cut_point != 1)
	{
		if (game->top_a->pos != game->botton_a->pos + 1)
			cmd(game, "pb");
		else
			cmd(game, "ra");
	}
}

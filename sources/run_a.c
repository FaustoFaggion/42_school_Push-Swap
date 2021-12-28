/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:46:54 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/28 17:48:28 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_a(t_game *game)
{
	while (check_pos(game, 'a') != 1)
	{
		if (game->top_a->pos <= game->cut_point)
			cmd_pb(game);
		else
		{
			if (game->stack_b != NULL)
			{
				if (game->top_b->pos > (game->cut_point / 2))
					cmd_ra(game, 1);
				else
					cmd_rr(game);
			}
			else
				cmd_ra(game, 1);
		}
	}
	game->top_a->cut_point = 1;
}

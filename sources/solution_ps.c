/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/28 19:33:21 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_3(t_game *game)
{
	if (game->top_a->pos > game->next_a->pos)
		cmd_sa(game, 1);
	while (game->botton_a->pos < game->top_a->pos)
		cmd_rra(game, 1);
	if (check_stack_a(game) != 0)
		return ;
	cmd_rra(game, 1);
	cmd_sa(game, 1);
}

static void	run_5(t_game *game)
{
	while (game->size_a != 3)
	{
		if (game->top_a->pos <= 2)
			cmd_pb(game);
		else
			cmd_ra(game, 1);
	}
	run_3(game);
	if (game->top_b->pos < game->next_b->pos)
		cmd_sb(game, 1);
	cmd_pa(game);
	cmd_pa(game);
}

static void	to_b_to_a(t_game *game)
{
	to_b(game);
	if (game->size_b > CUT_POINT)
	{
		cut_point(game, game->stack_b);
		run_b(game);
	}
	to_a(game);
	if (check_stack_a(game) != 0 && game->stack_b == NULL)
		return ;
}

int	solution_ps(t_game *game)
{
	if (check_stack_a(game) != 0)
		return (0);
	if (game->size_a == 5)
		run_5(game);
	if (game->size_a <= 3)
		run_3(game);
	if (check_stack_a(game) != 0)
		return (0);
	cut_point(game, game->stack_a);
	run_a(game);
	while (game->size_b > 1)
	{
		cut_point(game, game->stack_b);
		run_b(game);
	}
	if (check_stack_a(game) != 0 && game->stack_b == NULL)
		return (0);
	while (check_stack_a(game) != 1)
		to_b_to_a(game);
	return (0);
}

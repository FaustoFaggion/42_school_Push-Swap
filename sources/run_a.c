/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:46:54 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/29 14:06:01 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_way(t_game *game)
{
	t_stack	*temp;

	game->minor_b = 0;
	temp = game->stack_b;
	while (temp->pos != game->minor)
	{
		game->minor_b++;
		temp = temp->next;
	}
	game->major_b = 0;
	temp = game->stack_b;
	while (temp->pos != game->major)
	{
		game->major_b++;
		temp = temp->next;
	}
}

static void	go_minor(t_game *game)
{
	if (game->minor_b < (game->size_b - game->major_b))
	{
		while (game->top_b->pos != game->minor)
		{
			if (game->top_b->pos == game->minor_b + 1)
				cmd(game, "pa");
			cmd(game, "rb");
		}
		cmd(game, "pa");
		cmd(game, "ra");
	}
	else
	{
		while (game->top_b->pos != game->major)
		{
			if (game->top_b->pos == game->major_b - 1)
				cmd(game, "pa");
			cmd(game, "rrb");
		}
		cmd(game, "pa");
		if (game->top_a->pos == game->next_a->pos + 1)
			cmd(game, "sa");
	}
}

static void	go_major(t_game *game)
{
	if (game->major_b < (game->size_b - game->minor_b))
	{
		while (game->top_b->pos != game->major)
		{
			if (game->top_b->pos == game->major_b - 1)
				cmd(game, "pa");
			cmd(game, "rb");
		}
		cmd(game, "pa");
		if (game->top_a->pos == game->next_a->pos + 1)
			cmd(game, "sa");
	}
	else
	{
		while (game->top_b->pos != game->minor)
		{
			if (game->top_b->pos == game->minor_b + 1)
				cmd(game, "pa");
			cmd(game, "rrb");
		}
		cmd(game, "pa");
		cmd(game, "ra");
	}
}

void	to_a(t_game *game)
{
	if (game->stack_b == NULL)
		return ;
	while (game->next_b != NULL)
	{
		cut_point(game, game->stack_b);
		choose_way(game);
		if (game->minor_b < game->major_b)
			go_minor(game);
		else
			go_major(game);
	}
	cmd_pa(game);
	while (game->top_a->pos == game->botton_a->pos + 1)
		cmd_ra(game, 1);
}

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
				if (game->top_b->pos < (game->cut_point / 2) 
					&& game->top_b->pos != 1)
					cmd_rr(game);
				else
					cmd(game, "ra");
			}
			else
				cmd(game, "ra");
		}
	}
	game->top_a->cut_point = 1;
}

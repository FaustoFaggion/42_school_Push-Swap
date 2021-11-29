/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psD.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/28 21:02:14 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sa(t_game *game)
{
	if (game->stack_b != NULL)
	{
		if (game->next_b != NULL)
		{
			if (*game->top_b->pos < game->size / 4 && game->next_b->pos > game->top_b->pos)
				cmd_rb(game, 1);
			else
			{
				if (game->next_b->pos > game->top_b->pos)
					cmd_ss(game);
				else
					cmd_sa(game, 1);
			}
		}
		else
			cmd_sa(game, 1);
	}
	else if (game->stack_b == NULL)
		cmd_sa(game, 1);
}

static void	check_ra(t_game *game)
{
	if (game->stack_b != NULL)
	{
		if (game->next_b != NULL)
		{
			if (game->botton_b->pos > game->top_b->pos 
				|| (*game->top_b->pos < game->size_b / 2))
				cmd_rr(game);
			else
				cmd_ra(game, 1);
		}
		else
			cmd_ra(game, 1);
	}
	else if (game->stack_b == NULL)
		cmd_ra(game, 1);
}

static void	check_rra(t_game *game)
{
	if (game->stack_b != NULL)
	{
		if (game->next_b != NULL)
		{
			if (game->botton_b->pos > game->top_b->pos 
				|| (*game->botton_b->pos > game->size_b / 2))
				cmd_rrr(game);
			else
				cmd_rra(game, 1);
		}
		else
			cmd_rra(game, 1);
	}
	else if (game->stack_b == NULL)
		cmd_rra(game, 1);
}

static void	check_pb(t_game *game)
{
	if (game->stack_b != NULL)
	{
		if (game->top_b->next != NULL)
		{
			if (*game->top_b->pos < game->size / 4 && game->next_b->pos > game->top_b->pos)
				cmd_rb(game, 1);
			else
				cmd_pb(game);
		}
		else
			cmd_pb(game);
	}
	else
		cmd_pb(game);
}

static	int	check_stack_a(t_game *game)
{
	t_stack *temp;
	t_stack *temp_next;
	
	temp = game->stack_a;
	temp_next = game->stack_a->next;
	while (temp->next != NULL)
	{
		if (*temp->pos != (*temp_next->pos - 1))
			return (0);
		temp = temp_next;
		temp_next = temp_next->next;
	}
	return (1);
}

static	int	check_median(t_game *game)
{
	if ((game->size / game->index) < game->size_a)
		return (0);
	return (1);
}
/*
static void	check_rrb(t_game *game)
{
	if (game->stack_a != NULL)
	{
		if (game->next_a != NULL)
		{
			if (game->botton_a->pos > game->next_b->pos && *game->botton_a->pos < (game->size))
				cmd_rrr(game);
			else
				cmd_rrb(game, 1);
		}
		else
			cmd_rrb(game, 1);
	}
	else if (game->stack_b == NULL)
		cmd_rrb(game, 1);
}
*/
static	int	check_median_b(t_game *game)
{
		if ((game->size) - (game->size / game->index) < game->size_b)
			return (0);
	return (1);
}

static void run_a(t_game *game)
{
	while (check_stack_a(game) != 1)
	{
		while (check_median(game) != 1 && check_stack_a(game) != 1)
		{
			if (*game->botton_a->pos <= (game->size - (game->size / game->index)))
				check_rra(game);
			else if (*game->next_a->pos <= (game->size - (game->size / game->index)))
			{
				if (*game->top_a->pos <= (game->size - (game->size / game->index)))
				{
					if (game->top_a->pos < game->next_a->pos)
						check_pb(game);
					else
						check_sa(game);
				}
				else
				{
					check_ra(game);
				}
			}
			else if (*game->next_a->pos > (game->size - (game->size / game->index)))
			{	
				if (*game->top_a->pos <= (game->size - (game->size / game->index)))
					check_pb(game);
				else
					check_ra(game);
			}
		}
		if (DEBUG)
			print_stack(game);
		game->index++;
	}
}

static void run_b(t_game *game)
{
	
			while (check_median_b(game) != 1)
			{
				if (game->top_a->pos == game->top_b->pos + 1)
					cmd_pa(game);
				else
				{
					if (game->stack_b->next != NULL)
					{
						if (game->top_b->pos < game->botton_b->pos)
						{
							cmd_rrb(game, 1);
							cmd_pa(game);
						}
						else
						{
							if (game->top_a->pos == game->next_b->pos + 1)
								cmd_sb(game, 1);
							else
								if (game->botton_b->pos < game->top_b->pos)
									cmd_rb(game, 1);
								else
									cmd_pa(game);
						}
					}
					else
						cmd_pa(game);
				}
				if (DEBUG)
					print_stack(game);
			}			
}

int	solution_psD(t_game *game)
{
	game->index = 2;
	
	run_a(game);

	while (game->index > 0)
	{
//		while (check_stack_a(game) != 1 && check_median_b(game) != 0)
//		{
//			printf("############");
			run_b(game);
			run_a(game);
//		}
		game->index--;
	}
//	printf("OK\n");
	return (1);
}

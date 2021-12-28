/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psH.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/28 18:19:24 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void run_3(t_game *game)
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

static void	to_a(t_game *game)
{
	t_stack	*temp;
	int		minor;
	int		major;
	
	if (game->stack_b == NULL)
		return ;
	while (game->next_b != NULL)
	{
		cut_point(game, game->stack_b);
		minor = 0;
		temp = game->stack_b;
		while (temp->pos != game->minor)
		{
			minor++;
			temp = temp->next;
		}
		major = 0;
		temp = game->stack_b;
		while (temp->pos != game->major)
		{
			major++;
			temp = temp->next;
		}
		if (minor < major)
		{
			if (minor < (game->size_b - major))
			{
				while(game->top_b->pos != game->minor)
				{
					if (game->top_b->pos == minor + 1)
						cmd_pa(game);
					cmd_rb(game, 1);
				}
				cmd_pa(game);
				cmd_ra(game, 1);
			}
			else
			{
				while(game->top_b->pos != game->major)
					cmd_rrb(game, 1);
				cmd_pa(game);
				if(DEBUG != 0)
					print_stack(game);
			}
		}
		else
		{
			if (major < (game->size_b - minor))
			{
				while(game->top_b->pos != game->major)
					cmd_rb(game, 1);
				cmd_pa(game);
			}
			else
			{
				while(game->top_b->pos != game->minor)
				{
					if (game->top_b->pos == minor + 1)
						cmd_pa(game);
					cmd_rrb(game, 1);
				}
				cmd_pa(game);
				cmd_ra(game, 1);
				if (game->top_a->pos == minor + 1)
					cmd_ra(game, 1);
			}
		}
	}
	cmd_pa(game);
	while (game->top_a->pos == game->botton_a->pos + 1)
		cmd_ra(game, 1);
}

static void	to_b(t_game *game)
{
	if(DEBUG != 0)
		printf("to_b\n");
	if (game->top_a->pos != game->botton_a->pos + 1)
	{
		if(DEBUG != 0)
			printf("(22)\n");
		cmd_pb(game);
		if(DEBUG != 0)
			print_stack(game);
	}
	else
		cmd_ra(game, 1);
	if (game->size_b == 1 && game->top_a->cut_point == 1)
		cmd_pb(game);
	while (game->top_a->cut_point != 1)
	{
		if (game->top_a->pos != game->botton_a->pos + 1)
		{
			if(DEBUG != 0)
				printf("(23)\n");
			cmd_pb(game);
		}	
		else
		{
			if(DEBUG != 0)
				printf("(24)\n");
			cmd_ra(game, 1);
		}
		if(DEBUG != 0)
			print_stack(game);
	}
}

int	solution_psH(t_game *game)
{
//	int	x;
//	x = 0;
	
	if (check_stack_a(game) != 0)
		return (0);
	if (game->size_a == 5)
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
	if (game->size_a <= 3)
		run_3(game);
	if (check_stack_a(game) != 0)
		return (0);
	cut_point(game, game->stack_a);
	if(DEBUG != 0)
		print_stack(game);
	run_a(game);
	if (check_stack_a(game) != 0 && game->stack_b == NULL)
		return (0);
	while (game->size_b > 1)
	{
		cut_point(game, game->stack_b);
		run_b(game);
	}
	if (check_stack_a(game) != 0 && game->stack_b == NULL)
		return (0);

	while (check_stack_a(game) != 1)
//	while (x < 10)
	{
		to_b(game);
		if (game->size_b > CUT_POINT)
		{
				cut_point(game, game->stack_b);
				run_b(game);
		}
		to_a(game);
		if (check_stack_a(game) != 0 && game->stack_b == NULL)
			return (0);
//		x++;
	}	
	return(0);
}

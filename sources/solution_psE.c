/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psE.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/03 09:48:59 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	check_major(t_game *game)
{
	t_stack *temp;
	int	int_max;
	
	temp = game->top_b;
	int_max = game->top_b->content;
	if (game->top_b->next != NULL)
	{
		while(temp)
		{
			if(temp->content > int_max)
				int_max = temp->content;
			temp = temp->next;
		}
	}
	return (int_max); 
}
*/
static void	run_a(t_game *game)
{
	while(game->cut_point <= game->top_a->pos)
	{
		if (game->top_a->pos <= game->cut_point)
			cmd_pb(game);
		else
			cmd_ra(game, 1);
		if(DEBUG != 0)
			print_stack(game);
	}
	printf("\n######### finish run_a #########\n");
	game->top_a->cut_point = 1;
}
/*
static void	run_b_1(t_game *game)
{
	while((game->size_b / game->index) < game->size_b)
	{
		if (game->top_b->pos == 1)
		{
			cmd_pa(game);
			cmd_ra(game, 1);
		}
		if (game->top_a->pos == game->botton_a->pos + 1)
			cmd_ra(game, 1);
		if(game->top_b->pos > ((game->size_b / game->index)))
			cmd_pa(game);
		else
			cmd_rb(game, 1);
		if(DEBUG != 0)
			print_stack(game);
	}
	printf("\n#####################3######### finish run_b1 #########\n");
	game->top_a->cut_point = 1;
}

static void	to_a(t_game *game)
{
	int	major;

	while (game->next_b != NULL)
	{
		major = check_major(game);
		while(game->top_b->content != major)
		{
			if (game->top_b->pos == game->botton_a->pos + 1)
			{
				cmd_pa(game);
				cmd_ra(game, 1);
			}
			else
				cmd_rb(game, 1);
			if(DEBUG != 0)
			print_stack(game);
		}
		cmd_pa(game);
		if(DEBUG != 0)
			print_stack(game);
	}
	if (game->top_b->pos == game->botton_a->pos + 1)
	{
		cmd_pa(game);
		cmd_ra(game, 1);
		if(DEBUG != 0)
			print_stack(game);
	}
	else
		cmd_pa(game);
	while (game->top_a->pos == game->botton_a->pos + 1)
		cmd_ra(game, 1);
	if(DEBUG != 0)
			print_stack(game);
	printf("\n######### finish to_a #########\n");
}

static void	to_b(t_game *game)
{
	if (game->top_a->pos != game->botton_a->pos - 1)
	{
		cmd_pb(game);
		if(DEBUG != 0)
			print_stack(game);
	}
	while (game->top_b->cut_point != 1)

			cmd_pb(game);
		if(DEBUG != 0)
			print_stack(game);
	}
	printf("\n######### finish to_b #########\n");
}
*/
int	solution_psE(t_game *game)
{
	int i;

	i = 0;
	
	game->cut_point = game->size_a - (game->size_a / 2);
	run_a(game);
	game->index = game->index * 2;
/*	while (game->size_b > CUT_POINT)
	{
		run_b_1(game);
		game->index = game->index * 2;
	}
	while (i < 5)
	{

		to_b(game);
		to_a(game);
		if(DEBUG != 0)
			print_stack(game);
		i++;
	}
*/	
	return(0);
}	


/*	while (game->stack_b != NULL)
	{
		int	max;

		printf("\n############until next_b != NULL################\n");
		if (game->top_b->pos == game->botton_a->pos + 1)
		{
			cmd_pa(game);
			cmd_ra(game, 1);
		}
		else
		{
			if (check_major(game))
				cmd_pa(game);
			else
				cmd_rb(game, 1);
		}
		if(DEBUG != 0)
			print_stack(game);
	}
*/
/*
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
*/
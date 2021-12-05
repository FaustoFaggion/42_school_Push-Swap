/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psF.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/05 12:12:14 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cut_point(t_game *game, t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	
	game->major = 0;
	while (temp != NULL)
	{
		if (temp->pos > game->major)
			game->major = temp->pos;
		temp = temp->next;
	}
	temp = stack;
	game->minor = game->major;
	while (temp != NULL)
	{
		if (temp->pos < game->minor)
			game->minor = temp->pos;
		temp = temp->next;
	}
	game->cut_point = game->minor + ((game->major - game->minor) / 2);
	
}

static int	check_pos(t_game *game, char c)
{
	t_stack	*temp;
	
	if (c == 'a')
	{
		temp = game->stack_a;
		while(temp != NULL)
		{
			if(temp->pos < game->cut_point)
				return (0);
			temp = temp->next;
		}
		
	}
	if (c == 'b')
	{
		temp = game->stack_b;
		while(temp != NULL)
		{
			if(temp->pos > game->cut_point)
				return (0);
			temp = temp->next;
		}
		
	}
	return (1);
}

static void	run_a(t_game *game)
{
	while(check_pos(game, 'a') != 1)
	{
		if (game->top_a->pos <= game->cut_point)
			cmd_pb(game);
		else
			cmd_ra(game, 1);
		if(DEBUG != 0)
			print_stack(game);
	}
//	printf("\n######### finish run_a #########\n");
	game->top_a->cut_point = 1;
}

static void	run_b_1(t_game *game)
{
	while(check_pos(game, 'b') != 1)
	{
		if (game->top_b->pos == 1)
		{
			game->top_b->cut_point = 1;
			cmd_pa(game);
			cmd_ra(game, 1);
		}
		if (game->top_b->pos >= game->cut_point)
		{
				cmd_pa(game);
		}
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
		if(DEBUG != 0)
			print_stack(game);
	}
//	printf("\n#####################3######### finish run_b1 #########\n");
	game->top_a->cut_point = 1;
}


static void	to_a(t_game *game)
{

	while (game->next_b != NULL)
	{
		cut_point(game, game->stack_b);
		while(game->top_b->pos != game->major)
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
	while (game->top_a->cut_point != 1)
	{
		if (game->top_a->pos != game->botton_a->pos - 1)
			cmd_pb(game);
		else
			cmd_ra(game, 1);
		if(DEBUG != 0)
			print_stack(game);
	}
//	printf("\n######### finish to_b #########\n");
}

static	int	check_stack_a(t_game *game)
{
	t_stack *temp;
	t_stack *temp_next;
	
	temp = game->stack_a;
	temp_next = game->stack_a->next;
	while (temp->next != NULL)
	{
		if (temp->pos != (temp_next->pos - 1))
			return (0);
		temp = temp_next;
		temp_next = temp_next->next;
	}
	return (1);
}

int	solution_psF(t_game *game)
{
	cut_point(game, game->stack_a);
	run_a(game);
	while (game->size_b > 1)
	{
		cut_point(game, game->stack_b);
		run_b_1(game);
	}
	while (check_stack_a(game) != 1)
	{
		to_b(game);
		if (game->size_b > CUT_POINT)
		{
				cut_point(game, game->stack_b);
				run_b_1(game);
		}
		to_a(game);
	}	
	return(0);
}





/*
static void	to_a_1(t_game *game)
{
	t_stack *temp;
	int	major;
	int	minor;


	while (game->stack_b != NULL)
	{
		
		major = 0;
		minor = 0;
		cut_point(game, game->stack_b);
		temp = game->stack_b;
		if (temp->pos == game->botton_a->pos + 1)
		{
			cmd_pa(game);
			cmd_ra(game, 1);
		}
		else if (temp->pos == game->top_a->pos - 1)
			cmd_pa(game);
		else if (temp->next != NULL)
		{
			while (temp->pos != game->major)
			{
				major++;
				temp = temp->next;
			}
			temp = game->stack_b;
			while (temp->pos != game->minor)
			{
				minor++;
				temp = temp->next;
			}
			if (game->top_b->pos == major)
				cmd_pa(game);
			if (game->top_b->pos == minor)
			{
				cmd_pa(game);
				cmd_ra(game, 1);
			}	
			if (major > minor)
			{
				if ((major - game->size_b) < minor)
				{
					while(game->top_b->pos != game->major )
						cmd_rrb(game, 1);
					cmd_pa(game);
				}
				else
				{
					while (game->top_b->pos != game->minor)
						cmd_rb(game, 1);
					cmd_pa(game);
					cmd_ra(game, 1);
				}
			}
			else
			{
				if ((minor - game->size_b) < major)
				{
					while(game->top_b->pos != game->minor)
						cmd_rrb(game, 1);
					cmd_pa(game);
					cmd_ra(game, 1);
				}
				else
				{
					while (game->top_b->pos != game->major)
						cmd_rb(game, 1);
					cmd_pa(game);
				}
			}
			if (game->top_a->pos == game->botton_a->pos + 1)
				cmd_ra(game, 1);
		}
		if(DEBUG != 0)
			print_stack(game);
	}
	while (game->top_a->pos == game->botton_a->pos + 1)
		cmd_ra(game, 1);
	printf("finish to_a_1\n");
}
*/
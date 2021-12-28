/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psG.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/28 16:30:26 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cut_point_to_b(t_game *game, t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	
	game->major = 0;
	while (temp->cut_point != 1)
	{
		if (temp->pos > game->major)
			game->major = temp->pos;
		temp = temp->next;
	}
	temp = stack;
	game->minor = game->major;
	while (temp->cut_point != 1)
	{
		if (temp->pos < game->minor)
			game->minor = temp->pos;
		temp = temp->next;
	}
	game->cut_point = game->minor + ((game->major - game->minor) / 2);
	
}

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
			if(temp->pos <= game->cut_point)
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

static void	run_a(t_game *game)
{
	if(DEBUG != 0)
		printf("run_a\n");
	while(check_pos(game, 'a') != 1)
	{
		if (game->top_a->pos <= game->cut_point)
		{
			if(DEBUG != 0)
				printf("(1)\n");
			cmd_pb(game);
		}
		else
		{
			if (game->stack_b != NULL)
			{
				if (game->top_b->pos > (game->cut_point / 2))
				{
					if(DEBUG != 0)
						printf("(2)\n");
					cmd_ra(game, 1);
				}
				else
				{
					if(DEBUG != 0)
						printf("(3)\n");
					cmd_rr(game);
				}
			}
			else
			{
				if(DEBUG != 0)
					printf("(4)\n");
				cmd_ra(game, 1);
			}
		}
		if(DEBUG != 0)
			print_stack(game);
	}
	game->top_a->cut_point = 1;
}

static void	run_b(t_game *game)
{
	if(DEBUG != 0)
		printf("run_b\n");
	if (game->top_a->pos > game->next_a->pos)
	{
		if(DEBUG != 0)
			printf("(5)\n");
		cmd_sa(game, 1);
	}	
	while(check_pos(game, 'b') != 1)
	{
		if (game->botton_b->pos == game->botton_a->pos + 1)
		{
			if(DEBUG != 0)
					printf("(5.1)\n");
			cmd_rrb(game, 1);
			cmd_pa(game);
			cmd_ra(game, 1);
		}
/*		if (game->top_b->next != NULL)
		{
			if (game->next_b->pos == game->top_b->pos + 1)
			{
				if(DEBUG != 0)
					printf("(6)\n");
				cmd_sb(game, 1);
			}	
		}
*/		if (game->top_b->pos == 1)
		{
			game->top_b->cut_point = 1;
			if (check_stack_a(game) != 0)
			{
				if(DEBUG != 0)
					printf("(7)\n");
				cmd_pa(game);
			}	
			else
			{
				if(DEBUG != 0)
					printf("(8)\n");
				cmd_pa(game);
				cmd_ra(game, 1);
			}
		}
		else if (game->top_b->pos >= game->cut_point)
		{
			if(DEBUG != 0)
				printf("(9)\n");
			cmd_pa(game);
		}
		else
		{
			if (game->top_b->pos == game->botton_a->pos + 1)	
			{
				if(DEBUG != 0)
					printf("(10)\n");
				cmd_pa(game);
				cmd_ra(game, 1);
			}
			else
			{
				if(DEBUG != 0)
					printf("(11)\n");
				cmd_rb(game, 1);
			}
		}
		if(DEBUG != 0)
			print_stack(game);
	}
	if (game->top_b->pos == 1)
	{
		if(DEBUG != 0)
			printf("(12)\n");
		cmd_pa(game);
		if (check_stack_a(game) == 0)
			cmd_ra(game, 1);
		if(DEBUG != 0)
			print_stack(game);
	}
	else if (game->top_b->pos == game->botton_a->pos + 1)
	{
		if(DEBUG != 0)
			printf("(12.1)\n");
		cmd_pa(game);
		cmd_ra(game, 1);
	}
	game->top_a->cut_point = 1;
}

static void	to_a(t_game *game)
{
	t_stack	*temp;
	int		minor;
	int		major;
	
	if(DEBUG != 0)
		printf("to_a\n");
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
					if(DEBUG != 0)
						printf("(13)\n");
					if (game->top_b->pos == minor + 1)
						cmd_pa(game);
					cmd_rb(game, 1);
				}
				if(DEBUG != 0)
					print_stack(game);
				if(DEBUG != 0)
					printf("(14)\n");
				cmd_pa(game);
				cmd_ra(game, 1);
//				if (game->top_a->pos == minor + 1)
//					cmd_ra(game, 1);
			}
			else
			{
				if(DEBUG != 0)
					printf("(15)\n");
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
				if(DEBUG != 0)
					printf("(16)\n");
				while(game->top_b->pos != game->major)
					cmd_rb(game, 1);
				cmd_pa(game);
				if(DEBUG != 0)
					print_stack(game);
			}
			else
			{
				while(game->top_b->pos != game->minor)
				{
					if(DEBUG != 0)
						printf("(17)\n");
					if (game->top_b->pos == minor + 1)
						cmd_pa(game);
					cmd_rrb(game, 1);
				}
				if(DEBUG != 0)
					printf("(18)\n");
				cmd_pa(game);
				cmd_ra(game, 1);
				if (game->top_a->pos == minor + 1)
					cmd_ra(game, 1);
				if(DEBUG != 0)
					print_stack(game);
			}
		}
		if (DEBUG != 0)
			print_stack(game);
	}
	cmd_pa(game);
	while (game->top_a->pos == game->botton_a->pos + 1)
	{
		if(DEBUG != 0)
			printf("(21)\n");
		cmd_ra(game, 1);
	}
	if(DEBUG != 0)
			print_stack(game);
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
	cut_point_to_b(game, game->stack_b);
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

int	solution_psG(t_game *game)
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

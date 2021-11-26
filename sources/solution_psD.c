/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psD.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/26 18:44:59 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	print_stack(t_game *game)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	
	temp_a = game->stack_a;
	temp_b = game->stack_b;
	
	printf("STACK A -  ");
	while (temp_a != NULL)
	{
		printf("%d  ", *temp_a->content);
		temp_a = temp_a->next;
	}
	printf("\n");
	
	printf("STACK B -  ");
	while (temp_b != NULL)
	{
		printf("%d  ", *temp_b->content);
		temp_b = temp_b->next;
	}
	printf("\n");
}
*/
static void	check_sa(t_game *game)
{
	if (game->stack_b != NULL)
	{
		if (game->next_b != NULL)
		{
			if (game->next_b->pos > game->top_b->pos)
				cmd_ss(game);
			else
				cmd_sa(game, 1);
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

static	int	check_median(t_game *game, int i)
{
	if ((game->median / i) < game->size_a)
		return (0);
	return (1);
}

int	solution_psD(t_game *game)
{
//	int count;
	int	i;

	i = 1;
//	count = 0;
while (check_stack_a(game) != 1)
{
	while (check_median(game, i) != 1 && check_stack_a(game) != 1)
	{
		if (*game->botton_a->pos <= (game->size - (game->median / i)))
			check_rra(game);
		else if (*game->next_a->pos <= (game->size - (game->median / i)))
		{
			if (*game->top_a->pos <= (game->size - (game->median / i)))
			{
				if (game->top_a->pos < game->next_a->pos)
					cmd_pb(game);
				else
					check_sa(game);
			}
			else
			{
				check_ra(game);
			}
		}
		else if (*game->next_a->pos > (game->size - (game->median / i)))
		{	
			if (*game->top_a->pos <= (game->size - (game->median / i)))
				cmd_pb(game);
			else
				check_ra(game);
		}
//		printf("median %d\n", (game->size - (game->median / i)));
//		printf("top pos %d\n", *game->top_a->pos);
//		printf("size a %d\n", game->size_a);		
//		print_stack(game);
//		count++;
	}
	i++;
}
//	printf("count %d", count);
	return (1);
}
/*
static void	check_sa(t_game *game)
{
	if (game->stack_b != NULL)
	{
		if (game->next_b != NULL)
		{
			if (game->next_b->pos > game->top_b->pos)
				cmd_ss(game);
			else
				cmd_sa(game, 1);
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

static void	check_a(t_game *game)
{
	if (*game->botton_a->pos < game->median)								//botton to B
	{
		printf("botton A to B\n");
		if (game->next_a->pos < game->botton_a->pos && game->next_a->pos < game->top_a->pos)					//netx A < botton A
		{
			printf("next A < botton A\n");
			check_sa(game);
//			cmd_pa(game);
		}
		else 															//netx A to B &&  > botton
		{
			printf("next A > botton A\n");
			if (game->top_a->pos < game->botton_a->pos)				//top A < botton A
			{	
				printf("top A pos < botton A pos\n");
				cmd_pb(game);
			}
			else
			{
				printf("top pos A > botton pos A\n");
				check_rra(game);
			}
		}
	}
	else	// botton to A
	{
		printf("botton A to A\n");
		if (game->top_a->pos > game->next_a->pos)
		{
			printf("top A > next A\n");
			if (*game->top_a->pos < game->median)
			{
				printf("top pos A < game size\n");
				check_sa(game);
			}
			else
			{
				printf("top pos A > game size / 2\n");
				check_ra(game);
			}
		}
		else
		{
			printf("top A < next A\n");
			cmd_pb(game);
		}
	}
}

static	int	check_stack_b(t_game *game)
{
	t_stack *temp;
	t_stack *temp_next;
	if (game->stack_b == NULL)
		return (1);
	temp = game->stack_b;
	temp_next = game->stack_b->next;
	while (temp->next != NULL)
	{
		if (*temp->pos != (*temp_next->pos + 1))
			return (0);//not ok
		temp = temp_next;
		temp_next = temp_next->next;
	}
	return (1); //ok
}

static void	check_sb(t_game *game)
{
	if (game->stack_a != NULL)
	{
		if (game->next_a != NULL)
		{
			if (game->next_a->pos < game->top_a->pos)
				cmd_ss(game);
			else
				cmd_sb(game, 1);
		}
		else
			cmd_sb(game, 1);
	}
	else if (game->stack_b == NULL)
		cmd_sb(game, 1);
}

static void	check_rb(t_game *game)
{
	if (game->stack_a != NULL)
	{
		if (game->next_a != NULL)
		{
			if (game->botton_a->pos < game->top_a->pos 
				|| (*game->top_a->pos > game->size_a / 2))
				cmd_rr(game);
			else
				cmd_rb(game, 1);
		}
		else
			cmd_rb(game, 1);
	}
	else if (game->stack_a == NULL)
		cmd_rb(game, 1);
}

static void	check_rrb(t_game *game)
{
	if (game->stack_a != NULL)
	{
		if (game->next_a != NULL)
		{
			if (game->botton_a->pos < game->top_a->pos 
				|| (*game->botton_a->pos < game->size_a / 2))
				cmd_rrr(game);
			else
				cmd_rrb(game, 1);
		}
		else
			cmd_rrb(game, 1);
	}
	else if (game->stack_a == NULL)
		cmd_rrb(game, 1);
}

static void	check_b(t_game *game)
{
	if (*game->botton_b->pos < game->median)								//botton to B
	{
		printf("botton B to A\n");
		if (game->next_b->pos > game->botton_b->pos && game->next_b->pos > game->top_b->pos)					//netx A < botton A
		{
			printf("next B > botton B\n");
			check_sb(game);
		//	cmd_pb(game);
		}
		else 															//netx A to B &&  > botton
		{
			printf("next B < botton B\n");
			if (game->top_b->pos > game->botton_b->pos)				//top A < botton A
			{	
				printf("top B pos < botton B pos\n");
				cmd_pa(game);
			}
			else
			{
				printf("top pos B < botton pos B\n");
				check_rrb(game);
			}
		}
	}
	else	// botton to B
	{
		printf("botton B to B\n");
		if (game->top_b->pos < game->next_b->pos)
		{
			printf("top B < next B\n");
			if (*game->top_b->pos > game->median)
			{
				printf("top pos B > game size\n");
				check_sb(game);
			}
			else
			{
				printf("top pos B < game size / 2\n");
				check_rb(game);
			}
		}
		else
		{
			printf("top B > next B\n");
			cmd_pb(game);
		}
	}
}
int	solution_psD(t_game *game)
{
	int	i;
	int	teste;
	int	count;
	
	count = 0;
	teste = 0;
	
	i = 1;
	while (teste < 1)
	{
		while (check_stack_a(game) != 1)
		{
			check_a(game);
			print_stack(game);
			count++;
		}
		while (check_stack_b(game) != 1)
		{
			check_b(game);
			print_stack(game);
			count++;
		}
		if (check_stack_a(game) == 1 && check_stack_b(game) == 1)
		{
			while (game->stack_b != NULL)
			{
				cmd_pa(game);
				print_stack(game);
				count++;
			}
		}
	teste++;
	}

	print_stack(game);
	printf("\ncount: %d\n", count);
	return (0);
}
*/
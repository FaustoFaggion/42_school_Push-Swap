/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/23 10:56:50 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*temp;
	t_stack	*next;
	
	if (game->stack_1 == NULL)
		return (1);
	if (game->stack_2 == NULL)
		return (1);
	temp = game->stack_1;
	next = game->stack_2;
	while(*next->content > *temp->content)
	{
		if (next->next == NULL)
				return (1);
		temp = next;
		next = temp->next;
	}
	return (0);
}

static	int	check(t_game *game)
{
	t_stack *temp;
	t_stack *temp_next;
	
	temp = game->stack_a;
	temp_next = game->stack_a->next;
	while (temp->next != NULL)
	{
		if (*temp->content > *temp_next->content)
			return (0);
		temp = temp_next;
		temp_next = temp_next->next;
	}
	return (1);
}
static void check_dup(t_game * game)
{
	
	
}
int	solution_psB(t_game *game)
{
	int		flag;
	t_stack	*temp_next;
	int		i;
	int	a;
	int	b;

	flag = 0;
	while (flag == 0)
	{
		while (check_stack(game->stack_a, game->stack_a->next) != 1)
		{
			a = *game->botton_a->pos - *game->size_b;
			if (a < 0)
				a= a * -1;
			b = *game->botton_a->pos - *game->size_a;
			if (b < 0)
				b = b * -1;
			temp_next = game->stack_a->next;
			if (*game->top_a->content > *temp_next->content)					// 1- topA > nextA
			{
				if (*game->stack_a->content > *game->botton_a->content)			// 2 -topA > bottonA
				{
					if (a < b)													// 4 -pos -> B
					{	
						if (*game->stack_b->content < *game->botton_b->content)	// 3 -topB < bottonB
						cmd_ss(game);
						else													// 3 -topB > bottonB
							cmd_sa(game);
						cmd_pb(game);	
					}
					else														// 4 -pos <- A
					{
						if (*game->stack_b->content < *game->botton_b->content)	// 3 -topB < bottonB		
							cmd_rra(game);
						else													// 3 -topB > bottonB
							cmd_rrr(game);
					}
				}
				else															// 2 -topA < bottonA
				{
					if (a < b)													// 4 -posA -B < posA - A
					{
						if (*game->stack_b->content < *game->botton_b->content)		// 3 -topB < bottonB
							cmd_ss(game);
						else														// 3 -topB > bottonB
							cmd_sa(game);
						cmd_pb(game);
				}
			}
			else																//1 - top < next
				cmd_pb(game);
		}
		cmd_pb(game);
		steps++;
		while (check_stack(game->stack_b->next, game->stack_b) != 1)
		{
			temp_next = game->stack_b->next;
			if (*game->stack_b->content < *temp_next->content)					// 1 -topB < nextB
			{
				if (*game->stack_b->content < *game->botton_b->content)			// 2 - topB < bottonB
				{
					
					if (*game->stack_a->content > *game->botton_a->content)		// 3 -topA < bottonA		
						cmd_rrb(game);
					else														// 3 -topA > bottonA
						cmd_rrr(game);
				}
				else															// 2 - topB > bottonB
				{
					if (*game->stack_a->content > *game->botton_a->content)		// 3 -topA < bottonA
						cmd_sb(game);
					else														// 3 -topA < bottonA
						cmd_ss(game);
					cmd_pa(game);
				}
			}
			else																// 1 -top > next
				cmd_pa(game);
		}
		cmd_pa(game);
		flag = check(game);
	//	flag++;
	}
	printf("\n\nsteps : %d - ", steps);
	printf("size: %d - ", *game->size);
	printf("size A: %d - ", *game->size_a);
	printf("size B: %d\n\n", *game->size_b);
	i = 0;
	while (i < *game->size)
	{
		printf("%d - ", game->sequence[i]);
		i++;
	}
	return (0);
}
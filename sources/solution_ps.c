/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/20 14:08:57 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("%d", *temp->content);
		if (temp->next != NULL)
			printf("%d", *temp_next->content);
	}
	return (1);
}

int	solution_ps(t_game *game)
{
	int	flag;
	t_stack	*temp_next;
	int steps;
	
	steps = 0;
	flag = 0;
	while (flag == 0)
	{
		while (game->stack_a->next != NULL)
		{
			temp_next = game->stack_a->next;
			if (*game->stack_a->content > *temp_next->content)
			{
				if (*game->stack_a->content > *game->botton_a->content)
				{
					printf("1");
					cmd_ra(game);
					steps++;
				}
				else
				{
					printf("2");
					cmd_sa(game);
					steps++;
					cmd_pb(game);
					steps++;
					flag ++;
				}
			}
			else
			{
				printf("3");
				cmd_pb(game);
				steps++;
				flag ++;
			}
		}
		printf("4");
		cmd_pb(game);
		steps++;
		while (game->stack_b->next != NULL)
		{
			temp_next = game->stack_b->next;
			if (*game->stack_b->content < *temp_next->content)
			{
				if (*game->stack_b->content < *game->botton_b->content)
				{
					printf("5");
					cmd_rb(game);
					steps++;
				}
				else
				{
					printf("6");
					cmd_sb(game);
					steps++;
					cmd_pa(game);
					steps++;
					flag ++;
				}
			}
			else
			{
				printf("7");
				cmd_pa(game);
				steps++;
				flag ++;
			}
		}
		printf("8");
		cmd_pa(game);
		steps++;
		flag = check(game);
	}
	printf("\n\nsteps : %d", steps);
	return (0);
}
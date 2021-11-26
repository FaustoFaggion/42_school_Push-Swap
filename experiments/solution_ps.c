/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/22 12:26:05 by fagiusep         ###   ########.fr       */
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
/*
static int	stop_stack_a(t_game *game)
{
	t_stack *temp;
	
	while (game->stack_a->next != NULL)
	{
		temp = game->stack_a->next;
		if (game->stack_a->content > temp->content)
			return (1);
	}
	return (0);
}
*/
int	solution_ps(t_game *game)
{
	int		flag;
	t_stack	*temp_next;
	int		steps;
	int		i;
	
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
				//	if(stop_stack_a(game) == 0)
				//		break ;
					cmd_ra(game);
					steps++;
				}
				else
				{
					printf("2");
				//	if(stop_stack_a(game) == 0)
				//		break ;
					cmd_sa(game);
					steps++;
					cmd_pb(game);
				//	if(stop_stack_a(game) == 0)
				//		break ;
					steps++;
					flag ++;
				}
			}
			else
			{
				printf("3");
			//	if(stop_stack_a(game) == 0)
			//			break ;
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
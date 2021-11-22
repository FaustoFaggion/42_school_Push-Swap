/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_ps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/22 12:23:40 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_game(t_game *game)
{
	t_stack	*temp;
	t_stack	*next;
	
	temp = game->stack_a;
	next = game->stack_a->next;
	while(*next->content > *temp->content)
	{
		if (next != NULL)
				return (1);
		temp = next;
		next = temp->next;
	}
	return (0);
}


/*
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
*/
int	solution_ps(t_game *game)
{
	int	steps;
	int	flag;
	int	i;
	
	steps = 0;
	flag = 0;
	while (flag == 0)
	{
		if (check_game(game) != 1)
		{
			if(game->top_a > game->stack_a-> next)
			{
				if (game->stack_b != NULL)
				{
					
				}
				else
					cmd_sa(game);
			}
			printf("\n\nflag : %d - ", flag);
		}
		
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
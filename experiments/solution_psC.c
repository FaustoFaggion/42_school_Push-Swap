/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_psC.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:31:53 by fagiusep          #+#    #+#             */
/*   Updated: 2021/11/24 14:42:59 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*temp;
	t_stack	*next;
	
	if (stack_1 == NULL)
		return (1);
	if (stack_2 == NULL)
		return (1);
	temp = stack_1;
	next = stack_2;
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

static void check_pos_a(t_game *game)
{
	int	a;
	int	b;
	
	a = *game->botton_a->pos - *game->size_a;
	if (a < 0)
		a= a * -1;
	b = *game->botton_a->pos - *game->size_b;
	if (b < 0)
		b = b * -1;
	if (a <= b)
		game->botton_a->push = 'A';
	else
		game->botton_a->push = 'B';
	
	a = *game->top_a->pos - *game->size_a;
	if (a < 0)
		a= a * -1;
	b = *game->top_a->pos - *game->size_b;
	if (b < 0)
		b = b * -1;
	if (a <= b)
		game->top_a->push = 'A';
	else
		game->top_a->push = 'B';
}

static void	next_pos(t_game *game)
{
	int		a;
	int		b;
	t_stack	*temp;
	
	temp = game->stack_a->next;
	a = *temp->pos - *game->size_a;
	if (a < 0)
		a= a * -1;
	b = *temp->pos - *game->size_b;
	if (b < 0)
		b = b * -1;
	if (a <= b)
		game->top_a->next_push = 'A';
	else
		game->top_a-> next_push = 'B';
}

int	solution_psC(t_game *game)
{
	int		flag;
//	t_stack	*temp;
	
	flag = 0;
	while (flag == 0)
	{
		if (game->stack_a != NULL)
		{
			if (check_stack(game->stack_a, game->stack_a->next) != 1)
			{
				check_pos_a(game);
				if (game->botton_a->push == 'A')
				{
					printf("botton A stay A\n");
					if (game->top_a->push == 'B')
					{
						printf("top A push B\n");
						next_pos(game);
						if (game->top_a->next_push == 'A')
						{
							printf("top A  next stay A\n");
						}
						else if (game->top_a->next_push == 'B')
						{
							printf("top A next push B\n");
						}
					}
					else if (game->top_a->push == 'A')
					{
						printf("botton A push B\n");
					}
				}
				else if (game->botton_a->push == 'B')
				{
				
				}
	
			}
			else
			{

			}
		}
		if (game->stack_b != NULL)
		{
			if (check_stack(game->stack_b->next, game->stack_b) != 1)
			{
			
			}
		}
		flag = check(game);
		flag++;
	}
	printf("\nsize: %d - ", *game->size);
	printf("size A: %d - ", *game->size_a);
	printf("size B: %d\n\n", *game->size_b);

	while (game->stack_a->next != NULL)
	{
		printf("%d - ", *game->stack_a->content);
		game->stack_a = game->stack_a->next;
	}
	if (game->stack_b != NULL)
	{
		while (game->stack_b->next != NULL)
		{
			printf("%d - ", *game->stack_b->content);
			game->stack_b = game->stack_b->next;
		}
	}
	return (0);
}
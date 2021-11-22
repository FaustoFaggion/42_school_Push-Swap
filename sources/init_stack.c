/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:17:28 by fausto            #+#    #+#             */
/*   Updated: 2021/11/22 11:42:36 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ps_lstlast(*stack);
	last->next = new;
	new->previous = last;
}

static t_stack	*ps_lstnew(int *content)
{
	t_stack	*n_elem;

	n_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!n_elem)
		return (NULL);
	n_elem->content = content;
	n_elem->previous = NULL;
	n_elem->next = NULL;
	n_elem->pos = NULL;
	return (n_elem);
}

static void	check_pos(t_game *game, t_stack *temp)
{
	int	i;
	int	x;
	
	i = 0;
	x = 0;
	while (i < *game->size)
	{
		if (game->args[i] <= *temp->content)
			x++;
		i++;
	}
	temp->pos = &game->sequence[x- 1];
}

int	init_stack(t_game *game, int argc)
{
	t_stack	*temp;

	int	i;

	i = 0;
	while (i < argc - 1)
	{
		temp = ps_lstnew(&game->args[i]);
		if (temp == NULL)
			return (1);
		check_pos(game, temp);
//		printf("content:%d i:%d pos:%d\n", *temp->content, i, *temp->pos);
		ps_lstadd_back(&game->stack_a, temp);
		i++;
	}
	game->top_a = game->stack_a;
	game->botton_a = ps_lstlast(game->stack_a);

//	printf("top stack A %d\n", *game->top_a->content);
//	printf("botton stack A %d\n", *game->botton_a->content);
//	ps_print_lst(game->stack_a);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:17:28 by fausto            #+#    #+#             */
/*   Updated: 2021/11/18 14:45:57 by fausto           ###   ########.fr       */
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

void	ps_lstadd_back(t_stack **stack, t_stack *new)
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
	return (n_elem);
}

static t_stack	*ps_print_lst(t_stack *stack)
{
	printf("\nprint_lst\n");
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		printf("stack %p -> ", stack);
		printf("stack->content %d\n ", *stack->content);
		printf("      stack->previous %p -> ", stack->previous);
		printf("      stack->next %p\n ", stack->next);
		stack = stack->next;
	}
	return (stack);
}

int	init_stack(t_game *game, int argc)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		temp = ps_lstnew(&game->args[i]);
		ps_lstadd_back(&game->stack_a, temp);
		i++;
	}
	ps_print_lst(game->stack_a);
	cmd_sa(game);
	printf("After cmd\n");
	ps_print_lst(game->stack_a);
	return (0);
}

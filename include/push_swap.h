/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:25:09 by fausto            #+#    #+#             */
/*   Updated: 2021/11/18 19:00:25 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
typedef struct s_stack
{
	int		*content;
	void	*previous;
	void	*next;
}			t_stack;

typedef struct s_game
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*args;
	int		top;
	int		botton;
	
}		t_game;

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

int	init_ps(int argc, char *argv[], t_game *game);

int	init_stack(t_game *game, int argc);

int	exit_ps(t_game *game);

int	cmd_sa(t_game *game);

int	cmd_ra(t_game *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:25:09 by fausto            #+#    #+#             */
/*   Updated: 2021/11/26 17:59:02 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
typedef struct s_stack
{
	int		*pos;
	int		*content;
	void	*previous;
	void	*next;
}			t_stack;

typedef struct s_game
{
	int		*args;
	int		*sequence;
	int		size;
	int		median;
	t_stack	*stack_a;
	t_stack	*top_a;
	t_stack	*next_a;
	t_stack	*botton_a;
	int		size_a;
	t_stack	*stack_b;
	t_stack	*top_b;
	t_stack	*next_b;
	t_stack	*botton_b;
	int		size_b;
}		t_game;

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

int		init_ps(int argc, char *argv[], t_game *game);

int		init_stack(t_game *game, int argc);

t_stack	*ps_lstlast(t_stack *stack);

int		exit_ps(t_game *game);

int		cmd_sa(t_game *game, int i);

int		cmd_ra(t_game *game, int i);

int		cmd_rra(t_game *game, int i);

int		cmd_pb(t_game *game);

int		cmd_sb(t_game *game, int i);

int		cmd_rb(t_game *game, int i);

int		cmd_rrb(t_game *game, int i);

int		cmd_pa(t_game *game);

int		cmd_ss(t_game *game);

int		cmd_rr(t_game *game);

int		cmd_rrr(t_game *game);

int		solution_psD(t_game *t_game);

//void	check_top_next(t_game *game);

//void	check_top_pos(t_game *game);

#endif

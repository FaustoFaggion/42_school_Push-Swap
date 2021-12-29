/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:29:00 by fagiusep          #+#    #+#             */
/*   Updated: 2021/12/29 11:19:03 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ss : sa and sb at the same time.*/
int	cmd_ss(t_game *game)
{
	cmd_sa(game, 2);
	cmd_sb(game, 2);
	write(1, "ss\n", 3);
	return (0);
}

/*rr : ra and rb at the same time.*/
int	cmd_rr(t_game *game)
{
	cmd_ra(game, 2);
	cmd_rb(game, 2);
	write(1, "rr\n", 3);
	return (0);
}

/*rrr : rra and rrb at the same time.*/
int	cmd_rrr(t_game *game)
{
	cmd_rra(game, 2);
	cmd_rrb(game, 2);
	write(1, "rrr\n", 4);
	return (0);
}

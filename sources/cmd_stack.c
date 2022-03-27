/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 09:14:22 by fagiusep          #+#    #+#             */
/*   Updated: 2022/03/27 09:14:23 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd(t_game *game, char cmd[3])
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		cmd_sa(game, 1);
	if (ft_strncmp(cmd, "ra", 2) == 0)
		cmd_ra(game, 1);
	if (ft_strncmp(cmd, "rra", 3) == 0)
		cmd_rra(game, 1);
	if (ft_strncmp(cmd, "pb", 2) == 0)
		cmd_pb(game);
	if (ft_strncmp(cmd, "sb", 2) == 0)
		cmd_sb(game, 1);
	if (ft_strncmp(cmd, "rb", 2) == 0)
		cmd_rb(game, 1);
	if (ft_strncmp(cmd, "rrb", 3) == 0)
		cmd_rrb(game, 1);
	if (ft_strncmp(cmd, "pa", 2) == 0)
		cmd_pa(game);
}

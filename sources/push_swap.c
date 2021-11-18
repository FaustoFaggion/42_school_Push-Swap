/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:22:39 by fausto            #+#    #+#             */
/*   Updated: 2021/11/18 19:34:07 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (init_ps(argc, argv, &game) == 1 || init_stack(&game, argc) == 1)
	{
		exit_ps(&game);
		return (0);
	}
	cmd_sa(&game);
	cmd_ra(&game);
}

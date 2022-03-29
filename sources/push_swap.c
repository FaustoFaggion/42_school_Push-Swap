/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:22:39 by fausto            #+#    #+#             */
/*   Updated: 2022/03/29 10:17:44 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc > 1)
	{
		if (init_ps(argc, argv, &game) == 1 || init_stack(&game, argc) == 1)
		{
			exit_ps(&game);
			return (0);
		}
		solution_ps(&game);
		exit_ps(&game);
	}
	return (0);
}

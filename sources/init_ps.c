/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:24:41 by fausto            #+#    #+#             */
/*   Updated: 2021/11/18 15:46:26 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arguments(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write(2, "Write a non digit argument \n", 28);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	init_variables(int argc, t_game *game)
{
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->args = NULL;
	game->args = malloc(sizeof(int) * (argc - 1));
	if (!game->args)
	{
		write(2, "malloc error game->stack_a\n", 27);
		return (1);
	}
	return (0);
}

static int	parse_args(int argc, char *argv[], t_game *game)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		game->args[i - 1] = ft_atoi(argv[i]);
		//Verificar corretamente se número é > INT_MAX e < INT_MIN
		if (game->args[i - 1] > INT_MAX || game->args[i - 1] < INT_MIN)
		{
			write(2, "Number > INT_MAX or < INT_MIN\n", 30);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_dup(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->args[i])
	{
		j = i + 1;
		while (game->args[j])
		{
			if (game->args[i] == game->args[j])
			{	
				write(2, "Number duplicated\n", 18);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	init_ps(int argc, char *argv[], t_game *game)
{
	if (check_arguments(argc, argv) == 1)
		return (1);
	if (init_variables(argc, game) == 1)
		return (1);
	if (parse_args(argc, argv, game) == 1)
		return (1);
	if (check_dup(game) == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:24:41 by fausto            #+#    #+#             */
/*   Updated: 2021/11/30 12:30:41 by fagiusep         ###   ########.fr       */
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
	game->args = malloc(sizeof(int) * (argc - 1));
	if (game->args == NULL)
		return (1);
	game->sequence = malloc(sizeof(int) * (argc - 1));
	if (game->sequence == NULL)
		return (1);
	game->stack_a = NULL;
	game->top_a = NULL;
	game->next_a = NULL;
	game->botton_a = NULL;
	game->stack_b = NULL;
	game->top_b = NULL;
	game->next_b = NULL;
	game->botton_b = NULL;
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
		game->sequence[i - 1] = i;
		i++;
	}
	game->size = i - 1;
	game->size_a = game->size;
	game->size_b = 0;
	game->median = (game->size + 1) / 2;
	return (0);
}

static int	check_dup(t_game *game, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (game->args[i] == game->args[j])
			{	
				write(2, "Number duplicated - ",20);
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
	if (check_dup(game, argc) == 1)
		return (1);
	return (0);
}

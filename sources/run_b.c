#include "push_swap.h"

static void pos_1(t_game *game)
{
			if (check_stack_a(game) != 0)
				cmd_pa(game);
			else
			{
				cmd_pa(game);
				cmd_ra(game, 1);
			}
}

void	run_b(t_game *game)
{
	while(check_pos(game, 'b') != 1)
	{
		if (game->botton_b->pos == game->botton_a->pos + 1 
			|| game->botton_b->pos == 1)
			cmd_rrb(game, 1);
		if (game->top_b->pos == 1)
			pos_1(game);
		else if (game->top_b->pos >= game->cut_point)
			cmd_pa(game);
		else
		{
			if (game->top_b->pos == game->botton_a->pos + 1)	
			{
				cmd_pa(game);
				cmd_ra(game, 1);
			}
			else
				cmd_rb(game, 1);
		}
	}
	game->top_a->cut_point = 1;
}
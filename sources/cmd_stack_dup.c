#include "push_swap.h"

/*ss : sa and sb at the same time.*/
int	cmd_ss(t_game *game)
{
	cmd_sa(game);
	cmd_sb(game);
	return (0);
}

/*rr : ra and rb at the same time.*/
int	cmd_rr(t_game *game)
{
	cmd_ra(game);
	cmd_rb(game);
	return (0);
}

/*rrr : rra and rrb at the same time.*/
int	cmd_rrr(t_game *game)
{
	cmd_rra(game);
	cmd_rrb(game);
	return (0);
}

#include "push_swap.h"

void	print_stack(t_game *game)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	printf("size %d\n", game->size);
	printf("size_a %d\n", game->size_a);
	printf("size_b %d\n", game->size_b);
	printf("size - size / i %d\n", (game->size) - (game->size / game->index));
	printf("size / index %d\n", game->size / game->index);
	printf("game_index %d\n", game->index);
	printf("top_a pos %d\n", *game->top_a->pos);
	printf("next_a pos %d\n", *game->next_a->pos);
	printf("botton_a pos %d\n", *game->botton_a->pos);
	printf("top_b pos %d\n", *game->top_b->pos);
	printf("next_b pos %d\n", *game->next_b->pos);
	printf("botton_b pos %d\n", *game->botton_b->pos);

	temp_a = game->stack_a;
	temp_b = game->stack_b;
	
	printf("STACK A -  ");
	while (temp_a != NULL)
	{
		printf("%d  ", *temp_a->content);
		temp_a = temp_a->next;
	}
	printf("\n");
	
	printf("STACK B -  ");
	while (temp_b != NULL)
	{
		printf("%d  ", *temp_b->content);
		temp_b = temp_b->next;
	}
	printf("\n");
}
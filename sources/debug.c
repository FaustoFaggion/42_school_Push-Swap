#include "push_swap.h"

void	print_stack(t_game *game)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

/*	printf("game->major %d * ", game->major);
	printf("game->minor %d\n", game->minor);
	printf("size %d\n", game->size);
	printf("size_a %d\n", game->size_a);
	printf("size_b %d\n", game->size_b);
*/		
//		printf("size_a - size_a /cut_point %d\n", (game->size_a) - (game->size_a / game->cut_point));
//		printf("size_b - size_b /cut_point %d\n", (game->size_b) - (game->size_b / game->cut_point));
//		printf("game_cut_point %d\n", game->cut_point);
	if (game->stack_a != NULL)
	{
//		printf("top_a pos %d\n", game->top_a->pos);
//		printf("botton_a pos %d\n", game->botton_a->pos);
//		printf("cut_point_a %d\n", game->top_a->cut_point);
//		if (game->stack_a->next != NULL)
//			printf("next_a pos %d\n", game->next_a->pos);
	}
	if (game->stack_b != NULL && game->stack_b->next != NULL)
	{
//		printf("top_b pos %d\n", game->top_b->pos);
//		printf("next_b pos %d\n", game->next_b->pos);
//		printf("botton_b pos %d\n", game->botton_b->pos);
	}
	temp_a = game->stack_a;
	temp_b = game->stack_b;
	
	printf("STACK A -  ");
	while (temp_a != NULL)
	{
		if (temp_a->cut_point == 0)
			printf("%d  ", temp_a->content);
		if (temp_a->cut_point == 1)
			printf("(%d) ", temp_a->content);
		if (temp_a->cut_point == 2)
			printf("[%d] ", temp_a->content);
		temp_a = temp_a->next;
	}
	printf("\n");
	
	printf("STACK B -  ");
	while (temp_b != NULL)
	{
		if (temp_b->cut_point == 0)
			printf("%d  ", temp_b->content);
		if (temp_b->cut_point == 1)
			printf("(%d) ", temp_b->content);
		if (temp_b->cut_point == 2)
			printf("[%d] ", temp_b->content);
		temp_b = temp_b->next;
	}
	printf("\n");
/*	temp_a = game->stack_a;
	while (temp_a != NULL)
	{
		printf("content %d * pos %d * ", temp_a->content, temp_a->pos);
		temp_a = temp_a->next;
	}

	printf("\n");
	temp_b = game->stack_b;
	while (temp_b != NULL)
	{
		printf("content %d * pos %d * ", temp_b->content, temp_b->pos);
		temp_b = temp_b->next;
	}

	printf("\n");
*/}
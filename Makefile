NAME			=	push_swap
NAME_BONUS		=	push_swap_bonus

PATH_LIBFT		=	./libft
LIBFT			=	$(PATH_LIBFT)/libft.a

I_LIBFT			=	-I ./libft
I_PUSH_SWAP			=	-I ./include

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra -g

SRC_DIR			=	sources
SRC_FILES		=	push_swap.c \
					init_ps.c \
					init_stack.c \
					exit_ps.c \
					cmd_stack_a.c \
					cmd_stack_b.c \
					solution_ps.c

SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

#SRC_DIR_BONUS	=	sources_bonus
#SRC_FILES_BONUS	=	

#SRC_BONUS		=	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))

OBJ_DIR			=	objects
OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#OBJ_DIR_BONUS	=	objects_bonus
#OBJ_BONUS		=	$(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

FS				=	-fsanitize=address -g3

all:	$(NAME)

#bonus:	$(NAME_BONUS)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(I_PUSH_SWAP) $(I_LIBFT)

#$(NAME_BONUS):	$(LIBFT) $(OBJ_DIR_BONUS) $(OBJ_BONUS)
#	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS) $(I_PUSH_SWAP) $(I_LIBFT)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(I_PUSH_SWAP) $(I_LIBFT)

#$(OBJ_DIR_BONUS)/%.o:	$(SRC_DIR_BONUS)/%.c
#	$(CC) $(CFLAGS) -c $< -o $@ $(I_PUSH_SWAP) $(I_LIBFT)

$(LIBFT):
	make -C $(PATH_LIBFT)

$(OBJ_DIR):
	mkdir objects

#$(OBJ_DIR_BONUS):
#	mkdir objects_bonus

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
#	rm -rf $(OBJ_BONUS)
#	rm -rf $(OBJ_DIR_BONUS)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
#	rm -rf $(NAME_BONUS)
	make -C $(PATH_LIBFT) fclean

re: fclean all

run:
	make && ./push_swap 9 8 7 6 5 4 3 2 1 0
run1:
	make && ./push_swap 0 1 2 3 4 5 6 7 8 9 
run2:
	make && ./push_swap 3 8 7 4 2 9 0 6 1 5
run3:
	make && ./push_swap 3 18 7 4 12 9 10 6 16 1 0 13 5 11 17 2 14 19 8 15
#run_bonus:
#	make && ./pipex file1.txt "tr a b" "tr e c" file2.txt

#sanitize:	$(LIBFT) $(OBJ_DIR) $(OBJ)
#	$(CC) $(CFLAGS) $(FS) $(OBJ) $(LIBFT) -o $(NAME) $(I_PIPEX) $(I_LIBFT)
#	./pipex file1.txt "tr a b" "tr e c" file2.txt

#valgrind:
#	make && valgrind ./pipex file1.txt "tr a b" "tr e c" file2.txt

#valgrind_bonus: $(NAME_BONUS)
#	valgrind --leak-check=full --show-leak-kinds=all ./pipex file1.txt "tr a b" "tr e c" file2.txt




	

define IMG
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░▄ ▀▄▄▀▄░░░░░░░░░░░░░░░░░░░░░▄ ▀▄▄▀▄░░░░░░░░░░░░░░░░░░░░░▄ ▀▄▄▀▄░░░░░░░░░░░░░░
░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░░░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░░░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░
░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░░░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░░░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░
░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░░░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░░░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░
░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░░░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░░░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░
░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░
░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░
░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░░░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░░░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░
░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░░░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░░░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░

endef
export IMG

NAME := push_swap
LIBFT_DIR = libft/
LIBFT_EXEC = ./libft/libft.a
SRCFILES := push_swap.c \
			mechanism.c \
			mechanism_II.c \
			sort_small.c \
			sort_four.c \
			sort_five.c \
			sort_five_utils.c \
			indexes.c \
			radix.c \
			mechanism_utils.c \
			linked_list_manage.c \
			error_handling.c \
			ft_atoi_long.c \
			cleaner.c \
			bubble_sort.c \
			error_handling_utils.c
CC = gcc
CFLAGS = -Wextra -Werror -Wall
OBJS := $(SRCFILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN) "$$IMG"
	@make -C libft/
	@make bonus -C libft/ 
	$(CC) -g $(CFLAGS) $(SRCFILES) $(LIBFT_EXEC) -o $(NAME)
clean:
	# rm -f *.o
	rm -f $(OBJS)
	make clean -C libft/
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft/
	
re:		fclean all

CROSS = "\033[8m"
RED = "\033[0;1;91m"
GREEN = "\033[0;1;32m"
BLUE = "\033[0;1;34m"

.PHONY: clean fclean re
NAME := push_swap
LIBFT_DIR = libft/
LIBFT_EXEC = ./libft/libft.a
SRCFILES := intro.c
CC = gcc
CFLAGS = -Wextra -Werror -Wall
OBJS := $(SRCFILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	make bonus -C libft/ 
	$(CC) -g $(CFLAGS) $(SRCFILES) $(LIBFT_EXEC) -o $(NAME)
clean:
	# rm -f *.o
	rm -f $(OBJS)
	make clean -C libft/
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft/
	
re:		fclean all

.PHONY: clean fclean re
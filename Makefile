NAME := push_swap
LIBFT_DIR = libft/
LIBFT_EXEC = ./libft/libft.a
SRCFILES := push_swap.c \
			mechanism.c \
			mechanism_II.c \
			linkedlistmerge.c \
			sort_small.c \
			sort_four.c \
			sort_five.c \
			sort_five_utils.c \
			indexes.c \
			radix.c \
			mechanism_utils.c \
			linked_list_manage.c \
			error_handling.c
CC = gcc
CFLAGS = -Wextra -Werror -Wall
OBJS := $(SRCFILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@make bonus -C libft/ 
	$(CC) -g $(CFLAGS) $(SRCFILES) $(LIBFT_EXEC) -o $(NAME)
	@echo "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
oooooooooooooooooooooooooooooooddoooodddddoooooooooooooooooooooooooooooooooooooo\n\
ooooooooooooooooooooooooooolc:;,,''''',,,;;:ccloodoooooooooooooooooooooooooooooo\n\
ooooooooooooooooooooodoc;,,,,,;;:coolcc:;;;,,,,,,,:odooooooooooooooooooooooooooo\n\
oooooooooooooooooooc;,',;coddxxxddddddddddxxxddolc;,;codoooooooooooooooooooooooo\n\
oooooooooooooooo:,,,;cldddddddddollllllllllllooodddo:,,;cooooooooooooooooooooooo\n\
ooooooooooooool,'cdxxddddddollllllllllllooooolllloodddl:,,;coooooooooooooooooooo\n\
ooooooooooooo:',dxxxxxddollllooooooooooooooooooolllllooddl;,,;looooooooooooooooo\n\
oooooooooodl,'cdxxddddolloooooooooooooooooooooooooollllooddoc;',looooooooooooooo\n\
ooooooooooc',oxxdddodoooooooooooooooooooooooooooooooooooooooodc.'ldooooooooooooo\n\
oooooooood:.cxddoooooooooddoolllllllllllllllloooooooooooooooooo:.,oooooooooooooo\n\
oooooooood:.;xdooooolccc::cccccccccccccc::::::::::;coooooooooooo;.;ooooooooooooo\n\
oooooooood:.;xdoc;:ccloodxkOOOOOOOOOOOOOOkkOkkkxxdc,cdoodoooooooo;.;oooooooooooo\n\
oooooooood:.,do:,cx00000OOOOOOOOOOOOOOOOOOOOOOOOOkx:,ododooooooooo,.:doooooooooo\n\
oooooooood,.:d:ck00K00000OOOOOOOOOOOOOOOOOOOOO0000k:;oddddooooooool'.cdooooooooo\n\
oooooooooo'.c::0XKKK000OOOOOOOOOOOOOOOOOOOOOOOO000koodddddddooooood:.,oooooooooo\n\
oooooooooo'.;:xNKKKK0000OOOOOOOOOOOOOOOOOOOOOOOOOOxddxdddddddoooood:.,oooooooooo\n\
oooooooooo, .lKXXKKKK000OOOO00000OOOOOOOOOOOOOOOOkxdddddddddddoooodc.'oooooooooo\n\
oooooooooo, 'kKXKKKK00OOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkddddddddddooodl..ldoooooooo\n\
oooooooood;.:OK0kxxddxkkkkkkkkkkxoccccccccldkkOOOOOOOOkxdddddddddodl..ldoooooooo\n\
oooooooood:.:0Oo:;,,,;:oxxxkkxxo:,',;,;;;;:lddxxkOOOOOOOkooddddddddl.'odoooooooo\n\
oooooooood:.,c::c::;,'';oxxkkxxl'';:c;,''..';;:loxkOOOOOOxodddddddd;.;dooooooooo\n\
ooooooooodl..cdo::c,.  .;:clll:''looc:,    .;;.':::ccllodoloddddddl.'odooooooooo\n\
oooooooooxl'lOkocoo'   ,''lddo;.cxddddc.. ..:o;,dxddoolllc:;:;;::c' .coooooooooo\n\
oooooooooo,;kOOkkkdc:;co;'x0OOc'lxdddddoooodxxc'oOkOOOOO00xooolc,.''..ldoooooooo\n\
oooooooooo';OK00OOkxxxxk;.o0OOx:,cxxxxxxxxxxko,:kOOOOOOOOOxloddxddxx:.;doooooooo\n\
ooooooooool,;kK0000OO0Ol.:O0OOOko,;oxkOOOOOkl,ckOOO0OOOOOOxdxkkddxkko..ldooooooo\n\
oooooooooodl..ldxkOkdl:''xKOOOkkkd::::cccccccokOO0O0OOOOOkkkkOOxddkkc.,ooooooooo\n\
oooooooooooo'.:ollllclo:dK0OOOOkkkddddolcldkkkkOOOOOOOOkkkkkOkxxxxko.'ldoooooooo\n\
oooooooooood;.oK000OOkl;oxkkxdolokl;oxxxxxxxxkkkkkkkkkkkkxxxkdlkOOx'.ldooooooooo\n\
ooooooooooodc.l00OOOOkxdlldddl::ldddxkxxxxxxxxxxxkkkkkkkxxxkxldOOk;.cdoooooooooo\n\
ooooooooooodo,:O0OOOOkkOkkxddddddxxxxxxxxxxxxxxxxxxxxxxxxxxo:,:dd;.:oooooooooooo\n\
ooooooooooood:,dOOOOkxxxxxxdddddddddxddddddxxxxxxxxxxxxxxxxllo'.':looooooooooooo\n\
oooooooooooodl';kOOkxdddddddddddoollc:;::lodxxxxxxxxxxxxxxxxxd'.ldoooooooooooooo\n\
oooooooooooood:.lkkkxo:cllc:::::;;;::ccccldddxxddddxxxxxxdxxxc.;oooooooooooooooo\n\
ooooooooooooooo;,lxkkddkOOkkxxxdddxxxxxxxxxddxxddddddddddddxkc.;oooooooooooooooo\n\
ooooooooooooooooc;;lxxxkOOkxxxddddxxxxxxxxdddddddddddddddddxkx,.cdoooooooooooooo\n\
oooooooooooooooooo:',oxxkOOOkkxxxxxxxkxxxdddddddoccoddddddxkkko.'ooooooooooooooo\n\
oooooooooooooooooool;';okOOOkkxxxxxxxxxdddddddl;,;codddddxxkkkk:.:dooooooooooooo\n\
oooooooooooooooooooool,':oxkxxxdddddddddddoc;;,;coddddddxxxkkkOx,.cooooooooooooo\n\
oooooooooooooooooooooooc'..,,;::;;;;;::;;,;;:codddddddxxxxxkkkkko;:ooooooooooooo\n\
ooooooooooooooooooooooodo'.:c;;;;;;;::cccloddodddddddxxxxxxkkxxxxdoooooooooooooo\n\
oooooooooooooooooooooooodc.,kOkxddooooooooodddddddddxxxxxxxxxdddoooooooooooooooo\n\
oooooooooooooooooooooooooo,.lOOOkddddddddddddddddddxxxxxxxdddooooooooooooooooooo\n\
ooooooooooooooooooooooooool.'xOkkkxxdddddddddddddddxxxxdddoooooooooooooooooooooo\n\
ooooooooooooooooooooooooooo;.cOkkkkxdddddddddddddddddddooooooooooooooooooooooooo"
clean:
	# rm -f *.o
	rm -f $(OBJS)
	make clean -C libft/
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft/
	
re:		fclean all

.PHONY: clean fclean re
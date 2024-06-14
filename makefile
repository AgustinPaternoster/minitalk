CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAMEC = client
NAMES = server
CFILE = client.c
SFILE = server.c
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
INC = minitalk.h

all: $(NAMES) $(NAMEC)

$(NAMES) : $(SFILE) $(INC) makefile
	@make -C ft_printf
	@make -C libft
	$(CC) $(FLAGS) $(SFILE) $(PRINTF) $(LIBFT) -o $(NAMES)
$(NAMEC) : $(CFILE) $(INC) makefile
	$(CC) $(FLAGS) $(CFILE) $(PRINTF) $(LIBFT) -o $(NAMEC)

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm $(NAMES)
	rm $(NAMEC)

re:	fclean all
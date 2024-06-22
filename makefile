CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAMEC = client
NAMES = server
CFILE = client.c
SFILE = server.c
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
HEADER = inc/minitalk.h

all: library $(NAMES) $(NAMEC)

$(NAMES) : $(SFILE) $(HEADER) makefile 
	$(CC) $(FLAGS) $(SFILE) $(HEADER) $(PRINTF) $(LIBFT) -o $(NAMES)

$(NAMEC) : $(CFILE) $(HEADER) makefile
	$(CC) $(FLAGS) $(CFILE) $(HEADER) $(PRINTF) $(LIBFT)  -o $(NAMEC)

library:
	@make -C libft
	@make -C ft_printf

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm $(NAMES)
	rm $(NAMEC)

re:	fclean all
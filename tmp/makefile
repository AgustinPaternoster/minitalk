CC = gcc
CFLAGS = -Wall -Werror -Wextra
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
HEADER = inc/minitalk.h
BINARIES = server client

all: library $(BINARIES) Makefile


$(BINARIES) : %: %.c $(HEADER)
	$(CC) $(FLAGS) $(HEADER) $(PRINTF) $(LIBFT) -o $@ $<


library:
	@make -C libft
	@make -C ft_printf

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm $(BINARIES)

re:	fclean all
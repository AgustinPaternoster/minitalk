CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAMEC = client
NAMES = server
CFILE = client.c
SFILE = server.c
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
HEADER = inc/minitalk.h

#---------bonus----------#

NAMEC_B = client_bonus
NAMES_B = server_bonus
CFILE_B = client_bonus.c
SFILE_B = server_bonus.c
HEADER_B = inc/minitalk_bonus.h

all: minitalk

minitalk : library $(NAMES) $(NAMEC) 

$(NAMES) : $(SFILE) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SFILE) $(HEADER) $(PRINTF) $(LIBFT) -o $(NAMES)

$(NAMEC) : $(CFILE) $(HEADER) Makefile
	$(CC) $(FLAGS) $(CFILE) $(HEADER) $(PRINTF) $(LIBFT)  -o $(NAMEC)

bonus : minitalk_bonus

minitalk_bonus : library $(NAMES_B) $(NAMEC_B)

$(NAMES_B) : $(SFILE_B) $(HEADER_B) Makefile
	$(CC) $(FLAGS) $(SFILE_B) $(HEADER_B) $(PRINTF) $(LIBFT) -o $(NAMES_B)

$(NAMEC_B) : $(CFILE_B) $(HEADER_B) Makefile
	$(CC) $(FLAGS) $(CFILE_B) $(HEADER_B) $(PRINTF) $(LIBFT)  -o $(NAMEC_B)



library:
	@make -C libft
	@make -C ft_printf

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm $(NAMES_B) $(NAMEC_B) $(NAMES) $(NAMEC)
	

re:	fclean all
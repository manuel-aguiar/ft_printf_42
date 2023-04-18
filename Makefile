FILES = 	ft_printf print_csdiu_perc print_pxX
	 
HEADERS = ft_printf.h

NAME = libftprintf.a


SRCS = $(addsuffix .c, $(FILES))
OBJS = ${SRCS:c=o}


CC = cc
FLAGS = -c -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f
	
all: $(NAME)
	
$(NAME): $(OBJS)
	$(LIB) $@ $(OBJS)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(FLAGS) -I$(HEADERS) $(SRCS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

mkclean: all clean

.PHONY: clean fclean re mkclean

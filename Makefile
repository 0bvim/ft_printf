# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 17:36:04 by vde-frei          #+#    #+#              #
#    Updated: 2023/08/26 10:31:20 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMMOM ###
NAME		=	libftprintf.a
LIBS		=	-lft
INCLUDES	=	-I ./includes
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDES)
FILES		=	ft_printf.c ft_put.c ft_print_var.c ft_flags_utils.c
FILESB		=	ft_printf_bonus.c ft_put_bonus.c ft_print_var_bonus.c ft_flags_utils_bonus.c
SRCS		=	$(addprefix sources/, $(FILES))
BSRCS		=	$(addprefix bonus/, $(FILESB))
OBJS		=	$(SRCS:.c=.o)
BOBJ		=	$(BSRCS:.c=.o)
AR		=	ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BOBJ) 
	@$(AR) $(NAME) $(BOBJ)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

cleanbonus: 
	$(RM) $(BOBJ)

fcleanbonus: cleanbonus

rebonus: fcleanbonus bonus 

re: fclean all

.PHONY: all clean fclean re cleanb fcleanb rebonus

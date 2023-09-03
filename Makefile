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
LIBFT_PATH	=	./libraries/libft
LIBS_PATH 	= 	-L$(LIBFT_PATH)
LIBS		=	-lft
INCLUDES	=	-I ./includes -I $(LIBFT_PATH)/includes
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
FILES		=	ft_printf.c ft_put.c ft_print_var.c ft_flags_utils.c
FILESB		=	ft_printf_bonus.c ft_put_bonus.c ft_print_var_bonus.c ft_flags_utils_bonus.c
SRCS		=	$(addprefix sources/, $(FILES))
BSRCS		=	$(addprefix bonus/, $(FILESB))
OBJS		=	$(SRCS:.c=.o)
BOBJ		=	$(BSRCS:.c=.o)
AR		=	ar -rc

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: $(BOBJ) 
	@$(AR) $(NAME) $(BOBJ)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

cleanb: 
	$(RM) $(BOBJ)

fcleanb: cleanb

rebonus: fcleanb bonus 

re: fclean all

.PHONY: all clean fclean re cleanb fcleanb rebonus

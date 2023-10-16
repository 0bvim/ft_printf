# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 17:36:04 by vde-frei          #+#    #+#              #
#    Updated: 2023/10/12 05:20:14 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMMOM ###
NAME		=	libftprintf.a
INCLUDES	=	-I ./includes
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDES)
FILES		=	ft_printf.c ft_put.c ft_print_var.c \
			ft_flags_utils.c ft_putnbr_base.c ft_atoi.c \
			ft_numbers.c ft_putchar.c ft_putstr.c
FILESB		=	ft_printf_bonus.c ft_put_bonus.c ft_print_var_bonus.c \
			ft_flags_utils_bonus.c ft_putnbr_base_bonus.c ft_atoi_bonus.c \
			ft_numbers_bonus.c ft_putchar_bonus.c ft_putstr_bonus.c
SRCS		=	$(addprefix sources/, $(FILES))
BSRCS		=	$(FILESB)
OBJS		=	$(SRCS:.c=.o)
BOBJ		=	$(BSRCS:.c=.o)
AR		=	ar -rcs

SLEEP = sleep 1
PRINTD = printf "Done\n"

ifdef WITH_BONUS
	OBJS += $(BOBJ)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@printf "Lib Generated\n"
	@$(SLEEP) 
	@$(PRINTD)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(AR) $(NAME) $@
	@printf "Making Objects...\n"
	@$(SLEEP) 

bonus:
	@$(MAKE) WITH_BONUS=TRUE --no-print-directory

clean:
	@$(RM) $(OBJS)
	@printf "Cleaning...\n"
	@$(SLEEP) 
	@$(PRINTD)

fclean: clean
	@$(RM) $(NAME)
	@$(SLEEP) 
	@$(PRINTD)

cleanbonus: 
	@$(RM) $(BOBJ)
	@$(SLEEP) 
	@$(PRINTD)

fcleanbonus: cleanbonus fclean
	@printf "Cleaning...\n"
	@$(SLEEP) 
	@$(PRINTD)

rebonus: fcleanbonus bonus 
	@printf "Remaking all\n"
	@$(SLEEP) 
	@$(PRINTD)

re: fclean all
	@printf "Remaking all\n"
	@$(SLEEP) 
	@$(PRINTD)

.PHONY: all bonus clean fclean re cleanbonus fcleanbonus rebonus

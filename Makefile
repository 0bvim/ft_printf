# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 17:36:04 by vde-frei          #+#    #+#              #
#    Updated: 2023/10/16 16:42:24 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = lib/libft/libft.a

SHELL := /bin/bash
COUNT := 0
SLEEP := sleep 0.5

BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

MANDATORY = Static library compiled
LBONUS = Bonus Static library compiled
CLEAN = Objects delete
FCLEAN = Static library delete
LIBNAME = ft_printf
BLIBNAME = ft_printf_bonus
COMP = Compiling

DFLAGS = -Wall -Wextra -Werror -g3 # TO DEBBUG
CFLAGS = -Wall -Werror -Wextra -O3 -fomit-frame-pointer -finline-functions # TO IMPROVE PERFORMANCE
ARFLAGS = rcs

SRC = sources
BONUS = sources/bonus
INC = includes
OBJ = obj

INCLUDES = -I$(INC)/

CFILES = $(addprefix $(SRC)/, ft_printf.c ft_put.c ft_print_var.c ft_flags_utils.c ft_putnbr_base.c \
		 ft_atoi.c ft_numbers.c ft_putchar.c ft_putstr.c)

BFILES = $(addprefix $(BONUS)/, ft_printf_bonus.c ft_put_bonus.c ft_print_var_bonus.c \
		 ft_flags_utils_bonus.c ft_putnbr_base_bonus.c ft_atoi_bonus.c \
		 ft_numbers_bonus.c ft_putchar_bonus.c ft_putstr_bonus.c)

OBJECT =  $(patsubst %, $(OBJ)/%, $(notdir $(CFILES:.c=.o)))

ifdef WITH_BONUS
	CFILES = $(BFILES)
	MANDATORY = $(LBONUS)
	MAGENTA = $(YELLOW)
	LIBNAME = $(BLIBNAME)
endif

ifdef WITH_DEBBUG
	CFLAGS = $(DFLAGS)
endif

all: $(OBJ) $(NAME)

$(NAME): $(OBJECT)
	@$(AR) $(ARFLAGS) $@ $?
	@$(SLEEP)
	@printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean:
	@$(RM) -rf $(OBJ)
	@$(SLEEP)
	@printf "$(RED)$(CLEAN)$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"

re: fclean all

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

debbug:
	@make WITH_DEBBUG=TRUE --no-print-directory

.PHONY: all bonus clean fclean re debbug

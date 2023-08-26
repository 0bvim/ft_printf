# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 12:05:38 by vde-frei          #+#    #+#              #
#    Updated: 2023/08/26 06:56:31 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#				CONFIGURATION				       #
#******************************************************************************#

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I.

#******************************************************************************#
#				  INCLUDES				       #
#******************************************************************************#

HEADER = ./includes/./includes/libft.h


#******************************************************************************#
#				SOURCE FILES				       #
#******************************************************************************#
MANDATORY = ft_atoi.c \
	    ft_isalnum.c \
	    ft_isalpha.c \
	    ft_isascii.c \
	    ft_isdigit.c \
	    ft_isprint.c \
	    ft_strlen.c \
	    ft_tolower.c \
	    ft_toupper.c \
	    ft_memset.c \
	    ft_bzero.c \
	    ft_memcpy.c \
	    ft_memmove.c \
	    ft_strlcpy.c \
	    ft_strlcat.c \
	    ft_strncmp.c \
	    ft_strchr.c \
	    ft_strrchr.c \
	    ft_strdup.c \
	    ft_memchr.c \
	    ft_strnstr.c \
	    ft_memcmp.c \
	    ft_calloc.c \
	    ft_putchar_fd.c \
	    ft_putstr_fd.c \
	    ft_putendl_fd.c \
	    ft_putnbr_fd.c \
	    ft_itoa.c \
	    ft_substr.c \
	    ft_strjoin.c \
	    ft_strtrim.c \
	    ft_split.c \
	    ft_strmapi.c \
	    ft_striteri.c

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

#******************************************************************************#
#				 MAKEFILE SETUP				       #
#******************************************************************************#

SRCS = $(addprefix sources/,$(MANDATORY))
BSRCS = $(addprefix sources/,$(BONUS))

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

GREEN := \033[32m
CLEAR_COLOR := \033[0m

PRINT = printf
PRINT_DONE = $(PRINT) "$(GREEN)[-----'\!done!/'-----]$(CLEAR_COLOR)\n"
PRINT_CLEANED = $(PRINT) "$(GREEN)[-----'\!cleaned!/'-----]$(CLEAR_COLOR)\n"


ifdef WITH_BONUS
	OBJS += $(BOBJS)
endif

#******************************************************************************#
#				  LIBFT CONFIG				       #
#******************************************************************************#

all: $(NAME)
	
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(PRINT_DONE)
bonus:
	@make WITH_BONUS=TRUE --no-print-directory

clean:
	@rm -f $(OBJS) $(BOBJS)
	@$(PRINT_CLEANED)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus

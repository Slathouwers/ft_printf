# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 09:55:38 by slathouw          #+#    #+#              #
#    Updated: 2021/09/22 08:33:25 by slathouw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
LIBFT 	= libft
INCLUDES= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJDIR	= obj


SOURCES	=	ft_printf.c ft_print_hex.c ft_print_uint.c ft_print_int.c \
			ft_print_char.c ft_print_str.c
SRCDIR 	= srcs
SRCS 	= ${addprefix $(SRCDIR)/, $(SOURCES)}
OBJS	= ${addprefix $(OBJDIR)/, $(SOURCES:.c=.o)}


BONUSSOURCES = ft_printf_bonus.c ft_print_hex_bonus.c ft_print_uint_bonus.c ft_print_int_bonus.c \
			ft_print_char_bonus.c ft_print_str_bonus.c ft_field_parse_bonus.c
BONUSSRCDIR = srcs_bonus
BONUSSRCS = ${addprefix $(BONUSSRCDIR)/, $(BONUSSOURCES)}
BONUSOBJS = ${addprefix $(OBJDIR)/, $(BONUSSOURCES:.c=.o)}


all : 		${NAME}

$(NAME) :	$(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p obj
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

bonus :	$(BONUSOBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(BONUSOBJS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(BONUSSRCDIR)/%.c
	mkdir -p obj
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUSOBJS)
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re :		fclean all

.PHONY: all clean fclean re bonus

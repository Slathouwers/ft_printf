# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 09:55:38 by slathouw          #+#    #+#              #
#    Updated: 2021/09/20 10:29:30 by slathouw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
LIBFT 	= libft
INCLUDES= includes
SOURCES	=	ft_printf.c ft_print_hex.c ft_print_uint.c ft_print_int.c \
			ft_print_char.c
SRCDIR 	= srcs
OBJDIR	= obj
SRCS 	= ${addprefix $(SRCDIR)/, $(SOURCES)}
OBJS	= ${addprefix $(OBJDIR)/, $(SOURCES:.c=.o)}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror



all : 		${NAME}

$(NAME) :	$(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p obj
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re :		fclean all

.PHONY: all clean fclean re

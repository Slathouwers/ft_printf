# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 11:59:30 by slathouw          #+#    #+#              #
#    Updated: 2021/09/19 15:51:27 by slathouw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
SRCS 		= ft_isalnum.c ft_isprint.c ft_strlen.c ft_tolower.c ft_atoi.c 	\
			ft_isalpha.c ft_memset.c ft_strncmp.c ft_toupper.c ft_bzero.c	\
			ft_isascii.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_isdigit.c 	\
			ft_strdup.c ft_strrchr.c ft_memcpy.c ft_memmove.c ft_strlcpy.c 	\
			ft_strlcat.c ft_memchr.c ft_memcmp.c ft_substr.c ft_strjoin.c 	\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c	\
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c 	\
			ft_putstrn_fd.c ft_putstrl_fd.c ft_lstadd_back.c ft_lstadd_front.c\
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_nbr_len.c\
			ft_unbr_len.c ft_uitoa.c ft_lstmap.c ft_lstnew.c ft_lstsize.c	\
			ft_putunbr_fd.c
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

all : 		${NAME}

${NAME} :	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all

.PHONY: 	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 12:40:04 by gbreana           #+#    #+#              #
#    Updated: 2022/05/05 12:31:37 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
INCL		=	../include/libft.h
SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
                ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
                ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
                ft_memset.c ft_strchr.c ft_strchri.c ft_strlen.c ft_strrchr.c\
                ft_strnstr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
                ft_tolower.c ft_toupper.c ft_strncmp.c ft_split.c\
				ft_substr.c ft_strjoin.c ft_strnjoin.c ft_strtrim.c \
				ft_itoa.c ft_strmapi.c ft_putstr_fd.c ft_putchar_fd.c\
				ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c\
				ft_putstr.c ft_putunbr.c ft_isspace.c\
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
				ft_lstadd_back_bonus.c ft_lstsize_bonus.c\
 				ft_lstlast_bonus.c ft_lstdelone_bonus.c\
 				ft_lstclear_bonus.c ft_lstiter_bonus.c\
 				ft_lstmap_bonus.c\
 				ft_printf.c get_next_line.c
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

DEPS		=	$(patsubst %.c,%.d,$(SRCS))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD
RM			=	rm -rf

override		OBJS_ALL ?= $(OBJS)
override		DEP_ALL ?= $(DEPS)

%.o:			%.c Makefile
				$(CC) $(CFLAGS) -I $(INCL) -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS_ALL) $(INCL)
				ar -rcs $(NAME) $(OBJS_ALL) $?
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(DEPS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
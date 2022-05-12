# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 08:25:42 by gbreana           #+#    #+#              #
#    Updated: 2022/05/11 18:01:27 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INCL		=	./include/so_long.h

LIB			=	-L ./libft -lft
LIBFT		=	libft.a
MLX			=	-L ./mlx -lmlx -framework OpenGL -framework Appkit
MLXLIB		=	mlx


MDIR		= 	./sources/mandatory/
BDIR		=	./sources/bounus/

MFLS		=	main.c errors.c hooks.c readmap.c map_check.c
BFLS		=	

MSRC		=	$(addprefix $(MDIR), $(MFLS))
BSRC		=	$(addprefix $(BDIR), $(BFLS))

MOBJS		=	$(patsubst %.c,%.o,$(MSRC))
BOBJS		=	$(patsubst %.c,%.o,$(BSRC))

MDEPS		=	$(patsubst %.c,%.d,$(MSRC))
BDEPS		=	$(patsubst %.c,%.d,$(BSRC))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD
RM			=	rm -rf

override		OBJS_ALL ?= $(MOBJS)
override		DEP_ALL ?= $(DEPS)

%.o:			%.c Makefile libft/libft.a
				$(CC) $(CFLAGS) -Imlx -I $(INCL) -c $< -o ${<:.c=.o}


all:			$(LIBFT) $(MLXLIB) $(NAME)

$(LIBFT):
				@make -s -C ./libft

$(MLXLIB):
				@make -C ./mlx

#$(MLXLIB) $(LIBFT)
$(NAME):		$(MLXLIB) $(LIBFT) $(MOBJS)
				@make -s -C ./mlx
				@$(CC) $(MOBJS) $(LIB) $(MLX) -o $@

bonus:			$(MLXLIB) $(LIBFT) $(BOBJS)
				@$(CC) $(BOBJS) $(LIB) $(MLX) -o $@

clean:
				@make clean -s -C ./libft
				@make clean -s -C ./mlx
				$(RM) $(MOBJS) $(MDEPS) $(BOBJS) $(BDEPS)

fclean:			clean
				@make fclean -s -C ./libft
				@make re -s -C ./mlx
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 08:25:42 by gbreana           #+#    #+#              #
#    Updated: 2022/06/05 14:40:16 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INCLM		=	./include/so_long.h
INCLB		=	./include/so_long_bonus.h

LIB			=	-L ./libft -lft
LIBFT		=	libft.a
MLX			=	-L ./mlx -lmlx -framework OpenGL -framework Appkit
MLXLIB		=	mlx

MDIR		= 	./sources/mandatory/
BDIR		=	./sources/bonus/

MFLS		=	main.c errors.c init.c \
				hooks.c map_read.c map_check.c \
				utils.c render.c moves.c
BFLS		=	main_bonus.c errors_bonus.c init_bonus.c \
				hooks_bonus.c map_read_bonus.c map_check_bonus.c \
				utils_bonus.c render_bonus.c moves_bonus.c

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

$(MDIR)%.o:		$(MDIR)%.c Makefile libft/libft.a
				$(CC) $(CFLAGS) -Imlx -I $(INCLM) -c $< -o ${<:.c=.o}
$(BDIR)%.o:		$(BDIR)%.c Makefile libft/libft.a
				$(CC) $(CFLAGS) -Imlx -I $(INCLB) -c $< -o ${<:.c=.o}

all:			$(LIBFT) $(MLXLIB) $(NAME)

$(LIBFT):
				@make -C ./libft

$(MLXLIB):
				@make -C ./mlx

$(NAME):		$(MLXLIB) $(LIBFT) $(MOBJS)
				@make -s -C ./mlx
				@$(CC) $(MOBJS) $(LIB) $(MLX) -o $@

bonus:			$(MLXLIB) $(LIBFT) $(BOBJS)
				@make -s -C ./mlx
				@$(CC) $(BOBJS) $(LIB) $(MLX) -o so_long_bonus

clean:
				@make clean -s -C ./libft
				@make clean -s -C ./mlx
				$(RM) $(MOBJS) $(MDEPS) $(BOBJS) $(BDEPS)

fclean:			clean
				@make fclean -s -C ./libft
				@make re -s -C ./mlx
				$(RM) $(NAME) so_long_bonus

re:				fclean all

.PHONY:		all clean fclean re bonus
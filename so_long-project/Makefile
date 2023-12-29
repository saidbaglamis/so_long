# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 02:11:22 by mbaglami          #+#    #+#              #
#    Updated: 2023/11/26 02:11:22 by mbaglami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

MINILIBX_PATH	=	./minilibx

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CC 				= gcc

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -Lminilibx -lmlx -framework OpenGL -framework AppKit


REMOVE 			= rm -f

SRCS_DIR		= ./sources/

SRCS 			= $(addprefix $(SRCS_DIR),\
				so_long.c			\
				ft_check_map.c		\
				ft_close_game.c		\
				ft_free_memory.c	\
				ft_handle_input.c	\
				ft_init_game.c		\
				ft_init_map.c		\
				ft_render_map.c		\
				ft_utils.c)

all:			$(NAME)

${NAME}: 		$(LIBFT) mlx
				@${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

$(LIBFT):
		@make -C $(LIBFT_PATH) all

mlx:
		@make -C $(MINILIBX_PATH) all

clean:
				@make -C $(LIBFT_PATH) clean
				@make -C $(MINILIBX_PATH) clean
				@echo

fclean:
				${REMOVE} ${NAME}
				@make -C $(LIBFT_PATH) fclean
				@make -C $(MINILIBX_PATH) clean
				@echo "${NAME}: ${RED}${NAME} were deleted${RESET}"
				@echo

re:				fclean all

.PHONY:			all clean fclean re rebonus valgrind

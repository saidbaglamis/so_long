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

LIBFT 			= ./libraries/Libft/libft.a

CC 				= gcc

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -L/minilibx-linux -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

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

all:			${LIBFT} ${NAME}

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C libraries/Libft

clean:
				make clean -C libraries/Libft
				@echo

fclean:
				${REMOVE} ${NAME}
				@echo "${NAME}: ${RED}${NAME} were deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re rebonus valgrind

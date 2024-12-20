# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:47:15 by frocha            #+#    #+#              #
#    Updated: 2024/11/11 18:47:17 by frocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap_radix.c push_swap_utils.c check_order_and_validity.c push_swap_instructions.c \
		push_swap_instructions_2.c push_swap_instructions_3.c find_number_instructions.c \
		push_swap.c quicksort_functions.c free_arrays.c free_stack.c push_stack.c \
		sort_3.c sort_to_5.c
OBJS = ${SRCS:.c=.o}
INCLUDE		=	-I.

NAME = push_swap

$(NAME): ${OBJS}
	@make re -C ./libft
	${CC} ${CFLAGS}  $^ ${INCLUDE} -Llibft -lft -o ${NAME}

all: $(NAME)

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
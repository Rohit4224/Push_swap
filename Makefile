# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:34:15 by rkhinchi          #+#    #+#              #
#    Updated: 2023/03/21 18:23:03 by rkhinchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		push_swap

NAME_BONUS	=		checker	

SRC			=		src/push_s_utils.c \
					src/push_swap.c \
					src/ra_rr.c \
					src/rra_rrr.c \
					src/sa_pa.c \
					src/utils02.c \
					src/sorting.c \
					src/utils03.c \
					src/error.c \
					src/sort_lis.c \
					src/lis.c \
					src/utils04.c \
					src/move_2_a.c \
					src/best_fusion.c \
					src/arr_4_a.c 

SRC_BONUS		=	src/checker.c \
					src/check_output.c \
					src/ra_rr_checker.c \
					src/rra_rrr_checker.c \
					src/sa_pa_checker.c \
					src/error.c \
					src/utils03.c \
					src/utils04.c \
					src/utils02.c \
					src/ra_rr.c \
					src/rra_rrr.c \
					src/sa_pa.c 

LIBFT		=		libft/libft.a

OBJ			=		$(SRC:.c=.o)

OBJ_BONUS	=		$(SRC_BONUS:.c=.o)


CC			=		gcc

RM			=		rm -f

CFLAGS		=		-Wall -Wextra -Werror -g

$(NAME):	$(OBJ)
					make -C ./libft
					$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
					make clean -C libft
					${RM} $(OBJ) $(OBJ_BONUS)

fclean:		clean
					make fclean -C libft
					${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:					fclean all

bonus:		all $(OBJ_BONUS)
					$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)

.PHONY:		all clean fclean re

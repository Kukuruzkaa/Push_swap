# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 12:55:59 by ddiakova          #+#    #+#              #
#    Updated: 2021/05/23 12:56:04 by ddiakova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

LIBFT 			= Libft/libft.a

SRCS 			= push_swap.c \
					init_clear.c \
					errors.c \
					instructions.c \
					utils.c \
					sorting.c \
					simple_sort.c \
					middle_sort.c \
					big_sort.c \

OBJS			= $(SRCS:%.c=%.o)

RM 				= rm -rf

CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra -g -c 
FSAN			= -g3 -fsanitize=address
SRCDIR 			= src
OBJDIR 			= objs

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

all:			$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

$(LIBFT):
				@make bonus -s -C Libft

$(NAME):		$(OBJS) $(LIBFT)
				$(CC) -o $(NAME) $(OBJS) Libft/libft.a

clean:
				$(RM) $(OBJDIR)
				make clean -C Libft
				
fclean:			clean
				$(RM) $(NAME)
				make fclean -C Libft

re: 			fclean all

.PHONY: 		all clean fclean re bonus

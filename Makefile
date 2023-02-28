# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:34:33 by mle-boud          #+#    #+#              #
#    Updated: 2023/02/28 23:27:00 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = push_swap.h /usr/include mlx_linux

FOR_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

################ DIRS ################
DIR_TOOLS = tools/
DIR_PARSE = parse/

################ SRCS ################
SRCS = main.c start_game.c \

TOOLS = error_handler.c my_mlx_tools.c stack_tools.c \

PARSE = check_doability.c check_validity.c parse.c \

############ DIRS + SRCS #############
SRCS_TOOLS = $(addprefix $(DIR_TOOLS), $(TOOLS))
SRCS_PARSE = $(addprefix $(DIR_PARSE), $(PARSE))

################ OBJS ################
OBJS_SRCS = $(patsubst %.c, %.o,$(SRCS))
OBJS_TOOLS =  $(patsubst %.c,%.o,$(SRCS_TOOLS))
OBJS_PARSE =  $(patsubst %.c,%.o,$(SRCS_PARSE))
OBJS = $(OBJS_SRCS) $(OBJS_TOOLS) $(OBJS_PARSE)

################ PHONY ################
.PHONY: all clean fclean re $(NAME)

################ RULES ################
all: otherMakefile $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $^ $(FOR_MLX) -o $@

otherMakefile:
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -O3 -c $< -o $@

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME)

re: fclean all
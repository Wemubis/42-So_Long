# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:34:33 by mle-boud          #+#    #+#              #
#    Updated: 2023/02/23 12:10:45 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = push_swap.h /usr/include mlx_linux

FOR_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

################ DIRS ################
DIR_RULES = /
DIR_SORT = /
DIR_UTILS = /

################ SRCS ################
SRCS = 

RULES = 

SORT = 

UTILS = 

############ DIRS + SRCS #############
SRCS_RULES = $(addprefix $(DIR_RULES), $(RULES))
SRCS_SORT = $(addprefix $(DIR_SORT), $(SORT))
SRCS_UTILS = 	$(addprefix $(DIR_UTILS), $(UTILS))

################ OBJS ################
OBJS_SRCS = $(patsubst %.c, %.o,$(SRCS))
OBJS_RULES =  $(patsubst %.c,%.o,$(SRCS_RULES))
OBJS_SORT =  $(patsubst %.c,%.o,$(SRCS_SORT))
OBJS_UTILS =  $(patsubst %.c,%.o,$(SRCS_UTILS))
OBJS = $(OBJS_SRCS) $(OBJS_RULES) $(OBJS_SORT) $(OBJS_UTILS)

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
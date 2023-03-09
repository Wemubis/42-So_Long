# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:33:24 by mle-boud          #+#    #+#              #
#    Updated: 2022/12/11 19:33:24 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

HEADER = libft.h

################ DIRS ################
DIR_CHAR = char/
DIR_CONV_PUT = conv_put/
DIR_GNL = gnl/
DIR_MEM = mem/
DIR_PRINTF = printf/
DIR_STRING = string/
DIR_LIST = list/

################ SRCS ################
CHAR = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_tolower.c ft_toupper.c \

CONV_PUT = ft_atoi.c ft_itoa.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c \

GNL = get_next_line.c get_next_line_utils.c \

MEM = ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c \

PRINTF = ft_printf.c ft_putnbr_base_printf.c ft_putnbr_printf.c \
		ft_putnbr_unsigned_printf.c ft_putptr_base_printf.c ft_putstr_printf.c \

STRING = ft_bzero.c ft_calloc.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_strcat.c ft_strcmp.c ft_find_char.c ft_chrtrim.c \

LIST = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
		ft_lstsize.c \

############ DIRS + SRCS #############
SRCS_CHAR = $(addprefix $(DIR_CHAR), $(CHAR))
SRCS_CONV_PUT = $(addprefix $(DIR_CONV_PUT), $(CONV_PUT))
SRCS_GNL = 	$(addprefix $(DIR_GNL), $(GNL))
SRCS_MEM = 	$(addprefix $(DIR_MEM), $(MEM))
SRCS_PRINTF = $(addprefix $(DIR_PRINTF), $(PRINTF))
SRCS_STRING = $(addprefix $(DIR_STRING), $(STRING))
SRCS_LIST = $(addprefix $(DIR_LIST), $(LIST))

################ OBJS ################
OBJS_CHAR =  $(patsubst %.c,%.o,$(SRCS_CHAR))
OBJS_CONV_PUT =  $(patsubst %.c,%.o,$(SRCS_CONV_PUT))
OBJS_GNL =  $(patsubst %.c,%.o,$(SRCS_GNL))
OBJS_MEM =  $(patsubst %.c,%.o,$(SRCS_MEM))
OBJS_PRINTF =  $(patsubst %.c,%.o,$(SRCS_PRINTF))
OBJS_STRING =  $(patsubst %.c,%.o,$(SRCS_STRING))
OBJS_LIST = $(patsubst %.c,%.o,$(SRCS_LIST))
OBJS = $(OBJS_CHAR) $(OBJS_CONV_PUT) $(OBJS_GNL) $(OBJS_MEM) $(OBJS_PRINTF) $(OBJS_STRING) $(OBJS_LIST)

################ PHONY ################
.PHONY: all clean fclean re

################ RULES ################
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 15:49:02 by yehyun            #+#    #+#              #
#    Updated: 2023/01/27 15:08:48 by yehyun           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
RM = rm -f

MLXDIR = ../mlx/
SRC_DIR = srcs/

SRCS = main.cpp Param.cpp Window.cpp

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) -L$(MLXDIR) -lmlx $(FRAMEWORK) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	make clean -C $(MLXDIR)
	$(RM) $(OBJS)

fclean :
	make clean -C $(MLXDIR)
	$(RM) $(OBJS)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
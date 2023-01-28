# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 15:49:02 by yehyun            #+#    #+#              #
#    Updated: 2023/01/28 14:56:46 by yehyun           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CPP = c++
CXXFLAGS = -Wall -Wextra -Werror
MLXFLAG = glfw
RM = rm -f

MLXDIR = ../MLX42/
SRC_DIR = srcs/

SRC = main.cpp Param.cpp Window.cpp Map.cpp utils.cpp

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLXDIR)
	$(CPP) $(CXXFLAGS) libmlx42.a -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit $^ -o $@

%.o : %.cpp
	$(CPP) $(CXXFLAGS) -Imlx -c $< -o $@

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
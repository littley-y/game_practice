# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 16:31:35 by yehyun            #+#    #+#              #
#    Updated: 2023/01/24 13:44:15 by yehyun           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = my_tester
NAME_STL = std_tester

all : $(NAME) $(NAME_STL)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAG) $^ -o $@

$(NAME_STL) : $(OBJS)
	$(CPP) $(CPPFLAG) -D1 $^ -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : 
	rm -f $(OBJS) $(NAME) $(NAME_STL)

re : 
	make fclean
	make all

debug :
	make all

.PHONY : all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:52:47 by yehyun            #+#    #+#              #
#    Updated: 2023/02/08 16:54:29 by yehyun           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c ft_strlcpy.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_lstclear.c ft_lstadd_back.c ft_lstdelone.c ft_lstsize.c ft_lstnew.c \
		ft_strrev.c get_next_line.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : 
	@make fclean 
	@make all

.PHONY: all clean fclean re
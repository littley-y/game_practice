NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
RM = rm -f

MLXDIR = ../mlx/
LIBDIR = ../libft/
SRC_DIR = srcs/

SRC = main.c utils.c game.c img.c map.c key.c put_player.c enemy.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(CFLAGS) -Imlx/ -L$(MLXDIR) -lmlx -L$(LIBDIR) -lft $(FRAMEWORK) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@make clean -C $(MLXDIR)
	@make clean -C $(LIBDIR)
	@$(RM) $(OBJS)

fclean :
	@make clean -C $(MLXDIR)
	@make fclean -C $(LIBDIR)
	@$(RM) $(OBJS) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
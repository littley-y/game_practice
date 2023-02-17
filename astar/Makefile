NAME = astar

CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
RM = rm -f

MLXDIR = ../mlx/
LIBDIR = ../libft/
SRC_DIR = srcs/

SRC = main.c utils.c game.c img.c map.c key_and_mouse.c astar.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

ifdef DFLAG
	CFLAGS += -g2 -fsanitize=address
endif

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(CFLAGS) -L$(MLXDIR) -lmlx -L$(LIBDIR) -lft $(FRAMEWORK) $^ -o $@

debug:
	@make fclean
	@make DFLAG=1 all

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@make clean -C $(MLXDIR)
	@make clean -C $(LIBDIR)
	@$(RM) $(OBJS)

fclean :
	@make clean -C $(MLXDIR)
	@make fclean -C $(LIBDIR)
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all bonus clean fclean re
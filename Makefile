NAME = so_long

CC = gcc
CFLAGS = 

LIBFT = -L libft -lft
LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/

SRC = parser.c \
		init.c \
		main.c \
		get_next_line/get_next_line.c \
		free.c \
		textures.c \
		draw.c \
		unitsize.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@chmod 777 mlx_linux/configure
	@$(MAKE) -C mlx_linux
	echo "\033[36mMaking So Long\033[0m"
	$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	$(CC) -c $^  -g

bonus : all

clean :
	@$(MAKE) fclean -C libft
	echo "\033[35mCleaning Mlx's objects...\033[0m"
	@$(MAKE) clean -C mlx_linux
	echo "\033[32mDone\033[0m"
	echo "\033[35mCleaning So Long's objects...\033[0m"
	rm -f $(OBJ)
	echo "\033[32mDone\033[0m"

fclean :
	@make clean
	echo "\033[35mCleaning So_Long...\033[0m"
	@rm -f $(NAME)
	echo "\033[32mDone\033[0m"

re : fclean
	make all

.PHONY : all clean fclean re bonus
.SILENT :

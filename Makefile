NAME    = so_long
CC      =  gcc
# CFLAGS  = -Wall -Wextra -Werror -g3
RM      = rm -f

# Add the path to the MiniLibX library
LIBDIR  = minilibx-linux
LIBS    = -L$(LIBDIR) -lmlx -lXext -lX11 -lm

# Include directory for MiniLibX header files
INCLUDE = -I$(LIBDIR)

# Source and object files
SRC     = src/so_long.c src/initialize.c src/run.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

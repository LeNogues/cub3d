NAME=cub3d
LIBFTNAME=libft.a
CC=cc
CFLAGS=-Wall -Werror -Wextra -Ilibft -g3
LIBFLAGS= -lft -Llibft
LIBFTDIR = ./libft

SRC=    src/main.c \
		src/parsing/parsing.c \
		src/parsing/verif_pre_open.c \
		src/parsing/open_file.c \
		src/parsing/file_is_valid.c \
		src/parsing/line_is_valid.c \
		src/utils/error_message.c \
		src/utils/close_all_fd.c \
		src/utils/init_fd.c
	

OBJ_DIR=obj
OBJS=$(SRC:%.c=$(OBJ_DIR)/%.o)

# Create necessary directories for .o files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFLAGS)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

all: $(NAME)

default: all

.PHONY: all re clean fclean

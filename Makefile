NAME = fractol

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INCLUDES_DIR = ./includes

LIBFT_DIR = $(addprefix $(INCLUDES_DIR)/, libft)
LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

MLX_DIR = $(addprefix $(INCLUDES_DIR)/, minilibx-linux)
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

SRCS = $(addprefix $(SRCS_DIR)/, fractol_basic_utils.c fractol_fractals.c \
		fractol_init.c fractol_main.c fractol_math_utils.c fractol_render.c)

OBJS = $(SRCS:.c=.o)
OBJS := $(patsubst $(SRCS_DIR)/%,$(OBJS_DIR)/%,$(OBJS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(MLX_INC) $(LIBFT_INC) 
LIBFT_INC = -I $(LIBFT_DIR)
MLX_INC = -I $(MLX_DIR)
LIBFT_LINK = -L $(LIBFT_DIR) -l ft -l pthread
MLX_LINK = -L $(MLX_DIR) -l mlx -lXext -lX11
RM = rm -rf

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): ${OBJS}
	$(CC) $(OBJS) $(MLX_LINK) $(LIBFT_LINK) -lm -o $(NAME)

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
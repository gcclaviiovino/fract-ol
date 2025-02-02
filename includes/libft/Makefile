SRCFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c get_next_line_utils.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c \
			ft_printf.c ft_printf_utils.c ft_printf_ptr_format.c \
			ft_printf_num_formats.c ft_printf_char_formats.c

BSRCFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
OBJFILES = $(SRCFILES:.c=.o)
BOBJFILES = $(BSRCFILES:.c=.o)
NAME = libft.a
LIBCR = ar rcs
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

$(NAME): ${OBJFILES}
	$(LIBCR) $(NAME) $(OBJFILES)

bonus: ${NAME} ${BOBJFILES}
	$(LIBCR) $(NAME) $(BOBJFILES)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME) $(OBJFILES)

re: fclean all
.PHONY: all clean fclean re bonus
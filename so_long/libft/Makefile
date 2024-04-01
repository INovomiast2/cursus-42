NAME = libft.a
CC = @cc
FLAGS = -Wall -Wextra -Werror

SRCS := $(shell find . -name "*.c")

OBJS := ${SRCS:.c=.o}

BONUS_SRCS := $(shell find . -name "*_bonus.c")
BONUS_OBJS := ${BONUS_SRCS:.c=.o}

HEADERS = -I ./libft.h

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
		 @ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
		 @echo "\033[0;32m$(NAME) CREATED SUCCESSFULLY!\033[0m"

%.o: %.c $(HEADERS)
		 $(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
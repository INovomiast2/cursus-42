NAME = so_long
CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX = ./libs/MLX42
LIBFT = ./libs/libft

HEADERS := -I ./includes -I $(LIBMLX)/include -I $(LIBFT)/libft.h
LIBS := $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib" -pthread -lm
SRCS := $(shell find ./srcs -iname "*.c")
OBJS := ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

libft:
		@make -C $(LIBFT)

%.o: %.c
	 @$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) \n"

$(NAME): $(OBJS)
		 @$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	  @make clean -C $(LIBFT)
	  @rm -rf $(OBJS)
	  @rm -rf $(LIBMLX)/build

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -rf $(NAME)
		@printf "\033[32m[FULLY CLEANED SUCCESSFULLY!]\033[0m"

re: clean all

.PHONY: all, libmlx, libft, clean, fclean, re


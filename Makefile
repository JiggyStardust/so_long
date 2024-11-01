# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:33:02 by sniemela          #+#    #+#              #
#    Updated: 2024/10/31 11:01:16 by sniemela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lglfw
CC = gcc


SOURCES =  so_long.c \
			map_handling/construct_map.c \
			map_handling/map_validity.c \
		
OBJS = $(SOURCES:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a 

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

INCLUDES = -I$(LIBFT_DIR) -I$(MLX42_DIR)/include

CYAN_BOLD := \e[1;96m
HIB_GREEN := \e[1;92m
GREEN_UNDER := \e[4;32m
ANSI_RESET := \033[0m

REQUIRED_PACKAGES = build-essential libx11-dev libglfw3 xorg-dev
CHECK_PACKAGES_CMD = dpkg -l | grep -E '$(subst $(space),|,$(REQUIRED_PACKAGES))'

all: check_packages $(NAME)

check_packages:
	@if ! $(CHECK_PACKAGES_CMD) > /dev/null; then \
		echo "$(CYAN_BOLD)Required packages not installed.$(ANSI_RESET)"; \
		echo "\n\nPlease install: $(REQUIRED_PACKAGES)"; \
		exit 1; \
	fi

$(NAME): $(OBJS) $(LIBFT) $(MLX42_LIB)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42_LIB) $(LDFLAGS) -o $(NAME)
	@echo "$(HIB_GREEN)$(NAME) has been successfully built!$(ANSI_RESET)"

$(OBJS): clone_MLX42 $(MLX42_LIB)

%.o: %.c
	@echo "Compiling included files..."
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	@echo "Building libft..."
	make -C $(LIBFT_DIR)

clone_MLX42:
	@if [ ! -d "$(MLX42_DIR)" ] || [ -z "$$(ls -A $(MLX42_DIR))" ]; then \
		echo "Cloning MLX42..." ; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	else \
		echo "$(CYAN_BOLD)MLX42 already exists, skipping clone.$(ANSI_RESET)"; \
	fi

$(MLX42_LIB): clone_MLX42
	@if [ ! -f "$(MLX42_LIB)" ]; then \
		echo "Building MLX42 library..."; \
		cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4; \
	else \
		echo "$(CYAN_BOLD)MLX42 library is up-to-date, skipping build.$(ANSI_RESET)"; \
	fi

$(MLX42_DIR):
	@mkdir -p $(MLX42_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	rm -rf $(MLX42_DIR)/build
	@echo "$(CYAN_BOLD)Cleaned up object files from so_long, libft, and MLX42$(ANSI_RESET)"

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_DIR)
	@echo "$(CYAN_BOLD)Removed $(NAME), libft.a and MLX42.$(ANSI_RESET)"

re: fclean all
	@echo "$(GREEN_UNDER)Rebuilt everything from scratch$(ANSI_RESET)"

.PHONY: all clean fclean re check_packages
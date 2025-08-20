# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 12:24:44 by vblanc            #+#    #+#              #
#    Updated: 2025/07/27 16:04:25 by ctheveno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP -O3
MLXFLAGS := -lXext -lX11 -lm -lpthread -L/opt/X11/lib -I/opt/X11/include

NAME := cub3D
NAME_BONUS := cub3D_bonus
RM := rm -rf

INC_DIR := -Iincludes -Iincludes/structs
SRC_DIR := srcs
INC_DIR_BONUS := -Iincludes -Iincludes/structs
SRC_DIR_BONUS := srcs
OBJ_DIR := objs

FILES := main.c \
		graphics/hooks.c \
		graphics/mlx_use.c \
		graphics/dda.c \
		graphics/new_image.c \
		graphics/minimap.c \
		graphics/loop_hook.c \
		utils/init_game.c \
		utils/free_array.c \
		utils/test_file_game.c \
		parsing/clean_parsing.c \
		parsing/error.c \
		parsing/floor_and_ceilling_rgb.c \
		parsing/parsing.c \
		parsing/map_grid.c \
		parsing/map_grid_start.c \
		parsing/texture_paths.c \
		parsing/valid_map.c \

FILES_BONUS := main_bonus.c

SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
DEPS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.d))

SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(FILES_BONUS))
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))
DEPS_BONUS := $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.d))

LIBFT_DIR := libft
PRINTF_FD_BUFFER_DIR := printf_fd_buffer
MLX_DIR := minilibx-linux

LIBFT := $(LIBFT_DIR)/libft.a
PRINTF_FD_BUFFER := $(PRINTF_FD_BUFFER_DIR)/ft_printf.a
MLX := $(MLX_DIR)/libmlx.a


all: libft mlx printf_fd_buffer $(NAME)

bonus: libft mlx printf_fd_buffer $(NAME_BONUS)

libft:
	@make -C libft

printf_fd_buffer:
	@make -C printf_fd_buffer

mlx:
	@make -C minilibx-linux;

$(NAME): $(OBJS)
	@make -C libft
	@make -C printf_fd_buffer;
	@make -C minilibx-linux;
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF_FD_BUFFER) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_FD_BUFFER_DIR) -I$(MLX_DIR) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(PRINTF_FD_BUFFER) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIR_BONUS) -I$(LIBFT_DIR) -I$(PRINTF_FD_BUFFER_DIR) -I$(MLX_DIR) -c $< -o $@
	$(CC) $(CFLAGS) $(INC_DIR_BONUS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@make -C libft clean
	@make -C printf_fd_buffer clean
	@make -C minilibx-linux clean
	$(RM) $(OBJ_DIR)

fclean:
	@make -C libft fclean
	@make -C printf_fd_buffer fclean
	@make -C minilibx-linux clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

norm:
	@norminette srcs includes

-include $(DEPS)

.PHONY: all bonus libft printf_fd_buffer mlx clean fclean re norm

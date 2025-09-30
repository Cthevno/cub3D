# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 12:24:44 by vblanc            #+#    #+#              #
#    Updated: 2025/09/22 15:09:55 by ctheveno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP -O3
MLXFLAGS := -lXext -lX11 -lm -lpthread

NAME := cub3D
NAME_BONUS := cub3D_bonus
RM := rm -rf

INC_DIR := -Iincludes -Iincludes/structs
INC_DIR_BONUS := -Iincludes -Iincludes/structs
SRC_DIR := srcs
SRC_DIR_BONUS := srcs_bonus
OBJ_DIR := objs
OBJ_DIR_BONUS := objs_bonus

FILES := main.c \
		graphics/hooks.c \
		graphics/mlx_use.c \
		graphics/new_image.c \
		graphics/loop_hook.c \
		graphics/ray_length.c \
		utils/init_game.c \
		utils/free_array.c \
		utils/mod_2pi.c \
		parsing/clean_parsing.c \
		parsing/error.c \
		parsing/floor_and_ceilling_rgb.c \
		parsing/parsing.c \
		parsing/get_map_data.c \
		parsing/extract_texture_paths.c \
		parsing/map_grid.c \
		parsing/map_grid_start.c \
		parsing/texture_paths.c \
		parsing/valid_map.c \
		parsing/valid_map_utils.c \
		parsing/flood_map.c \
		parsing/map_size.c \
		parsing/store_pixels.c \
		parsing/update_game_map_and_player.c \
		parsing/map_char_to_int.c \

FILES_BONUS := main.c \
		graphics/hooks.c \
		graphics/mlx_use.c \
		graphics/new_image.c \
		graphics/minimap.c \
		graphics/loop_hook.c \
		graphics/ray_length.c \
		utils/init_game.c \
		utils/free_array.c \
		utils/mod_2pi.c \
		parsing/clean_parsing_bonus.c \
		parsing/error_bonus.c \
		parsing/floor_and_ceilling_rgb_bonus.c \
		parsing/parsing_bonus.c \
		parsing/get_map_data_bonus.c \
		parsing/extract_texture_paths_bonus.c \
		parsing/map_grid_bonus.c \
		parsing/map_grid_start_bonus.c \
		parsing/texture_paths_bonus.c \
		parsing/map_size_bonus.c \
		parsing/store_pixels_bonus.c \
		parsing/update_game_map_and_player_bonus.c \
		parsing/update_game_textures_bonus.c \
		parsing/valid_map_bonus.c \
		parsing/valid_map_utils_bonus.c \
		parsing/map_char_to_int_bonus.c \
		parsing/flood_map_bonus.c \
		
SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
DEPS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.d))

SRCS_BONUS := $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS))
OBJS_BONUS := $(addprefix $(OBJ_DIR_BONUS)/, $(FILES_BONUS:.c=.o))
DEPS_BONUS := $(addprefix $(OBJ_DIR_BONUS)/, $(FILES_BONUS:.c=.d))

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

clean:
	@make -C libft clean
	@make -C printf_fd_buffer clean
	@make -C minilibx-linux clean
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJ_DIR_BONUS)

fclean:
	@make -C libft fclean
	@make -C printf_fd_buffer fclean
	@make -C minilibx-linux clean
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJ_DIR_BONUS)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

norm:
	@norminette srcs includes

-include $(DEPS)

.PHONY: all bonus libft printf_fd_buffer mlx clean fclean re norm

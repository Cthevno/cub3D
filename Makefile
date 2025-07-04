# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 12:24:44 by vblanc            #+#    #+#              #
#    Updated: 2025/06/17 14:11:40 by vblanc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP -o3
MLXFLAGS := -lXext -lX11 -lm -lpthread

NAME := cub3D
NAME_BONUS := cub3D_bonus
RM := rm -rf

INC_DIR := -Iincludes -Iincludes/structs
SRC_DIR := srcs
INC_DIR_BONUS := -Iincludes -Iincludes/structs
SRC_DIR_BONUS := srcs
OBJ_DIR := objs

FILES := main.c\
		\
		graphics/hooks.c\
		graphics/mlx_use.c\
		graphics/dda.c\
		graphics/new_image.c\
		graphics/minimap.c\
		graphics/loop_hook.c\
		\
		utils/init_game.c\
		utils/free_array.c\
		\
		\
		utils/test_file_game.c

FILES_BONUS := main_bonus.c

SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
DEPS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.d))

SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(FILES_BONUS))
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))
DEPS_BONUS := $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.d))

LIBFT_DIR := libft
MLX_DIR := minilibx-linux

LIBFT := $(LIBFT_DIR)/libft.a
MLX := $(MLX_DIR)/libmlx.a


all: libft mlx $(NAME)

bonus: libft mlx $(NAME_BONUS)

libft:
	@make -C libft

mlx:
	@make -C minilibx-linux;

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux;
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIR_BONUS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx-linux clean
	$(RM) $(OBJ_DIR)

fclean:
	@make -C libft fclean
	@make -C minilibx-linux clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

norm:
	@norminette srcs includes

-include $(DEPS)

.PHONY: all bonus libft mlx clean fclean re norm
CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP -o3 -g3

NAME := cub3D_parsing
RM := rm -rf

INC_DIR := -Iincludes -I. -Ignl -Iprintf_fd_buffer/header
SRC_DIR := .
OBJ_DIR := objs

FILES := $(shell find $(SRC_DIR) -type f -name "*.c")


SRCS := $(FILES)
OBJS := $(addprefix $(OBJ_DIR)/, $(FILES:$(SRC_DIR)/%.c=%.o))
DEPS := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.d))

LIBFT_DIR := ../libft

LIBFT := $(LIBFT_DIR)/libft.a

PRINTF_FD_DIR := ./printf_fd_buffer
PRINTF_FD := $(PRINTF_FD_DIR)/ft_printf.a

GNL_DIR := ./gnl
GNL_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_OBJS)))

all: libft ft_printf_fd $(NAME)

libft:
	@make -C ../libft
ft_printf_fd :
	@make -C printf_fd_buffer

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C ../libft
	@make -C printf_fd_buffer
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF_FD) -o $(NAME)

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJ_DIR)

fclean:
	@make -C libft fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

norm:
	@norminette srcs includes

-include $(DEPS)

.PHONY: all bonus libft clean fclean re norm

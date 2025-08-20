// #include "mlx_use.h"
#include "../../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
// #include "../../libft/libft.h"
// #include "../printf_fd_buffer/header/ft_printf.h"
#include <stdio.h>
#include "../../includes/parsing.h"
#include <limits.h>
#include <fcntl.h>

typedef struct s_pixel_storing
{
    void *mlx_ptr;
    void *img_ptr;
    char *img_data;
    int width;
    int height;
    int bits_per_pixel;
    int size_line;
    int endian;
}t_pixel_storing;

int copy_texture_array()
{

    return (1);
}

int store_pixels_from_xpm(char *img_path, int **texture_array)
{
    t_pixel_storing pixel_storing;
    pixel_storing.mlx_ptr = mlx_init();
    if (!pixel_storing.mlx_ptr)
        return (1);
    pixel_storing.img_ptr = mlx_xpm_file_to_image(pixel_storing.mlx_ptr, "../../assets/textures/colorstone.xpm", &pixel_storing.width, &pixel_storing.height);
    if (!pixel_storing.img_ptr)
    {
        printf("Erreur: impossible de charger l'image\n");
        return (1);
    }
    pixel_storing.img_data = mlx_get_data_addr(pixel_storing.img_ptr, &pixel_storing.bits_per_pixel, &pixel_storing.size_line, &pixel_storing.endian);
    //pass by parameter path to the image and where to store it in the other struct

    //copy in function by passing texture_array and pixel_storing_struct.
    **texture_array = malloc(pixel_storing.height * sizeof(int*));
    for (int i = 0; i < pixel_storing.height; i++)
    {
        texture_array[i] = malloc(pixel_storing.width * sizeof(int));
        for (int j = 0; j < pixel_storing.width; j++)
        {
            texture_array[i][j] = *(int*)(pixel_storing.img_data + (i * pixel_storing.size_line + j * (pixel_storing.bits_per_pixel / 8)));
        }
    }
    mlx_destroy_image(pixel_storing.mlx_ptr, pixel_storing.img_ptr);
    return (0);
}

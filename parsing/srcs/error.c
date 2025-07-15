#include <stdlib.h>
#include "../printf_fd_buffer/header/ft_printf.h"

int	ft_error(char *str)
{
	ft_printf_fd(2, "%s\n", str);
	return (0);
}

void	*ft_error_null(char *str)
{
	ft_printf_fd(2, "%s\n", str);
	return (NULL);
}


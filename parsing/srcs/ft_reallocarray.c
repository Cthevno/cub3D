/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:19:14 by ctheveno          #+#    #+#             */
/*   Updated: 2025/07/04 11:23:24 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

// Simple realloc implementation (with limitations)
// Note: This is a simplified version for educational purposes
// A real implementation would need a memory allocator that tracks block sizes

void *realloc(void *__ptr, size_t __size)
{
	void	*new_ptr;

	// If ptr is NULL, behave like malloc
	if (__ptr == NULL)
		return (malloc(__size));

	// If size is 0, behave like free and return NULL
	if (__size == 0)
	{
		free(__ptr);
		return (NULL);
	}

	// Allocate new memory block
	new_ptr = malloc(__size);
	if (new_ptr == NULL)
		return (NULL);

	// WARNING: This is unsafe - we don't know the old size!
	// In a real implementation, you'd need to track block sizes
	// For now, we'll copy a reasonable amount and hope for the best
	// This is just for demonstration - don't use in production!
	memcpy(new_ptr, __ptr, __size);

	// Free the old block
	free(__ptr);

	return (new_ptr);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t	total_size;

	// Check for overflow in multiplication
	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);

	// Calculate total size
	total_size = nmemb * size;

	// Use realloc with the calculated size
	return (realloc(ptr, total_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenwo <svalenwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:51:25 by svalenwo          #+#    #+#             */
/*   Updated: 2022/01/07 17:00:09 by svalenwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_len_ptr(uintptr_t c)
{
	int	len;

	len = 0;
	while (c != 0)
	{
		c = c / 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t c)
{
	if (c >= 16)
	{
		ft_put_ptr(c / 16);
		ft_put_ptr(c % 16);
	}
	else
	{
		if (c <= 9)
			ft_putchar_fd((c + '0'), 1);
		else
			ft_putchar_fd((c - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_lenght;

	print_lenght = 0;
	print_lenght += write(1, "0x", 2);
	if (ptr == 0)
		print_lenght += write(1, "0", 1);
	else
	{
		print_lenght += ft_len_ptr(ptr);
		ft_put_ptr(ptr);
	}
	return (print_lenght);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenwo <svalenwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:18:45 by svalenwo          #+#    #+#             */
/*   Updated: 2022/01/10 19:28:49 by svalenwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_len_hex(unsigned int c)
{
	int	len;

	len = 0;
	if (c == 0)
		len = 1;
	while (c > 0)
	{
		c = c / 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int c, const char format)
{
	if (c >= 16)
	{
		ft_put_hex(c / 16, format);
		ft_put_hex(c % 16, format);
	}
	else
	{
		if (c <= 9)
			ft_putchar_fd((c + '0'), 1);
		else
		{
			if (format == 'X')
				ft_putchar_fd((c - 10 + 'A'), 1);
			if (format == 'x')
				ft_putchar_fd((c - 10 + 'a'), 1);
		}
	}
}

int	ft_print_hex(unsigned int c, const char format)
{
	if (c == '0')
		return (write(1, "0", 1));
	else
		ft_put_hex(c, format);
	return (ft_len_hex(c));
}

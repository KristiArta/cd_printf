/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenwo <svalenwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:18:27 by svalenwo          #+#    #+#             */
/*   Updated: 2022/01/07 16:33:57 by svalenwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_format(va_list args, const char format);
int		ft_print_char(int c);
void	ft_putstr(char *str);
int		ft_print_percent(void);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_len_hex(unsigned int c);
void	ft_put_hex(unsigned int c, const char format);
int		ft_len_ptr(uintptr_t c);
void	ft_put_ptr(uintptr_t c);
int		ft_print_ptr(unsigned long long ptr);
int		ft_num_len(unsigned	int num);
char	*ft_unitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int c, const char format);

#endif
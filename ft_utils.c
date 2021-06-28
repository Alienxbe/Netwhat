/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:35:08 by mykman            #+#    #+#             */
/*   Updated: 2021/06/27 19:39:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_netwhat.h"

static int	ft_intsize(int n, int c)
{
	if (!n)
		return (c);
	if (n < 0)
		return (ft_intsize(n / -10, c + 2));
	return (ft_intsize(n / 10, c + 1));
}

void	ft_print_byte(unsigned char n)
{
	int	i;

	i = -1;
	while (++i < 8)
		ft_putchar_fd(((n >> (7 - i)) & 1) + 48, 1);
}

void	ft_putip(char *str, t_ip ip)
{
	int	i;
	int c;

	ft_putstr_fd(str, 1);

	// Print in base 10
	c = 3;
	i = -1;
	while (++i < 4)
	{
		ft_putnbr_fd(ip[i], 1);
		if (!ip[i])
			c++;
		c += ft_intsize(ip[i], 0);
		if (i != 3)
			ft_putchar_fd('.', 1);
	}

	// Print spaces
	c = 20 - c;
	while (c--)
		ft_putchar_fd(' ', 1);

	// Print in base 2
	i = -1;
	while (++i < 4)
	{
		ft_print_byte(ip[i]);
		if (i != 3)
			ft_putchar_fd('.', 1);
	}
	ft_putchar_fd('\n', 1);
}

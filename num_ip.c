/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_ip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:33:48 by mykman            #+#    #+#             */
/*   Updated: 2021/06/26 21:12:48 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>

typedef unsigned char	*t_ip;

static void	ft_putip(char *str, t_ip ip)
{
	int	i;

	ft_putstr_fd(str, 1);
	i = -1;
	while (++i < 4)
	{
		ft_putnbr_fd(ip[i], 1);
		if (i != 3)
			ft_putchar_fd('.', 1);
	}
	ft_putchar_fd('\n', 1);
}

/*static void	ft_print_byte(unsigned char n)
{
	int	i;

	i = -1;
	while (++i < 8)
		ft_putchar_fd(((n >> (7 - i)) & 1) + 48, 1);
	ft_putchar_fd('\n', 1);
}*/

static t_ip	atoip(const char *str)
{
	char	**tab;
	t_ip	ip;
	int		i;

	if (!(tab = ft_split(str, '.')))
		return (NULL);
	ip = malloc(sizeof(t_ip) * 4);
	i = -1;
	while (tab[++i])
	{
		if (ip)
			ip[i] = (unsigned char)ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	return (ip);
}

static t_ip	get_network_addr(t_ip ip, int cidr)
{
	t_ip	new_ip;
	int		i;

	if (!(new_ip = (t_ip)malloc(sizeof(t_ip) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (i < cidr / 8)
			new_ip[i] = ip[i];
		else if (i > cidr / 8)
			new_ip[i] = 0;
		else
			new_ip[i] = ip[i] & (~((1 << (8 - (cidr - i * 8))) - 1));
	}
	return (new_ip);
}

static t_ip	get_broadcast_addr(t_ip ip, int cidr)
{
	t_ip	new_ip;
	int		i;

	if (!(new_ip = (t_ip)malloc(sizeof(t_ip) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (i < cidr / 8)
			new_ip[i] = ip[i];
		else if (i > cidr / 8)
			new_ip[i] = 255;
		else
			new_ip[i] = ip[i] | ((1 << (8 - (cidr - i * 8))) - 1);
	}
	return (new_ip);
}

static t_ip	get_subnet_mask(int cidr)
{
	int		i;
	t_ip	ip;

	if (!(ip = (t_ip)malloc(sizeof(t_ip) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (i < cidr / 8)
			ip[i] = 255;
		else if (i > cidr / 8)
			ip[i] = 0;
		else
			ip[i] = ~((1 << (8 - (cidr - i * 8))) - 1);
	}
	return (ip);
}

int main(int argc, char const *argv[]) {
	int		cidr;
	t_ip	ip;
	t_ip	network_addr;
	t_ip	broadcast_addr;
	t_ip	subnet_mask;

	// Catching errors
	if (argc != 3)
	{
		printf("BAD ARGUMENT COUNT\n");
		return (1);
	}

	// String into t_ip
	cidr = ft_atoi(argv[2]);
	ip = atoip(argv[1]);
	network_addr = get_network_addr(ip, cidr);
	broadcast_addr = get_broadcast_addr(ip, cidr);
	subnet_mask = get_subnet_mask(cidr);


	// Print section
	ft_putip("IP            : ", ip);
	ft_putip("Network  IP   : ", network_addr);
	ft_putip("Broadcast IP  : ", broadcast_addr);
	ft_putip("Subnet mask   : ", subnet_mask);

	// Free section
	free(ip);
	free(network_addr);
	free(broadcast_addr);
	free(subnet_mask);
	return (0);
}

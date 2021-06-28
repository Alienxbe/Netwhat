/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:39:04 by mykman            #+#    #+#             */
/*   Updated: 2021/06/27 19:12:28 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_netwhat.h"

t_ip	get_ip(const char *str)
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

t_ip	get_network_addr(t_ip ip, t_cidr cidr)
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

t_ip	get_broadcast_addr(t_ip ip, t_cidr cidr)
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

t_ip	get_subnet_mask(t_cidr cidr)
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

t_ip	get_wildcard(t_cidr cidr)
{
	int		i;
	t_ip	ip;

	if (!(ip = (t_ip)malloc(sizeof(t_ip) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (i < cidr / 8)
			ip[i] = 0;
		else if (i > cidr / 8)
			ip[i] = 255;
		else
			ip[i] = (1 << (8 - (cidr - i * 8))) - 1;
	}
	return (ip);
}

t_cidr	get_cidr(t_ip subnet)
{
	t_cidr	cidr;
	int		i;
	int		j;

	cidr = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 8)
		{
			if (!((subnet[i] >> (7 - j)) & 1))
				return (cidr);
			cidr++;
		}
	}
	return (cidr);
}

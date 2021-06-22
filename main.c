/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:33:48 by mykman            #+#    #+#             */
/*   Updated: 2021/06/22 18:49:38 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>

static char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	size_t	size;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)ft_calloc(sizeof(*ptr), size);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	if (n >= 1)
		free(s1);
	if (n >= 2)
		free(s2);
	return (ptr);
}

char		*get_network_addr(char **ip, int cidr)
{
	char	*str;
	int		byte;
	int		i;

	i = -1;
	str = ft_strdup("");
	while (ip[++i])
	{
		byte = ft_atoi(ip[i]);
		if (cidr / 8 == i)
		{
			byte >>= 8 - (cidr - i * 8);
			byte <<= 8 - (cidr - i * 8);
		}
		if (cidr / 8 < i)
			str = ft_strjoin_free(str, "0", 1);
		else
			str = ft_strjoin_free(str, ft_itoa(byte), 2);
		if (i < 3)
			str = ft_strjoin_free(str, ".", 1);
	}
	if (i != 4)
	{
		free(str);
		str = ft_strdup("Bad IP address");
	}
	return (str);
}

char 		*get_broadcast_addr(char **ip, int cidr)
{
	char	*str;
	int		byte;
	int		i;

	i = -1;
	str = ft_strdup("");
	while (ip[++i])
	{
		byte = ft_atoi(ip[i]);
		if (cidr / 8 == i)
			byte |= (1 << (8 - (cidr - i * 8))) - 1;
		if (cidr / 8 < i)
			str = ft_strjoin_free(str, "255", 1);
		else
			str = ft_strjoin_free(str, ft_itoa(byte), 2);
		if (i < 3)
			str = ft_strjoin_free(str, ".", 1);
	}
	if (i != 4)
	{
		free(str);
		str = ft_strdup("Bad IP address");
	}
	return (str);
}

int main(int argc, char const *argv[]) {
	char **tab;
	int i;

	int cidr;
	const char *ip;
	char *network_addr;
	char *broadcast_addr;

	if (argc != 3)
	{
		printf("BAD ARGUMENT COUNT\n");
		return (1);
	}

	// Variable assignement
	tab = ft_split(argv[1], '.');
	cidr = ft_atoi(argv[2]);
	ip = argv[1];
	network_addr = get_network_addr(tab, cidr);
	broadcast_addr = get_broadcast_addr(tab, cidr);

	//printf
	printf("\n\nIp adress: %23s\n", ip);
	printf("Network address: %17s\n", network_addr);
	printf("Broadcast address: %15s\n\n", broadcast_addr);

	// Free section
	free(network_addr);
	free(broadcast_addr);
	// Free tab
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}

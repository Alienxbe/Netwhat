/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_ip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:33:48 by mykman            #+#    #+#             */
/*   Updated: 2021/06/22 19:17:12 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>

typedef unsigned char	*t_ip;

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

static char	*build_ip(t_ip ip)
{
	char	*str;
	int		i;

	str = ft_strdup("");
	i = -1;
	while (++i < 4)
	{
		str = ft_strjoin_free(str, ft_itoa(ip[i]), 2);
		if (i != 3)
			str = ft_strjoin_free(str, ".", 1);
	}
	return (str);
}

/*char		*get_network_addr(char **ip, int cidr)
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
}*/

t_ip	get_broadcast_addr(t_ip ip, int cidr)
{
	t_ip new_ip;

	new_ip = ft_calloc
	return (ip);
}

int main(int argc, char const *argv[]) {
	char	**tab;
	int		i;

	t_ip	ip;

	// Catching errors
	if (argc != 3)
	{
		printf("BAD ARGUMENT COUNT\n");
		return (1);
	}

	// String into t_ip
	tab = ft_split(argv[1], '.');
	ip = malloc(sizeof(t_ip) * 4);
	i = -1;
	while (tab[++i])
	{
		ip[i] = (unsigned char)ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);

	printf("%s\n", build_ip(get_broadcast_addr(ip, 15)));
	printf("%s\n", build_ip(ip));
	return (0);
}

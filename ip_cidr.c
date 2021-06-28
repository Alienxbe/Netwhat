/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_cidr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:33:48 by mykman            #+#    #+#             */
/*   Updated: 2021/06/27 20:23:11 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_netwhat.h"

int main(int argc, char const **argv)
{
	t_cidr	cidr;
	t_ip	ip;
	t_ip	network_addr;
	t_ip	broadcast_addr;
	t_ip	subnet_mask;
	t_ip	wildcard;

	// Catching errors
	if (argc != 3)
	{
		ft_putstr_fd("BAD ARGUMENT COUNT\n", 1);
		return (1);
	}

	// Variable assignement
	cidr = ft_atoi(argv[2]);
	ip = get_ip(argv[1]);
	network_addr = get_network_addr(ip, cidr);
	broadcast_addr = get_broadcast_addr(ip, cidr);
	subnet_mask = get_subnet_mask(cidr);
	wildcard = get_wildcard(cidr);


	// Print section
	ft_putip("IP            : ", ip);
	ft_putip("Subnet mask   : ", subnet_mask);
	ft_putip("Wildcard      : ", wildcard);
	ft_putchar_fd('\n', 1);
	ft_putip("Network  IP   : ", network_addr);
	ft_putip("Broadcast IP  : ", broadcast_addr);
	printf("Hosts : %020d\n", 32 - cidr);

	// Free section
	free(ip);
	free(network_addr);
	free(broadcast_addr);
	free(subnet_mask);
	free(wildcard);
	return (0);
}

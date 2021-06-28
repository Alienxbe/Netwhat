/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subnet_cidr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:43:35 by mykman            #+#    #+#             */
/*   Updated: 2021/06/27 18:50:07 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_netwhat.h"

int main(int argc, char const **argv)
{
	t_ip	ip;

	// Catching errors
	if (argc != 2)
	{
		ft_putstr_fd("BAD ARGUMENT COUNT\n", 1);
		return (1);
	}

	// Variable assignement
	ip = get_ip(argv[2]);

	// Free section
	free(ip);
	return (0);
}

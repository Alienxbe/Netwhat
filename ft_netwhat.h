/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_netwhat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:27:09 by mykman            #+#    #+#             */
/*   Updated: 2021/06/27 19:39:02 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_NETWHAT_H
# define  FT_NETWHAT_H

# include "libft/includes/libft.h"
# include "stdio.h"

typedef unsigned char	*t_ip;
typedef unsigned char	t_cidr;

t_ip	get_ip(const char *str);
t_ip	get_network_addr(t_ip ip, t_cidr cidr);
t_ip	get_broadcast_addr(t_ip ip, t_cidr cidr);
t_ip	get_subnet_mask(t_cidr cidr);
t_ip	get_wildcard(t_cidr cidr);

t_cidr	get_cidr(t_ip subnet);

void	ft_print_byte(unsigned char n);
void	ft_putip(char *str, t_ip ip);

#endif

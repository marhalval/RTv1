/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:56:45 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/22 19:56:47 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishex(char c)
{
	if ((c >= 65 && c <= 70) || (c >= 97 && c <= 102) || ft_isdigit(c))
		return (1);
	return (0);
}

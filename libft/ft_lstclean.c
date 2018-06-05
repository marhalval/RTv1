/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:29:38 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/10 18:30:18 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclean(t_list *list)
{
	t_list *next;

	while (list)
	{
		next = list->next;
		ft_memdel(&list->content);
		ft_memdel((void **)&list);
		list = next;
	}
}

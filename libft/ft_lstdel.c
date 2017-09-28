/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 21:56:41 by cweather          #+#    #+#             */
/*   Updated: 2017/07/04 23:04:11 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nlst;

	lst = *alst;
	while (lst)
	{
		nlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nlst;
	}
	*alst = NULL;
}

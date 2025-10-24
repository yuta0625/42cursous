/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:14:46 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 20:06:47 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *list)
{
	free(list);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst ->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list	*s1 = ft_lstnew("hello");
// 	t_list	*s2 = ft_lstnew("world");

// 	s1 ->next = s2;
// 	ft_lstdelone(s2, del);
// 	printf("%s", (char *)s1 ->content);
// }

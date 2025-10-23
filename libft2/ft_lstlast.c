/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:51:38 by yohya             #+#    #+#             */
/*   Updated: 2025/10/23 17:04:21 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst ->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list *a = ft_lstnew("hello");
// 	t_list *b = ft_lstnew("world");
// 	t_list *c = ft_lstnew("42tokyo");

// 	a ->next = b;
// 	b ->next = c;
// 	t_list *result = ft_lstlast(b);
// 	printf("%s", (char *)result ->next);
// }

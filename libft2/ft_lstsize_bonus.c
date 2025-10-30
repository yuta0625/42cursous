/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:28:43 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 13:42:20 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst ->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list *a = ft_lstnew("hello");
// 	t_list *b = ft_lstnew("soccer");
// 	t_list *c = ft_lstnew("world");
// 	a ->next = b;
// 	b ->next = c;
// 	int result = ft_lstsize(a);
// 	printf("%d", result);
// 	free(a);
// 	free(b);
// 	free(c);
// 	return (0);
// }

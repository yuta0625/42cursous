/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:14:57 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 13:06:02 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ret;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ret = ft_lstlast(*lst);
	ret ->next = new;
}

// int	main(void)
// {
// 	t_list *l = ft_lstnew("baseball");
// 	t_list *lst = ft_lstnew("hello");
// 	t_list *new = ft_lstnew("world");
// 	t_list *s = ft_lstnew("soccer");
// 	lst ->next = s;
// 	s ->next = l;
// 	ft_lstadd_back(&s, new);
// 	printf("%s %s %s\n", (char *)lst->content, (char *)lst->next->content);
// }

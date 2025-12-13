/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:49:51 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:55:14 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new ->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	t_list *lst = ft_lstnew("apple");
// 	t_list *new = ft_lstnew("science");
// 	ft_lstadd_front(&lst, new);

//     printf("%s %s\n", (char *)lst->content, (char *)lst->next->content);
// 	free(lst);
// 	free(new);
// 	return (0);
// }

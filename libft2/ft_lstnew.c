/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:19:29 by yohya             #+#    #+#             */
/*   Updated: 2025/10/23 17:01:44 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node ->content = content;
	node ->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	char *word = ft_strdup("hello");
// 	if (!word)
// 		return (1);
// 	t_list	*temp = ft_lstnew(word);
// 	printf("%s", (char *)temp ->content);
// 	free(word);
// 	free(temp);
// 	return (0);
// }

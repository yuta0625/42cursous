/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:57:44 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 14:29:59 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst ->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst ->next;
	}
	return (new_list);
}

// static void	del(void *list)
// {
// 	free(list);
// }

// void	*to_upper(void *s)
// {
// 	char	*str;
// 	char	*ret;
// 	size_t	i;
// 	if (!s)
// 		return (NULL);
// 	str = (char *)s;
// 	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
// 	if (!ret)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			ret[i] = str[i] - 32;
// 		else
// 			ret[i] = str[i];
// 		i++;
// 	}
// 	ret[i] = '\0';
// 	return ((void *)ret);
// }

// int	main(void)
// {
// 	char	*s = ft_strdup("hello");
// 	t_list	*s1 = ft_lstnew(s);
// 	t_list	*temp = ft_lstmap(s1, to_upper, del);
// 	while(temp)
// 	{
// 		printf("%s", (char *)temp ->content);
// 		temp = temp ->next;
// 	}
// 	ft_lstclear(&s1, del);
// 	ft_lstclear(&temp, del);
// 	return (0);
// }

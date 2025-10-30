/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:48:20 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:56:27 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst ->content);
		lst = lst ->next;
	}
}

// void	to_upper(void *s1)
// {
// 	char	*word;

// 	word = (char *)s1;
// 	while (*word)
// 	{
// 		if (*word >= 'a' && *word <= 'z')
// 			*word -= 32;
// 		word++;
// 	}
// }

// int	main(void)
// {
// 	char *str = ft_strdup("hello");
// 	t_list	*s1 = ft_lstnew(str);
// 	ft_lstiter(s1, to_upper);
// 	printf("%s", (char *)s1 ->content);
// 	free(s1 ->content);
// 	free(s1);
// 	return (0);
// }

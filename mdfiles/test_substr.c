#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);

	slen = ft_strlen(s);

	// startが文字列長を超えていたら空文字を返す
	if (start >= slen)
	{
		ret = (char *)malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}

	// 残りの長さがlenより短ければ短い方を採用
	if (slen - start < len)
		len = slen - start;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);

	i = 0;
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	main(void)
{
	char *s = "abede";
	unsigned int start = 1;
	size_t len = 8;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}

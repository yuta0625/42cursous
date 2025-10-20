strnstr関数の使用
strnstr()関数は、文字列 big 内でヌル終端文字列 little の最初の出現位置を検索します。検索対象となる文字数は len 文字以下です。ヌル終端文字 『\0』 の後に続く文字は検索対象外となります
littleが空の文字列の場合、bigがかえされる。
little が big のどこにも存在しない場合、NULL が返される。それ以外の場合は、little が最初に現れる位置の最初の文字へのポインタが返される。

char *strnstr(const char *big, const char *little, size_t len);
size_t lenの長さだけ分のbigを見ていくという形になる
だからwhile文ははlenの長さ文だけ回してそのなかでlittleと一致する部分までbigの中身をすすめ、
その中で,下記の条件を満たす部分だけをreturn出力させる
while (j < len)
{
	k = 0;
	while (big[k] == little[k] && little[k])
		k++;
	if (k == str_count(little))
		return ((char *)big);
	j++;
}
その条件に満たない場合にはreturn (null)をする。
＜strchrやstrrchrで戻り値をキャストして返す理由にかんして＞
char	*ft_strrchr(const char *s, int c)
	return ((char *)s);
このようにする理由としてはsはconst charの型であるが、この*ft_strrchrの型はchar型であるからキャストをして返している。

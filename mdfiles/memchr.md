memchr関数の使用
void *memchr(const void *buf, int ch, size_t n);

第一引数は検索対象のメモリのポインタ
第二引数は検索文字
第三引数は検索バイト数
引数cを、論理和（&演算子）を使ってunsigned charと同じ0～255の範囲にする。
->引数cを&演算子で0xff(これ自体は16進数である)（10進数で255）と論理積を取ることで、unsigned char型と同じ0〜255の範囲に収めることができる。
戻り値
memchr() および memrchr() 関数は、一致するバイトへのポインタを返す。指定されたメモリ領域に文字が存在しない場合は NULL を返す。

memcmp()関数の使用について
memcmp() 関数は、メモリ領域 s1 と s2 の最初の n バイト（それぞれ unsigned char として解釈される）を比較します。

戻り値
memcmp() 関数は、s1 の最初の n バイトが s2 の最初の n バイトよりも小さい、等しい、または大きい場合に、それぞれ 0 未満、0、0 以上の整数を返します。
戻り値が 0 以外の場合、その符号は s1 の最初の n バイトが s2 の最初の n バイトよりも小さい、等しい、または大きい場合にそれぞれ決定されます。
バイトがそれぞれ、s2の最初のnバイトよりも小さい、等しい、または大きいと判断された場合に、それぞれ対応する整数を返します。

0以外の戻り値の場合、その符号は、s1とs2で異なる最初のバイトペア（unsigned charとして解釈される）の差の符号によって決定されます。

nが0の場合、戻り値は0です。

include <string.h>
int memcmp(const void *buf1, const void *buf2,size_t n);

第一引数、第二引数は比較対象メモリのポインタ
第三引数は比較サイズ

をそれぞれ指定します。
比較はunsigned charとして行われます。
戻り値は以下のようになります。

正の値　：　buf1 ＞ buf2
０　 　 ：　buf1 ＝ buf2
負の値　：　buf1 ＜ buf2
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	return (NULL);
}
例を通したイメージ

もし n = 5 なら、5バイトを1つずつ確認する必要があります。

1回目 → 比較後 n は 4

2回目 → 比較後 n は 3

3回目 → 比較後 n は 2

4回目 → 比較後 n は 1

5回目 → 比較後 n は 0 → ループ終了

つまり 5回きっちり回る

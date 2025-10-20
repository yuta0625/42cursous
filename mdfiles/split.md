ft_split関数の使用
char **ft_split(const char *s, char c)
<パラメータ>
s: 分割対象の文字列
c: 区切り文字列
<戻り値>
分割の結果生成された新しい文字列の配列
割当に失敗した場合、NULLを返す
<外部関数>
malloc. free

!in_wordという書き方について
「in_wordが 0(偽)かどうかを意味する」
!in_wordは「in_wordが0のときに真になる」
in_wordは今単語の中なのかどうかを表すフラグ
in_word = 0というのは真ではなく偽である。
だから次の条件に入る。
if ((s[i] != c) && !in_word)
ここでin_word = 1というように置き換えられるため、in_wordは真の値となる。
そのようになると、上記のif文の条件には合致せず、countは1しか進まない状況となる。
そのあとに、下記のelseifの条件に当てはまったら
else if (s[i] == c)
in_wordが0となりcount++を進めることができcount=2でreturnが行われる。


free_all関数に関して
二次元配列のmallocを行った場合に途中で失敗した場合に遡ってmalloc領域をfreeしていいかなければいけない
static void	free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr);
}
その場に、上記のようなfree処理となる

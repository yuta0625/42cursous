ft_strtrim関数の使用
char *ft_strtrim(const char *s1, const char *set)
<パラメータ>
s1: トリミング対象の文字列
set: 消去対象の文字列を含む文字列。
<戻り値>
トリミングされた文字列
割り当てに失敗した場合、NULLを返します。
<説明>
メモリを割り当て
setの先頭と末尾から文字列が消去されたs1のコピーを返す

substr・strchr・strlenが使えそう

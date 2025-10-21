ft_substr関数の使用
char *ft_substr(const char *s, unsigned int start, size_t len)
<パラメータ>
s:元の文字列。これをもとに部分文字列を生成する元の文字列。
start:  's'内の部分文字列の開始インデックス
len :  部分文字列の最大長。
 <戻り値>
 ・部分文字列
 ・割り当てに失敗した場合は、null文字を返す
 <説明>
 文字列's'の部分文字列を返す
 部分文字列はインデックス'start'から始まり、最大長で'len'です。
<考え>
ここでのmalloc領域の確保は（部分文字列分＋1）分の確保


ft_putendl_fd関数の使用
void ft_putendl_fd(char *s, int fd)
<パラメータ>
s : 出力する文字列
fd : 書き込み先のファイルディスクリプタ

<説明>
指定されたファイルに文字列's'を出力する
記述子に改行を続けて出力をする

ft_putstr_fd(char *s, int fd)とやることは同じだが
ft_putendl_fd(char *s, int fd)は最後に改行を出力する違いがある。

ft_putnbr_fd関数の使用
void ft_putnbr_fd(int n, int fd);

n : 出力する整数
fd : 書き込む先のファイル記述子

指定されたファイル記述子に整数'n'を出力する

bzero関数の使用
bzero - 値 0 のバイトで埋める
＜書式＞
 #include <strings.h>

       void bzero(void *s, size_t n);
bzero()  関数は バイト列 s から始まる領域の先頭 n バイトを 数値ゼロ (値が '\0' のバイト) で埋める。



ft_strmapi関数の使用に関して
char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
この関数宣言は、関数ポインタを引数にとる関数の典型例
ft_strmapiは「文字列sの各文字に関数fを適応し、新しい文字列を返す関数」である。
(*f)(unsigned int, char)
fは関数ポインタ、fが指す関数は次のような形の関数である
char 関数名(unsigned int, char)
使い方に関して
char to_uppercase(unsigned int i, char c)
{
    (void)i; // 使わないときは無視
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}
これをft_strmapiに渡すと
char *result = ft_strmapi("hello", to_uppercase);
結果はHELLOになる。

ft_striteri関数の使用
void	ft_striteri(char *s, void (*f)(unsigned int, char*))

ft_striteriとft_strmapiと似ているが「新しい文字列を返さずに、元の文字列を直接書き換える」タイプの関数である。
「文字列sの各文字にたいして、インデックス番号とその文字のアドレスを渡してfを実行する関数」

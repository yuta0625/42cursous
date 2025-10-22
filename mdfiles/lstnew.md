lstnew関数の使用に関して
ft_lstnewのmallocでどれだけの領域を確保すべきか、そしてintなどの値をどのように格納する
ft_lstnew関数は「新しいノード」をつくるので、確保するべき領域は「構造体１個分」である。
t_list *node = (t_list *)malloc(sizeof(t_list));

typedef struct s_list
{
	void  		  *content;
	struct s_list *next;
}                 t_list;

t_list *node;
node = (t_list *)malloc(sizeof(t_list));

node.content = content;
node.next = NULL
と
node ->content = content;
node ->next = NULL;
の違い

t_list *node;
と宣言しているため、nodeは構造体t_listそのものではなく、構造体へのポインタである。

| 記号   | 対象                 | 意味                  |
| `.`  | 構造体 **そのもの** に使う   | メンバに直接アクセス          |
| `->` | 構造体 **へのポインタ** に使う | ポインタが指す構造体のメンバにアクセス |

node ->content = contentはなにをしているのか
構造体nodeの中のcontentフィールドに、変数content(つまりnumのアドレス)を代入している。
・contentの中身は「ポインタ」なので、値を直接いれるわけではなく、アドレスをいれている。
・その結果、node ->contentは「データがある場所」を指すようになる
| 式                          | 意味
| `node->content = content;` | `content`の**アドレス（ポインタ）**を入れる |
| `*(int *)node->content`    | そのアドレスが指す**実際の値（例：42）**を取り出す |
「アドレスをつなぐ」とき → node->content = content;
「値を使う」とき　ｰ>　*(int *)node ->content

#include "push_swap.h"

//swap関数
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//クイックソートアルゴリズム
void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j) //iとjがすれ違うまで続ける
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			ft_swap(&arr[i++], &arr[j--]);
	}
	//ここまでくるとループが終わった時点で、配列はなんとなく「左側はピボットより小さいゾーン」
	//「右側はピボットより大きいゾーン」に分かれる。
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

//二分探索アルゴリズム
static	int	get_rank_by_binary_search(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	assign_index_by_sort(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;
	int		pos;

	if (!a || a->size <= 0)
		return ;
	arr = stack_to_array(a);
	quick_sort(arr, 0, a->size - 1);
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		//arrの配列の中の数字とcurのvalueと一緒になった場合にそのindexを返す
		//その判断をget_rank_by_binary_serch()が役割を担って行っている
		pos = get_rank_by_binary_search(arr, a->size, cur->value);
		if (pos < 0)
			error_and_exit();
		cur->index = pos;
		//a->topから回して全体をまわす
		cur = cur->next;
		i++;
	}
	free(arr);
}

1.コピー
arr = stack_to_array(a)
 ・スタックaの中身を、新しい配列arrにコピーしている。
 ・状態：スタックと配列は同じ並び順である。

2.整列(Sort)
quick_sort(arr, 0, a->size -1)
・配列arrだけをクイックソートで小さい順(昇順)に並び替える
・この時点でスタックaの並び順は変わっていない
・目的：二分探索(バイナリサーチ)は「整列されたデータ」に対してしか使えないため、ここで配列をソートして置く必要がある

3.順位づけ(Assign index/Search)

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

s->top = NULLの意味:
 ・スタックが「空っぽ」であることを示す目印である。
 ・もし初期化を忘れてtopにデタラメなアドレスが入っていると、あとの処理でif(s->top == NULL)という判定
 が誤動作したり、存在しないメモリにアクセスしてセグメンテーションフォルトでクラッシュするから
s->size = 0;
 ・現在の要素数を正確に管理するためのリセットである。

//双方向循環リストの作成
t_node	*node_new(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = 0;

	//通常のリストならNULLを入れるが、今回は双方向循環リストである
	//「世界に自分一人しかいないときに、自分の右隣は自分、左隣も自分」という状態にしておく。
	//こうすることで、ノードが一つでも増えたときに「つなぎ変える処理」を統一でき、例外処理を減らすことができる
	n->prev = n;
	n->next = n;
	return (n);
}

「Top(先頭)」を変えずに、「Toｐの直前(=Bottom)」に新しいノードを挟み込む処理を書いている
void	stack_push_bottom(t_stack *s, t_node *n)
{
	t_node	*top;
	t_node	*bottom;

	if (s->size == 0)
	{
		s->top = n;
		n->next = n;
		n->prev = n;
	}
	//すでにlistがあるとき
	else
	{
		top = s->top;
		bottom = top->prev;
		n->next = top;
		n->prev = bottom;
		bottom->next = n;
		top->prev = n;
	}
	s->size++;
}

双方向循環リスト

ノード構造体
イメージ：これはデータの一つを入れる箱(ノード)である。電車の車両のようなものである
typedef struct s_node
{
	int				value; //中身のデータ
	int				index; //整理番号　(ランク)
	struct s_node	*prev; //前の車両と繋ぐ手
	struct s_node	*next; //次の車両と繋ぐ手
}	t_node;

indexの決め方に関して
自分のインデックスは、自分より小さい数の個数と等しいという法則をつかうことができる

スタック構造体
t_stack: データの「管理者」
これはつながった車両(t_node)全体を管理する司令塔のような構造体である
typedef struct s_stack
{
	t_node	*top; //スタックの先頭
	int		size; //要素数
}	t_stack;

同じ重複でてきたらアウトの判断用
void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void set_index(t_stack *stack)
{
	t_node *current;
	t_node *compare;
	int		i;
	int		j;
	int 	count;

	if (!stack || !stack->top || stack->size <= 0)
		return ;
	current = stack->top;
	i = 0;
	while(i < stack->size)
	{
		count = 0;
		compare = stack->top;
		j= 0;
		while(j < stack->size)
		{
			if (compare->value < current->value)
				count++;
			else if (compare != current && compare->value == current->value)
				error_end_exit();
			compare = compare->next;
			j++;
		}
		current->index = count;
		current = current->next;
		i++;
	}
}

文字列を数字に変換する
int to_number(char *str)
{
	long	sign = 1;
	long	result = 0;

	while(*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while(*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (0);
		str++;
	}
	if (*str != '\0)
		return (0);
	return (result * sign)
}


t_node	*stack_pop_top(t_stack *s)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*next;

	if (s->size == 0)
		return (NULL);
	top = s->top;
	if (s->size == 1)
		s->top = NULL;
	else
	{
		bottom = top->prev;
		next = top->next;
		bottom->next = next;
		next->prev = bottom;
		s->top = next;
	}
	s->size--;
	//独立したノードにする
	//変に残ったスタックにアクセスを行ってしまう可能性がある。
	top->next = top;
	top->prev = top;
	return (top);
}

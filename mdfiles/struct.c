
#include <stdio.h>
#include <stdlib.h>

/* 1) ノード定義 */
typedef struct s_list {
    void            *content;   // データ本体（今回はint*を入れる）
    struct s_list   *next;      // 次ノードへのポインタ
} t_list;

/* 2) ヘルパー：intをヒープに複製してint*を返す */
static int *int_dup(int value)
{
    int *p = (int *)malloc(sizeof(int));
    if (!p) return NULL;
    *p = value;
    return p;
}

/* 3) ノード作成（contentを保持してnext=NULLで返す） */
t_list *lst_new(void *content)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node) return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

/* 4) 先頭に追加：*lstの前にnewを差し込む */
void lst_add_front(t_list **lst, t_list *new_node) {
    if (!lst || !new_node) return;
    new_node->next = *lst;
    *lst = new_node;
}

/* 5) 末尾に追加：最後のnextにnewをつなぐ */
void lst_add_back(t_list **lst, t_list *new_node) {
    if (!lst || !new_node) return;
    if (*lst == NULL) {
        *lst = new_node;
        return;
    }
    t_list *cur = *lst;
    while (cur->next) cur = cur->next;
    cur->next = new_node;
}

/* 6) 要素数カウント（学習用） */
int lst_size(t_list *lst) {
    int n = 0;
    while (lst) { n++; lst = lst->next; }
    return n;
}

/* 7) 全解放：content解放関数delを使って中身→ノードの順にfree */
void lst_clear(t_list **lst, void (*del)(void *)) {
    if (!lst) return;
    t_list *cur = *lst;
    while (cur) {
        t_list *next = cur->next;
        if (del) del(cur->content);  // 先に中身をfree
        free(cur);                   // その後ノード本体をfree
        cur = next;
    }
    *lst = NULL;
}

/* ---- デモ用に使うdel関数（int* を解放） ---- */
static void del_int(void *p) {
    free(p);
}

/* 8) 走査して表示（今回はint*前提でキャストして表示） */
void lst_print_ints(t_list *lst) {
    while (lst) {
        int *pi = (int *)lst->content;  // 実際に入れているのはint*
        printf("%d ", *pi);
        lst = lst->next;
    }
    printf("\n");
}

/* 9) サンプル：作成→末尾追加→走査→クリア */
int main(void) {
    t_list *head = NULL;

    // 値をヒープに確保し、各ノードに格納
    t_list *n1 = lst_new(int_dup(10));
    t_list *n2 = lst_new(int_dup(20));
    t_list *n3 = lst_new(int_dup(30));
    if (!n1 || !n2 || !n3) {
        fprintf(stderr, "malloc failed\n");
        // 途中で失敗した場合の後始末（雑に例示）
        if (n1) { del_int(n1->content); free(n1); }
        if (n2) { del_int(n2->content); free(n2); }
        if (n3) { del_int(n3->content); free(n3); }
        return 1;
    }

    // 末尾に追加して 10 -> 20 -> 30
    lst_add_back(&head, n1);
    lst_add_back(&head, n2);
    lst_add_back(&head, n3);

    printf("size = %d\n", lst_size(head));
    lst_print_ints(head);  // 出力: 10 20 30

    // 先頭に追加して 5 -> 10 -> 20 -> 30
    t_list *n0 = lst_new(int_dup(5));
    lst_add_front(&head, n0);
    printf("size = %d\n", lst_size(head));
    lst_print_ints(head);  // 出力: 5 10 20 30

    // 最後に全解放（中身→ノード）
    lst_clear(&head, del_int);
    return 0;
}

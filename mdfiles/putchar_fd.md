ft_putchar_fd関数の使用
void ft_putchar_fd(char c, int fd)
<パラメータ>
c: 出力する文字
fd: 書き込みファイル記述子
<外部関数>
write
<説明>
指定されたファイル記述子に文字'c'を出力する
このfd(ファイルディスクプリンタ)は「どこに出力をするか」を指定する番号です
void ft_putchar_fd(char c, int fd);
この関数は文字cを、ファイルディスクリプタfdが指す出力先に書き込む
ファイルディスクリプタ(fd)とは？
Unix系システムでは、「すべての入出力はファイルとして扱う」という仕組みがある。
| 出力先             | ファイルディスクリプタ番号 | 説明                                      |
| 標準入力（keyboard）  | `0`           | キーボード入力（`read()` で使う）                   |
| 標準出力（screen）    | `1`           | 通常の出力（`printf`, `write`）                |
| 標準エラー出力（screen） | `2`           | エラー出力（`perror`, `fprintf(stderr, ...)`） |
ft_putchar_fdの中身
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
ft_putchar_fd('A', 1);  // 画面に「A」と表示される
ft_putchar_fd('E', 2);  // エラー出力に「E」と出る
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putchar_fd('H', fd);
	ft_putchar_fd('i', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}
ｰ>この場合は"output.txt"にHiが書き込まれる
| 項目    | 内容                               |
| `fd`  | 出力先を示す番号（file descriptor）        |
| よく使う値 | `1`: 標準出力、`2`: エラー出力、`0`: 標準入力   |
| 実際の動作 | `write(fd, &c, 1);` で1文字出力       |
| 応用例   | ファイルを `open()` して取得した `fd` にも使える |

int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
open()は、ファイルを開いて、そのファイルを操作するための「ファイルディスクリプタ」を返す関数
使い方の構文
int open(const char *pathname, int flags, mode_t mode);
・pathname: 開きたいファイル名(ex: output.txt)
・flags: どう開くか（読み込み専用/書き込み専用/追記モード）
・mode: 新しく作る場合の「パーミッション（アクセス権）」設定


④ O_TRUNC
→ ファイルの中身を空にする（truncate）
すでに "output.txt" が存在していた場合、
中身を全部消してから開きます。

結論：fdには「数字」が入る
open()が返すのは「ファイルディスクリプタ」という整数番号(int型)です。
この番号はos（カーネル）が管理しているファイルテーブルの参照番号になる。
int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
fdに３が入るケースがほとんどである。
なぜ「３」なのか
UNIX/Linuxでは、プロセスが起動すると自動的に3つのファイルディスクリプタがすでに開いている
| ファイルディスクリプタ番号 | 名前                 | 役割               |
| **0**         | 標準入力 (`stdin`)     | キーボード入力など        |
| **1**         | 標準出力 (`stdout`)    | 画面出力 (`printf`)  |
| **2**         | 標準エラー出力 (`stderr`) | エラー表示 (`perror`) |
これらはすでに使われているので、open()は「次に空いている番号」＝3を返すのが一般的です。
プロセス開始直後：

fd=0 → 標準入力（キーボード）
fd=1 → 標準出力（画面）
fd=2 → 標準エラー（画面）

open("output.txt", ...) 実行後：

fd=3 → "output.txt"（ファイル）
つまりこの時点で
int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
を実行すると
１．OS が "output.txt" というファイルを開く
２．カーネル内の「ファイルテーブル」にその情報を登録する
３． プログラムに「そのファイルを指す番号（例；３）」を返す
結果的に
fd == 3;
ft_putchar_fd('H', fd);
をよぶと、実際には内部でwrite(fd, &c, 1)が動いている
ファイルディスクリプタ３番（＝output.txt）に'H'を１バイト書き込む
| 項目       | 内容                        |
| -------- | ------------------------- |
| `fd` の中身 | OSが返す整数番号（通常は3以上）         |
| 意味       | “どのファイル／出力先を使うか” を表す識別子   |
| 0        | 標準入力（キーボード）               |
| 1        | 標準出力（画面）                  |
| 2        | 標準エラー出力（画面）               |
| 3以降      | `open()` などで開いたファイルやパイプなど |

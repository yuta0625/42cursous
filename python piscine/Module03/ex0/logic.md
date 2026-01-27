import sys
sys.argvとは？
コマンドライン引数のリスト(list)
python3 ft_command_quest.py hello world 42

sys.argv[0] → "ft_command_quest.py"（プログラム名）
sys.argv[1] → "hello"
sys.argv[2] → "world"
sys.argv[3] → "42"

import sys
print(sys.argv)
# ['ft_command_quest.py', 'hello', 'world', '42']

全部 文字列 (str) として入ってくる
42 も "42" なので、数として使いたいなら int() などで変換が必要（Exercise1でやる）

python3 a.py
# len(sys.argv) = 1
python3 a.py hello world
# len(sys.argv) = 3

len()は「数える(countする)ための関数」であるが、どのように数えるかを確認する
len()
len(x)はxの要素数を返す
・リストなら「中に入っている要素の個数」
・文字列なら「文字数」
・辞書なら「キーの数」
・タプルなら「要素の数」
・セットなら「要素の数(重複なし)」

len([10, 20, 30])   # 3
len("abc")          # 3
len({"a": 1, "b": 2})  # 2  (キーが2つ)
len({1, 1, 2})      # 2  (セットは重複が消える)


forを使わなくwhileを使う方がいいかもしれない
arg_count = len(sys.argv)
for i in range(1, arg_count + 1)
    score = score + [int(sys.argv[i])]

sys.argvの有効なindexは0~len(sys.argv)-1になる
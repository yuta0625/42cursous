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

for文でrange()なしで回すには、スライスしたargvを回すのが一番きれいである。

forが回せるものの種類
list（リスト）
tuple（タプル）
str（文字列：1文字ずつ出る）
dict（辞書：デフォでキーが出る）
set（集合：順序は安定しない）
range（今回は使わない）
ファイルオブジェクト（1行ずつ）
sys.argv みたいなリスト などなど

tupleをつかって3D座標系を構築する。
->tupleはあとから変更を行うことができないリストである

「同じ型のものを集める場合にはリスト、違う型のもの同士を集める場合にはタプル」

sys sys.argvを使って行う
python3 ft_coordinate_system.py "3,4,0"
sys.argv[1] が "3,4,0"
split(",") して int() に変換して (3, 4, 0) を作る

複数座標もやるなら：
python3 ft_coordinate_system.py "0,0,0" "10,20,5"
2点間距離を計算できる

split()の結果はlist[str]だから、それをtuple[int, int, int]に変換すればいい

pythonで使いたくない(関数内で利用しない)引数がある場合、主にアンダースコア(_)を使う習慣や、(*args, **kwargs)を利用して無視することが行われる

def my_function(a, b, _):
    # a と b は使うが、3番目の引数は無視する
    return a + b

print(my_function(10, 20, "使いたくない値"))  # 結果: 30

set()
集合を作るやつ。
a = set([1, 2, 2, 3])   # {1, 2, 3}  重複が消える
b = set("abca")        # {'a','b','c'}  文字がユニーク化
empty = set()          # 空集合（{} は dict になるので注意）

union() ->和集合
「どっちかに入っているやつ全部」
a = {1, 2, 3}
b = {3, 4}
print(a.union(b))   # {1,2,3,4}

intersection()　->積集合
「両方に入っているやつだけ」
a = {1, 2, 3}
b = {3, 4}
print(a.intersection(b))  # {3}

difference() -> 差集合
a = {1, 2, 3}
b = {3, 4}
print(a.difference(b))  # {1,2}
print(b.difference(a))  # {4}

set型オブジェクトを扱うことができると、集合の計算を簡単にできる
集合の計算とは
・和集合
・積集合
・差集合
・排他的論理和集合

dict()->辞書をつくる
d = dict()
d2 = dict(a=1, b=2)   # {"a": 1, "b": 2}

keys() -> キー一覧(ビューを返す)
d = {"a": 1, "b": 2}
d.keys()  # dict_keys(['a', 'b'])

values() -> 値一覧(ビュー)を返す
d.values()  # dict_values([1, 2])

items() -> (キー, 値) のペア一覧（ビュー）を返す。ループで超使う。
for k, v in d.items():
    print(k, v)

get() -> キーを取り出す。キーが無い時にエラーにせず None やデフォルト値を返せる。
d = {"a": 1}
d.get("a")        # 1
d.get("x")        # None
d.get("x", 0)     # 0  (デフォルト指定)

user = {"name": "Alice", "age": 20}
# 1. キーが存在する場合
print(user.get("name"))  # 出力: Alice
# 2. キーが存在しない場合（デフォルト値なし -> None）
print(user.get("address"))  # 出力: None
# 3. キーが存在しない場合（デフォルト値を指定）
print(user.get("address", "Unknown"))  # 出力: Unknown

update() -> 辞書をまとめて追加・上書きする。
d = {"a": 1, "b": 2}
d.update({"b": 20, "c": 3})
# {"a": 1, "b": 20, "c": 3}

exercise5-ft_data_stream
iterをつかって必要なぶぶんだけかえす

yeild
関数を「値を１個ずつ返すジェネレータにする」


Excercise5に関して
<アウトラインの作成>
Processing 1000 game eventsに関して
インベント生成
例：毎回"Event k: Player {name} (level {lv} {action})みたいな文字列をyieldする

1000件ぶんストリーミング処理
for _ in range(1000):
    event = next(stream)のように1件ずつ取り出して処理

取り出した文字列から条件判定してカウント
3つの指標ならこう：
・Hight-level players(10+)
 ->イベント文字列からlevelの数字を取り出して
・Treasure events
->"found treasure"が含まれてたらterasure += 1
・Level-up
->"leveled up"が含まれていたらlevel_up +=1
最後にカウンタを出力すると、出力結果はさっきのような形になる。

「1000件イベントを作るというより、イベントをその場で生成して流す」
そこでのPlayersの持ち方は次の条件を満たすのが扱いやすい
・固定サイズで、毎回参照できる
・イベント生成に必要な最小情報だけ持つ
・解析(high-level/treasure/level-up)に直結する情報をもつ

プレイヤー一覧はタプルのタプルの方がいいかもしれない
list[tuple[str, int]]
プレイヤーを途中で増やす/消す/並び替える可能性があるならlistが自然である
tupel[tuple[str, int], ....]
プレイヤー集合を固定のマスターデータとして持つなら、タプルの方がいい

現状のplayersの持ち方
players: tuple[tuple[str, int], ...]
players = {
    ("alice", 5),
    ("bob", 12),
    ("charlie", 8),
}

Actions
actions: tuple[str, ...]
actions = {
    "killed monster",
    "found treasure",
    "leveled up",
}

・tupleを使う理由(listでもいいけど)
    ・変更しない前提のマスターデータ
    ・誤って.append()できない
    ・「固定データを参照しながらstreamを生成している」

・generataor側での使い方(設計イメージ)
    ・iをインクリメントしながら
    ・player[i % len(players)]でプレイヤーを選択
    ・actions[i % len(actions)]で行動を選択
    ・yeild(name, level, action)

ジェネレータ(yield)でストリームを作って、必要な分だけ取り出して処理する

次の処理を考える
現状の3つの数値に関して、1000回イベントを取り出して(nextで消費して)その都度条件に合えばカウントを増やすという、ストリーミング集計である

この時の考え方として「iterにアクセスする」というより、「itearator(ジェネレター)からnext()で1件取り出す」の考え方がいい

1000件処理の流れ（イメージ）
stream = iter(generators()) で 1本のストリーム（iterator）を作る
for i in range(1000): を回す
毎回 event = next(stream) で 次のイベント1件を取得
そのイベントの中身を見て、カウンタを更新する

Memory usage: Constant(streming)とは？
→処理するイベント数が増えても、メモリ使用量が増えない
今回の処理でのポイント
・events = []に1000件ためていない
・全イベントをlist/dictに保存していない
・1件取り出して→使って→捨てる
つまりメモリ上には常に：
・カウンタ数個(high_level, tresure, level_up)
・今処理中の1イベントだけ

この処理でどのくらいの処理時間がかかったのかを計測する
import time
time.time
ツールアーカイブの解凍と準備
#　アーカイブの解凍
wget .gzのファイルのリンク
tar -xzf data-generator-tools.tar.gz

使っていい標準ライブラリ:  sys
使っていい組み込み関数: open() read() write() close() print() input()

"r": readをする　fileがなかったらErrorハンドリングをする必要がある
"w": 新規で書き込むのでFileNotFoundErrorになることがないのでErrorハンドリングはいらない

Exercise2は「入力はstdin, 通常出力はstdout, 警告はstderr」を分けて出せるか

sysはPythonの標準ライブライで、「実行環境(標準入出力・引数など)にアクセスする入口」です
Exercise2では特に標準ストリームを扱うために使います

stdin / stdout / stderrの役割
sys.stdin(入力)
・キーボード入力が流れてくるところ(Input stream)
・今回はinput()をつかえばOK

sys.stdout(通常出力)
・通常の結果・ログを出す場所
・print()のデフォルトはstdout

sys.stderr(警告・エラー出力)
・重要通知・警告ログ用
・今回は [ALERT] ... を stderr に出すのが要求

input()の使い方
input(prompt)は
・prompt(案内文)をstdoutに出して
・ユーザーの入力をstdinから受け取って
・入力文字列を返す

stdout    通常の出力　　　　計算結果・通常ログ
stderr    エラー・警告　　　エラーメッセージ・警告

見た目は同じターミナルに出る
でも、内部的には別の通路である

パソコンには「出力のパイプ」が2本ある
        ┌── stdout（通常用）
Python ─┤
        └── stderr（警告用）


standardではstdoutに標準出力が行われている
file=sys.stderrを指定するとerror出力に出力をさせるようになる

stderrに出るかの確認のコマンド
python3 ft_stream_management.py 2> alert.txt
cat alert.txt

with openの内部挙動に関して
with open('sample.txt', 'r') as f:
が実行されるとき、Pythonの内部では以下の順序で処理が進む

1.open()の呼び出し: ファイルオブジェクト(コンテキストマネージャ)が生成される
２.__enter__() の実行: 生成されたオブジェクトの __enter__ メソッドが呼ばれます。このメソッドの戻り値（ファイルオブジェクト自身）が as f の f に代入されます。
3.ブロック内の処理: f.read() などの処理が実行されます。
4.__exit__() の実行: 処理が終わる（または途中でエラーが起きる）と、自動的に __exit__ メソッドが呼ばれます。ここで f.close() が実行され、メモリやシステムリソースが解放されます。


なぜ try...finally よりも優れているのか？

ディフェンスで「普通の f.close() と何が違うの？」と聞かれた際の回答ポイントです。

    書き忘れ防止: close() を手動で書く必要がないため、リソースリーク（ファイルが開きっぱなしになる現象）を防げます。

    例外への強さ: もし f.read() の最中にプログラムがクラッシュしても、Pythonは必ず __exit__ を通ることを保証しています。

    ディフェンス用フレーズ:
    「with 構文は、リソースの確保と解放をカプセル化する**RAII（Resource Acquisition Is Initialization）**に近い考え方です。エラー発生時でも確実に __exit__ が呼ばれるため、堅牢なプログラムになります。」


class MyTimer:
    def __enter__(self):
        print("開始！") # 前処理
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        print("終了！") # 後処理（必ず呼ばれる）

with MyTimer():
    print("メイン処理中...")

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

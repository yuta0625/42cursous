ツールアーカイブの解凍と準備
#　アーカイブの解凍
wget .gzのファイルのリンク
tar -xzf data-generator-tools.tar.gz

使っていい標準ライブラリ:  sys
使っていい組み込み関数: open() read() write() close() print() input()

"r": readをする　fileがなかったらErrorハンドリングをする必要がある
"w": 新規で書き込むのでFileNotFoundErrorになることがないのでErrorハンドリングはいらない

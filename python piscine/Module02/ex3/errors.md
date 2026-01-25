raiseを使う(継承クラスでerrorをまとめる)
今回の課題でなにをさせたいのか
・GardenErrorを自作例外の最上位(親)にする
・これより「ガーデン関連で起きた問題」は全部GardenError系として扱える
たとえば現実世界のアプリだと「このモジュールのエラーだけまとめて捕まえたい」ってよくあるのでそのときに活用することができる

今回は
・GardenError(親)
　・PlantError（植物系）
　・WaterError（水系）

自作のerrorを作成する
まず判断を行うための閾値を設定する方がいい

class GardenError(Exception):
このようにかける理由としては、「このクラスは”例外(エラー)として、raise/exceptで扱える型ですよと伝えるため
pythonでraiseできるのはBaseException(通常はException)を継承したものだけ
raiseで自分の自作のerrorハンドリングを行うことができる

こんかいは親クラスのGardenErrorをしっかりと確認をしてエラーハンドリングを行う
PlantErrorもWaterErrorもGardenErrorの子クラスなのでそれを意識してエラーハンドリングをおこなう

finallyでのerrorハンドリング
finallyは「エラーが起きても起きなくても、必ず最後に実行したい後片付けを書く場所」
tryの中で途中で例外が起きると、普通はその行で処理がとまってexceptに飛ぶ
その結果
・ファイルを開いたまま閉じ忘れる
・ロックを取りっぱなし
・一時ファイルを消し忘れる
・”処理中フラグ”を戻し忘れる

finallyに書いた処理は
・例外が起きても
・例外が起きなくても
・途中でreturnしても
基本的に必ず実行されるから、安全に片付けができる

try:
	#失敗するかもしれない処理
except SomeError:
	#失敗したときの処理
finally:
	#必ずやる後片付け

example:ファイルを確実にcloseする
f = None
try:
	f = open("data.txt", "r")
	data = f.read()
except FileNotFoundError:
	print("ファイルがありません")
finally:
	if f is not None:
		f.close()
		print("ファイルを閉じました”)

finallyを使わずに書くと
with open("data.txt") as f:
	data = f.read()

plant_list = ["Rose", "flower", "Tomate". "hann"]
print("Testing normal watering...")
for platn in plant_list:
	try:
		print("Opening watering system)
		print("Watering {plant}")
	except ValueError:
		print("Error: Cannot water None - invalid plant!")
	finally:
		print("Closing watering system (cleanup)")

try/exceptは「既に起きた例外を捕まえる」もの

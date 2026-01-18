クラス構成の大枠
 ・GardenManager
  ・複数のgardenを管理する「司令塔」
  ・植物の追加・成長・レポート作成などを担当する
 　　・GardenStatas(ネストされた補助クラス)ー＞こいつはgardenmanagerの中につくる
	　　このGardenStatasに持たせるべき処理内容
         ・入力：その garden の plants（Plant/FloweringPlant/PrizeFlower の list）
         出力：len(plants)
　　　　　→ Example: Plants added: 3


・Plant系の継承ツリー
　・Plant -> FloweringPlant -> PrizeFlower(ex5よりさらに継承を深くする)

必要となる知識
・インスタンスメソッド
・クラスメソッド
・スタティックメソッド

exampleの流れ
1.植物をgardenに追加する
2.garden植物を成長させる
3.統計を集計
plants added
total growth
plant types

4.レポート表示
5.クラスメソッド・staticメソッドのデモ

class GardenManager:
   class GardenStats:

class Plant:
class FloweringPlant(Plant)
class PrizeFlower(FloweringPlant)

def ft_gardennalytics()

if __name__ == '__main__':
   ft_gardennalytics()

Garden Managerに追加機能をもたせるのがいいかも

・instance method(self): すでに存在しているmgrの中身を操作する(add/grow/report)
・class method(cls): 「GardenManagerという型として、どういう初期構成のmanagerをつくるか」を担当する
ー＞つまり、別の作り方のコンストラクタみたいな役割

GardenManagerに「初期状態をつくって返す」メソッドを追加する
create_garden_network()
・AliceとBobのgardenを最初から用意する
・それぞれに植物をいれておく（スコア計算やTotal garden managedにつながる）
・最後にGardenManagerのインスタンスを返す

@classmethodのclsに関して
varoable = cls()は「自分のクラスのインスタンス(分身)を作る」という意味である
クラスからインスタンスを作るときは p = Plant() のようにクラス名を直接書きますよね？
しかし、@classmethod の中では、あえてクラス名を書かずに cls() と書くことで、「どのクラスから呼ばれたかによって、作るものを自動で変える」 という柔軟な動きをさせています。
具体例：なぜ Plant() と書かずに cls() と書くのか？
もし FloweringPlant (親) に「文字列からデータを作る便利機能」を作ったとします

クラス名を固定にしてしまうとよくないこと
class FloweringPlant:
    @classmethod
    def from_string(cls, text):
        # ここで親クラス名を書いてしまうと...
        return FloweringPlant("name", 10, "red", True)

class PrizeFlower(FloweringPlant):
    pass

# PrizeFlowerから呼び出しても、FloweringPlant（親）が生まれてしまう！
flower = PrizeFlower.from_string("...")
print(type(flower)) # -> <class 'FloweringPlant'> (これじゃ困る！)

クラス（clsを使う）
class FloweringPlant:
    @classmethod
    def from_string(cls, text):
        # cls は「呼び出したクラス自身」になる
        # PrizeFlower.from_string() なら、cls は PrizeFlower
        return cls("name", 10, "red", True)

class PrizeFlower(FloweringPlant):
    pass

# PrizeFlowerから呼び出せば、ちゃんとPrizeFlowerが生まれる！
flower = PrizeFlower.from_string("...")
print(type(flower)) # -> <class 'PrizeFlower'> (正解！)

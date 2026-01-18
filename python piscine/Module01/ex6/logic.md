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

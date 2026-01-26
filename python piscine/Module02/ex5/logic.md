この課題の設計に関して
最低限GardenManagerが内部に持つべき状態
・植物の一覧(+水量・日照などの状態)

Exercise5の要件は、「GardenManagerがadd/water/chek」を持ち、カスタム例外を使い、finallyを使い、raiseして落ちないようにすること

dictの実装に関して
self.plants: dict[str, dict[str, int]] = {}
# plants[name] = {"water": 5, "sun": 8}

必要な関数
・植物を追加するメソッド
def add_plat(self, name: str,water: int,sun: int) -> None:
    if not name:
        raise PlantError("Plant name cannot be empty!")
    self.plants[name] = {"water": water, "sun": sun}
これで、self.plantsの中身は以下のようになる
{
    "tomato": {"water": 5, "sun": 8}
}
・植物に水を与えるメソッド
ここでfinllyを使う
→finallyを使う理由としては、「失敗時」だけじゃなく「成功時」も含めて必ずやる保証
でもfinallyは
・例外が起きても　・起きなくても　・途中でreturnしても ・breakしても必ず最後に走る
・植物の健康状態を確認するメソッド

Adding plants to garden...
Added tomato successfully
Added lettuce successfully
Error adding plant: Plant name cannot be empty!
この出力を期待する
def test_garden_management():
    gm = GardenManager()
    print("=== Garden Management System ===\n")
    print("Adding plants to garden...")
    plants_to_add = [
        ("tomato", 5, 8),
        ("lettuce", 6, 7),
        ("", 3, 6), 
    ]
    for name, water, sun in plants_to_add:
        try:
            gm.add_plant(name, water, sun)
            pirnt(f"Added {name} successfully")
        except PlantError as e:
            print(f"Error adding plant: {e}")

今回のError処理に関して
・GardenError(基本)
・PlantError(植物系)
・WaterError(水やり系)

for name, info in self.plants.items()
items()のメソッドに関して
pythonの items() とは、辞書（dict型）に使うメソッドで、その辞書の全てのキーと値のペアを取得するものです。返されるのは (key, value) のタプルの集合のようなビューオブジェクト です。
dict.items() は 辞書の全てのキーと値の組 (key, value) を返します。
各ペアは タプル (key, value) として扱われます。
結果は dict_items というビューオブジェクト で、元の辞書が変更されると内容も反映されます。

d = {'apple': 1, 'banana': 2, 'cherry': 3}
for key, value in d.items():
    print(key, value)
出力
apple 1
banana 2
cherry 3

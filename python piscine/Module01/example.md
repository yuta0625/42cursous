カプセル化のメリットに関して(どのようにつかうのか)
__heightはそとからplant.__height=999みたいな形で触ることはできない
__heightはname mangling(名前の変換)されて、外側からその名前でアクセスできなくなる

取得：get_height()
変更：set_height()
のルートを通す設計になる -> ここで検証などを行うことができる

pythonはガチガチに守る言語ではない
rose._SecurePlant__height = 999
この書き方を行うと書き換えることができる。
この__は「絶対に触れない」ではなく、合図などである

カプセル化の本当のメリット
「簡単に改変できない」もあるけど、もっと大事なのはこれの変更ルールを1箇所に閉じ込められる
set_height() に “負の値禁止” を入れておけば、どこから更新しても安全に内部の実装を変えても外側のコードを壊しにくい。例えば内部表現を cm から mm に変えても、get_height() がcmで返すようにすれば外側はそのまま

_name(シングル)：ただのお願いである
class A:
	def __init__(self):
		self._x = 10
->外から普通にアクセスをできる
a = A()
print(a._x)   # 10
a._x = 99     # 変更できる


__name(ダブル)：名前が変わる
class A:
	def __init__(self):
		self.__x = 10

a = A()
a.__x #AttributeError
__x → _A__x

だからこれなら変えることが可能である
print(a._A__x)  # 10
a._A__x = 99

classをいつ作るのか
”同じ種類のものをたくさん扱う”
”データ＋操作(ふるまい)をセットで管理したい”
”ルール(制約)を一箇所に閉じ込めたい”
この３つが揃ったらclassの出番である

A. 同じ構造のデータが複数ある
辞書のリストでもできるけど、これだと、更新処理が散らかりやすい
plants = [
  {"name": "Rose", "height": 25, "age": 30},
  {"name": "Tulip", "height": 18, "age": 12},
]

B.　”操作”が増えそう
plants[i]["height"] += 2
plants[i]["age"] += 1

しかも「負の値禁止」みたいなルールが各所に散る
C. ルールを守らせたい（カプセル化）
heightはマイナス禁止、ageは減らせない
こういう制約を更新の入口(メソッド)に閉じ込めるのがclassの強み

class -> インスタンスの流れ
classは「設計図（型）」
class Plant:
->これは型をつくっているだけで、中の植物は存在しない

インスタンスは「設計図から作った実物」
rose = Plant("Rose", 25, 30)
tulip = Plant("Tulip", 18, 12)

継承ってなにが嬉しいのか
継承は一言でいうと、共通部分を親クラスにまとめて、差分だけ小クラスで追加/変更する

植物はみんな「名前・身長・年齢」を持つ
でも、植物によって「成長の仕方」が違うかもしれない
・Rose: 毎日 +1cm
・Bamboo：毎日 +5cm
・Cactus：成長遅い、乾燥耐性…など
こういうときに継承がハマる

多態性(ポリモーフィズム)：継承の一番おいしいところ
class Plant:
......
class Bamboo(Plant)
......
class Flower(Bamboo)
......
Plants = [
	Plant("Generic", 10, 1)
	Bamboo("Bamboo", 50, 10)
	Flower("Tulip", 18, 12, "yellow")
]

for _ in range(6):
	for p in plants

ネスト関数(関数の中で関数の宣言)
->関数の中に関数を定義する
使う場面
１．その関数内だけでつかう小さな処理を隠したい
２．外の変数を持ち回りたい
３．デコレータを作る

その関数の中だけで使う”表示補助”
def simulate_week(plants):
    def header(day: int) -> None:
        print(f"=== Day {day} ===")

    header(1)
    for p in plants:
        print(p.info())
こうするとheaderが外にもれない

クロージャ(ネストの強み)
内側の関数が外側の変数を覚えて使える
def make_growth_logger(prefix: str):
    def log(msg: str) -> None:
        print(f"[{prefix}] {msg}")
    return log

logger = make_growth_logger("SECURITY")
logger("Negative height rejected")
これ、ネスト関数だから prefix を覚えたまま logger が動く。

・ネスト関数：関数のスコープ(見える範囲)をその外側の関数の中だけに閉じ込める
・@staticmethod: クラスの中に置くけど、selfもclsも使わないただの関数にする(=クラスの名前空間に置く)
なので、ネスト関数に@staticmehotdをつけることは基本できない。意味がない。
@staticmethodは
「クラスの中で定義した関数(メソッド)」に対するデコレータだから
「そのクラスに“関係はある”けど、self（個体）や cls（クラス自体）に依存しない処理を、クラスの名前空間にまとめて置くため」

@staticmethod
・Plant.is_valid_height()みたいに所属がはっきりする
・selfを受け取らない＝インスタンス不要

@classmethod
・clsを受取、継承先でも正しく働かせたいときにつよい
・生成補助はこっちが本命になりがち

インスタンスメソッド
・self.heightみたいに個体の状態を触るなら必須である

classmethodは「インスタンスを固定する」ためじゃなくて「クラス(=型)に紐付いた処理をしたい」、特に生成(factory)や設定の適用を継承先でも正しく再利用できるようにしたいときに使う

ポイントはclsがくること。clsは「呼び出したクラス自身」だから、親でも子でも同じメソッドを使い回せる

クラスの中にクラス(ネストしたクラス)を作るのは
「このクラスは外側クラスの部品/内部専用の型だよ」ってスコープと意味づけを強くするため

関連する型を名前空間としてまとめる
そとにconfigやstateを散らかしたくないとき

今回のex6の大枠の概要に関してのまとめ
全体構造
・植物(Plant)という型を作り
・それを継承して花が咲く植物/賞品付きの植物をつくり
・さらにGrademManagerが持ち主ごとの庭(garden)をdictで管理して
・成長させたり、レポートやスコアを計算する

class GardenManager:
    def __init__(self) -> None:
        self.garden: dict[str, list[Plant]] = {}
        self.total_growth: dict[str, int] = {}

self.garden: dict[str, list[Plant]] = {}
・key: owner(例："Alice")
・value: その人の庭にある植物リスト(list[Plant])


self.total_growth: dict[str, int] = {}
・key: owner
・value: そのownerが成長させた合計cm

classmethod: クラスから”初期セット”を作る
def create_garden_network(cls) -> "GardenManager":
    mgr = cls()
    mgr.add_plat()
    ....
    return mgr

classmethodは何のため
@classmethodは「クラスに紐づくメソッド」で第一引数がcls
ここでやっているのは初期状態が入ったGardenManagerを作る工場
・mgr = cls()
->もし将来GardenManagerを継承したクラスProGardenManagerをつくっても、ProGardenManger.create_garden_network()がProGardenManagerのインスタンスを返す

add_plant: dictを安全に使うための基本
def add_plant(self, owner: str, plant: Plant) -> None:
    if owner not in self.gardens:
        self.gardens[owner] = []
    self.gardens[owner].appned(plant)

まだ owner が登録されてなければ空リストを作る
そこに append

def grow_all(self, owner: str, amount: int) -> None:
    if owner not in self.gardens:
        print(f"{owner} is helping all plants grow...")
        return
    if owner not in self.total_growth:
        self.total_growth[owner] = 0
    print(f"{owner} is helping all plants grow...")
    for plant in self.gardens.get(owner, []):
        plant.grow(amount)
        self.total_growth[owner] += amount
dict.get(key, default) は keyがなくても安全に値を取れる
plant.grow() は 多態性（ポリモーフィズム）で効いてる
Plant / FloweringPlant / PrizeFlower を混ぜても同じ grow() が呼べる

GardenStats: クラス内クラス + staticmethod
class GardenManager:
    class GardenStats:
        @staticmethod
        def height_validation(height: int) -> bool:
            return height >= 0

GardenStatsはGardenMangerの付属ユーティリティって位置づけ
外にGardenStatsを独立でおいても動くけど、「庭の統計はGardenMangerに属する」という意味が読みやすくなる

@staticmethodは何のため？
@staticmethodはselfもclsもいらない関数を「クラスの中に整理して置く」ため。

・height_vvalidationはインスタンス状態を使わない
・count_typesもplantsリストを引数に貰えば十分
・format_plant_lineもplantを引数に貰えば十分
・garden_scoresも同じ



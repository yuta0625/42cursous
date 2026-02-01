今回のようなときに、なぜclassをつかうのかについてまとめて置く
classは設計図。
Plantに必要な情報を(name/height/day)がばらけない
だからPlantクラスをつくって、各植物を__init__で初期化してオブジェクト化してからlistにいれると、データ構造が統一されて再利用・拡張がいしやすい

なぜinitを使うのか
・__init__ は「新しいPlantを作るときに、最低限必要な情報を受け取って、状態をセットする初期化処理」
・これがあるとPlant("Rose", 25, 30)の時点で、「必ずname/height/dayを持つ個体」が作れる
ー＞つまりデータのかけや型ブレを防ぐ役目もある

また、["Rose", 25, 30]
このようにすると参照するときにplant[0]がnameなのか毎回覚える必要がある　

class=設計図
instance=その設計図からつくった実物/実体
Plantクラスは、植物の情報(name/height/day)をひとまとめにして管理するための設計図
インスタンス(=その設計図から作った実体)をつくるときに、必要なデータを__init__で受け取って属性を初期化する。
さらにgrow_countのように、後で成長量を計算したい変数も初期値を決めて持たせておく
そしてgrow()やage()はそのインスタンスの状態を更新するメソッドで状態の変化を計算して反映する


カプセル化に関して
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

rose.__height = 20 -> これだと変わらない
print(rose.get_info())
rose._SecurePlant__height = 20　-> これだと変更を行うことができる
print(rose.get_info())

カプセル化により、属性への直接アクセスを避け、getter/setterを唯一の入口にすることで、値の取得・更新方法を統一できる。
その結果、validationやログ出力などの更新ルールを１か所に集約でき、不正な状態を防ぎ、変更・保守・デバックがしやすい設計になる

今回の課題で行っていること
継承+メソッドのオーバーライド(override)+super()の使い方

１）親クラス
・Plantに共通属性(name, height, age)をもたせる
・子クラス(Flower/Tree/Vegetable)は追加情報だけを持つ
ー＞重複を減らす、共通管理しやすい

2）super().__init__()の意味
・親の初期化をえ呼ぶことで、子クラス側でname/height/ageを毎回書かなくてよくなる
・初期化のルールがPlantに集約され、将来変更にも強い
3）オーバーライド(get_infoの上書き)
・同じget_info()という名前でも、クラスごとに表示内容がかわる
->多態性（polymorphism） の入り口になる

現状のコード設計でもポリモーフィズム（多態性）は成立している
今の現状のget_info()でも
base_info()をつくってそれに加える形でもいい

今回実装を行わせたいことをまとめる
このコードは継承と多態性、さらにクラス内クラス+staticmethodでユーティリティ機能を分離して、「複数の植物をownerごとの庭で管理し、成長・集計・レポート・スコア算出を行う」

普通のメソッド(instance method)との違い
・instance mthod:
->個体(インスタンス)の状態を使う
例：mgr.grow_all()がmgr.gardensを更新するからselfが必要
・@staticmthod: def m(...) (self/clsなし)
->クラスやインスタンスの状態に依存しない純粋な処理をまとめるため
・@classmthod：def m(cls, ...)
->クラスそのものに関係する処理をする
特に別のコンストラクタとして使うのが王道である

なぜ今回の課題で@staticmthodをつかったのか
reason1: selfが不要(インスタンス状態に依存しない)
GardenStateの関数は全部、
・引数(plantやheight)だけで結果がきまる
・self.gadensやself.total_growthを直接さわらない

reason2: ユーティリティをクラスの中において「責務を分ける」
GardenMangerが「管理(add/grow/report)」を担当し、
GardenStatsは「計算・整形」を担当する

まとめると、「状態に依存しない純関数」だからstaticmethod,かつ「gardenの補助機能」だからGardenManagerの内側においた

@classmethod(create_garden_network)
->別の作り方を提供するが目的である

reasonA: デモ用の別コンストラクトにしたい
create_garden_network()は実質こういう役割：
・GardenManager()をつくる
・初期データをいれる
・完成したインスタンスを返す
つまり初期化済みのGardenMangerを作るかんすう

・__init__ は「最低限の初期化」だけ
・create_garden_networkは「デモ用データを入れて生成」
classmthodは「どのクラスから呼ばれても、そのクラスのインスタンスを作れる」
ｃls() を使うことで、将来 GardenManager を継承した場合でも、呼び出したクラスのインスタンスを返せるようになり拡張性が上がります。

create_garden_network()はcls()でまず空のインスタンス(__init__)をつくり、そこにadd_plantでデモデータを追加して同じインスタンスを返す
cls()を使うのは、継承先から呼ばれたときにも継承先のインスタンスを生成できるようにするためである。

clsで呼び出しもとのクラスを生成できる

self は すでに生成済みのインスタンス を指す

instance method は 既にあるものを操作するのが基本
だから、生成手順を instance method にすると「目的が生成なのに、既にある self を使う」形になって不自然、という整理が正確です

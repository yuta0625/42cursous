class Plant:
    """植物(Plant)の基本クラス/Base class: name・height・plant_typeを持ち,grow()で成長させる."""
    def __init__(self, name: str, height: int) -> None:
        self.name = name
        self.height = height
        self.plant_type = "regular"

    def grow(self, grow_height: int) -> None:
        self.height += grow_height
        print(f"{self.name} grew {grow_height}cm")


class FloweringPlant(Plant):
    """花の植物(FloweringPlant)/Plantを継承し、colorとbloomingを追加する."""
    def __init__(
        self, name: str,
        height: int,
        color: str,
        blooming: bool
    ) -> None:
        """plant_type = floweringをもつ"""
        super().__init__(name, height)
        self.color = color
        self.blooming = blooming
        self.plant_type = "flowering"


class PrizeFlower(FloweringPlant):
    """(PrizeFlower)/FloweringPlantを継承し、pointsを追加する"""
    def __init__(
        self, name: str,
        height: int,
        color: str,
        blooming: bool,
        points: int
    ) -> None:
        """plant_type = prizeをもつ"""
        super().__init__(name, height, color, blooming)
        self.points = points
        self.plant_type = "prize"


class GardenManager:
    """GardenManger/ownerごとの植物リストを管理し,growとreportを行う"""
    class GardenStats:
        """calculating statics"""
        @staticmethod
        def height_validation(plants: list) -> bool:
            """高さの検証を行う"""
            for plant in plants:
                if plant.height < 0:
                    return False
            return True

        @staticmethod
        def count_types(plants: list[Plant]) -> tuple[int, int, int]:
            """種類カウント：regular, flowering, prizeを数えて返す"""
            regular = 0
            flowering = 0
            prize_flowers = 0
            for plant in plants:
                if plant.plant_type == "prize":
                    prize_flowers += 1
                elif plant.plant_type == "flowering":
                    flowering += 1
                else:
                    regular += 1
            return regular, flowering, prize_flowers

        @staticmethod
        def format_plant_line(plant: Plant) -> str:
            """植物の表示行を作る：typeごとに表示内容を変える"""
            if plant.plant_type == "prize":
                bloom = "(blooming)" if plant.blooming else ""
                return (
                    f"- {plant.name}: {plant.height}cm, {plant.color} flowers "
                    f"{bloom}, Prize points: {plant.points}"
                )
            if plant.plant_type == "flowering":
                bloom = "(blooming)" if plant.blooming else ""
                return (
                    f"- {plant.name}: {plant.height}cm, "
                    f"{plant.color} flowers {bloom}"
                )
            return f"- {plant.name}: {plant.height}cm"

        @staticmethod
        def garden_scores(plants: list[Plant]) -> int:
            """
            スコア計算を行う。
            計算：
                Scores = height total + prize points.
            """
            scores = 0
            for plant in plants:
                scores += plant.height
                if plant.plant_type == "prize":
                    scores += plant.points
            return scores

    def __init__(self) -> None:
        """管理用データを初期化:gardensとtotal_growthを用意する"""
        self.gardens: dict[str, list[Plant]] = {}
        self.total_growth: dict[str, int] = {}

    @classmethod
    def create_garden_network(cls) -> "GardenManager":
        """デモ用の初期データを作る: Aliceの庭に複数植物を追加する"""
        mgr = cls()
        mgr.add_plant("Alice", Plant("Oak Tree", 100))
        mgr.add_plant("Alice", FloweringPlant("Rose", 25, "red", True))
        mgr.add_plant(
            "Alice", PrizeFlower("Sunflower", 50, "yellow", True, 10)
            )
        mgr.add_plant("Bob", PrizeFlower("Sunflower", 43, "yellow", True, 20))
        return mgr

    def add_plant(self, owner: str, plant: Plant) -> None:
        """植物を追加 (add plant): ownerの庭に plantを登録する"""
        if owner not in self.gardens:
            self.gardens[owner] = []
        self.gardens[owner] += [plant]
        if owner == "Alice":
            print(f"Added {plant.name} to {owner}'s garden")

    def grow_all(self, owner: str, amount: int) -> None:
        """全植物を成長 (grow all): ownerの庭の植物を一括で grow(amount)する"""
        if owner not in self.gardens:
            print(f"{owner} is helping all plants grow...")
            return
        if owner not in self.total_growth:
            self.total_growth[owner] = 0
        print(f"{owner} is helping all plants grow...")
        for plant in self.gardens[owner]:
            plant.grow(amount)
            self.total_growth[owner] += amount

    def report(self, owner: str) -> None:
        """レポート出力 (report): ownerの庭の一覧・成長量・種別カウントを表示する"""
        if owner in self.gardens:
            plants = self.gardens[owner]
        else:
            plants = []
        if owner in self.total_growth:
            growth = self.total_growth[owner]
        else:
            growth = 0
        print(f"=== {owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in plants:
            print(self.GardenStats.format_plant_line(plant))
        regular, flowering, prize = self.GardenStats.count_types(plants)
        print(f"\nPlants added: {len(plants)}, Total growth: {growth}cm")
        print(
            f"Plant types: {regular} regular, "
            f"{flowering} flowering, {prize} prize flowers"
        )

    def total_gardens(self) -> int:
        """count gardensを返す"""
        count = 0
        for _ in self.gardens:
            count += 1
        return count

    def print_scores(self) -> None:
        """各庭のスコアを表示"""
        line = "Garden scores"
        first = True
        for owner in self.gardens:
            scores = self.GardenStats.garden_scores(self.gardens[owner])
            if first:
                line += f" - {owner} : {scores},"
                first = False
            else:
                line += f"  {owner} : {scores}"
        print(line)


def main() -> None:
    print("=== Garden Management System Demo ===")
    print()
    mgr = GardenManager.create_garden_network()
    print()
    mgr.grow_all("Alice", 1)
    print()
    mgr.report("Alice")
    print()
    print(
        "Height validation test: "
        f"{GardenManager.GardenStats.height_validation(mgr.gardens['Alice'])}"
    )
    mgr.print_scores()
    print(f"Total gardens managed: {mgr.total_gardens()}")


if __name__ == '__main__':
    main()

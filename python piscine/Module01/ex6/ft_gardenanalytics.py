class Plant:
    def __init__(self, name: str, height: int) -> None:
        self.name = name
        self.height = height
        self.plant_type = "regular"

    def grow(self, grow_height: int) -> None:
        self.height += grow_height
        print(f"{self.name} grew {grow_height}cm")


class FloweringPlant(Plant):
    def __init__(
        self, name: str,
        height: int,
        color: str,
        blooming: bool
    ) -> None:
        super().__init__(name, height)
        self.color = color
        self.blooming = blooming
        self.plant_type = "flowering"


class PrizeFlower(FloweringPlant):
    def __init__(
        self, name: str,
        height: int,
        color: str,
        blooming: bool,
        points: int
    ) -> None:
        super().__init__(name, height, color, blooming)
        self.points = points
        self.plant_type = "prize"


class GardenManager:
    class GardenStats:
        @staticmethod
        def height_validation(height: int) -> bool:
            return height >= 0

        @staticmethod
        def count_types(plants: list[Plant]) -> tuple[int, int, int]:
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
            """Scores = height total + prize points."""
            scores = 0
            for plant in plants:
                scores += plant.height
                if plant.plant_type == "prize":
                    scores += plant.points
            return scores

    def __init__(self) -> None:
        self.gardens: dict[str, list[Plant]] = {}
        self.total_growth: dict[str, int] = {}

    @classmethod
    def create_garden_network(cls) -> "GardenManager":
        mgr = cls()
        mgr.add_plant("Alice", Plant("Oak Tree", 101))
        mgr.add_plant("Alice", FloweringPlant("Rose", 26, "red", True))
        mgr.add_plant(
            "Alice", PrizeFlower("Sunflower", 51, "yellow", True, 10)
            )
        return mgr

    def add_plant(self, owner: str, plant: Plant) -> None:
        if owner not in self.gardens:
            self.gardens[owner] = []
        self.gardens[owner].append(plant)
        print(f"Added {plant.name} to {owner} garden")

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

    def report(self, owner: str) -> None:
        if owner in self.gardens:
            plants = self.gardens[owner]
        else:
            plants = []
        print(f"=== {owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in plants:
            print(self.GardenStats.format_plant_line(plant))
        regular, flowering, prize = self.GardenStats.count_types(plants)
        print(
            f"Plants added: {len(plants)}, "
            f"Total growth: {self.total_growth.get(owner, 0)}"
        )
        print(
            f"Plant types: {regular} regular. "
            f"{flowering} flowering, {prize} prize flowers"
        )

    def total_gardens(self) -> int:
        count = 0
        for _ in self.gardens:
            count += 1
        return count

    def print_scores(self) -> None:
        line = "Garden scores"
        first = True
        for owner in self.gardens:
            scores = self.GardenStats.garden_scores(self.gardens[owner])
            if first:
                line += f" - {owner} : {scores}"
                first = False
            else:
                line += f" - {owner} : {scores}"
        print(line)


def ft_gardenanalytics() -> None:
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
        f"{GardenManager.GardenStats.height_validation(10)}"
    )
    mgr.print_scores()
    print(f"Total gardens managed: {mgr.total_gardens()}")


if __name__ == '__main__':
    ft_gardenanalytics()

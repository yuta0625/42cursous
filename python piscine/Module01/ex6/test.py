class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height

    def grow(self, amount: int = 1):
        self.height += amount
        print(f"{self.name} grew {amount}cm")


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, color: str, blooming: bool):
        super().__init__(name, height)
        self.color = color
        self.blooming = blooming


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, color: str, blooming: bool, prize_points: int):
        super().__init__(name, height, color, blooming)
        self.prize_points = prize_points


class GardenManager:
    class GardenStats:
        @staticmethod
        def count_types(plants: list) -> tuple[int, int, int]:
            regular = flowering = prize = 0
            for p in plants:
                if isinstance(p, PrizeFlower):
                    prize += 1
                elif isinstance(p, FloweringPlant):
                    flowering += 1
                else:
                    regular += 1
            return regular, flowering, prize

        @staticmethod
        def format_plant_line(p) -> str:
            # 表示をExample寄りに分岐
            if isinstance(p, PrizeFlower):
                bloom = " (blooming)" if p.blooming else ""
                return f"- {p.name}: {p.height}cm, {p.color} flowers{bloom}, Prize points: {p.prize_points}"
            if isinstance(p, FloweringPlant):
                bloom = " (blooming)" if p.blooming else ""
                return f"- {p.name}: {p.height}cm, {p.color} flowers{bloom}"
            return f"- {p.name}: {p.height}cm"

    def __init__(self):
        self.gardens: dict[str, list] = {}        # owner -> plants[]
        self.total_growth: dict[str, int] = {}    # owner -> total growth

    def add_plant(self, owner: str, plant):
        self.gardens.setdefault(owner, []).append(plant)
        self.total_growth.setdefault(owner, 0)
        print(f"Added {plant.name} to {owner}'s garden")

    def grow_all(self, owner: str, amount: int = 1):
        print(f"{owner} is helping all plants grow...")
        for p in self.gardens.get(owner, []):
            p.grow(amount)
            self.total_growth[owner] += amount

    def report(self, owner: str):
        plants = self.gardens.get(owner, [])
        print(f"=== {owner}'s Garden Report ===")
        print("Plants in garden:")
        for p in plants:
            print(self.GardenStats.format_plant_line(p))

        regular, flowering, prize = self.GardenStats.count_types(plants)
        print(f"Plants added: {len(plants)}, Total growth: {self.total_growth.get(owner, 0)}cm")
        print(f"Plant types: {regular} regular, {flowering} flowering, {prize} prize flowers")


# --- demo ---
mgr = GardenManager()
mgr.add_plant("Alice", Plant("Oak Tree", 100))
mgr.add_plant("Alice", FloweringPlant("Rose", 25, "red", True))
mgr.add_plant("Alice", PrizeFlower("Sunflower", 50, "yellow", True, 10))

mgr.grow_all("Alice", 1)
mgr.report("Alice")

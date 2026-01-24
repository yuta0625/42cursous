class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> None:
        print(f"{self.name} (Flower): {self.height}cm, {self.age} days")


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color

    def get_info(self) -> None:
        print(
            f"{self.name} (Flower): {self.height}cm, {self.age} days, "
            f"{self.color} color"
        )

    def bloom(self) -> None:
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int, tr_d: int) -> None:
        super().__init__(name, height, age)
        self.tr_d = tr_d

    def get_info(self) -> None:
        print(
            f"{self.name} (Tree): {self.height}cm, {self.age} days, "
            f"{self.tr_d}cm diameter"
        )

    def produce_shade(self, shade_r: int) -> None:
        self.shade_r = shade_r
        print(f"{self.name} provides {self.shade_r} square meters of shade")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        harvest_season: str,
        nutritional_value: str,
    ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def get_info(self) -> None:
        print(
            f"{self.name} (Vegetable): {self.height}cm, {self.age} days, "
            f"{self.harvest_season} harvest"
        )

    def vegetable_output(self) -> None:
        print(f"{self.name} is rich in vitamin {self.nutritional_value}")


def ft_plant_types() -> None:
    print("=== Garden Plant Types===")
    """Flower"""
    rose = Flower("Rose", 25, 30, "red")
    rose.get_info()
    rose.bloom()
    """Tree"""
    oak = Tree("Oak", 500, 1825, 50)
    oak.get_info()
    oak.produce_shade(78)
    """Vegetable"""
    tomate = Vegetable("Tomate", 80, 90, "summer", "C")
    tomate.get_info()
    tomate.vegetable_output()


if __name__ == '__main__':
    ft_plant_types()

class Plant:
    """Basicなクラス(親クラス)として、基本的な設定を記述"""
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> None:
        print(f"{self.name} (Plant): {self.height}cm, {self.age} days")


class Flower(Plant):
    """花(Flower)クラス/Plantを継承し,colorとbloom()を追加する """
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        """親クラスを初期化し、色(color)を追加する"""
        super().__init__(name, height, age)
        self.color = color

    def get_info(self) -> None:
        print(
            f"{self.name} (Flower): {self.height}cm, {self.age} days, "
            f"{self.color} color"
        )

    def bloom(self) -> None:
        print(f"{self.name} is blooming beautifully!\n")


class Tree(Plant):
    """木(Tree)クラス/Plantを継承し、幹の直径(tr_d)や日陰(shade)機能を追加する."""
    def __init__(self, name: str, height: int, age: int, tr_d: int) -> None:
        """親クラスを初期化し、幹の直径(tr_d)を追加"""
        super().__init__(name, height, age)
        self.tr_d = tr_d

    def get_info(self) -> None:
        print(
            f"{self.name} (Tree): {self.height}cm, {self.age} days, "
            f"{self.tr_d}cm diameter"
        )

    def produce_shade(self) -> None:
        """
        幹の直径(tr_d, cm)から樹冠半径を「半径＝幹直径/２の３倍」と仮定して日陰計算を行う
        計算：
            canopy_radius_cm = 9 * (tr_d / 2) = 1.5 * tr_d
            canopy_radius_m  = canopy_radius_cm / 100
            shade_area_m2     = pi * canopy_radius_m^2
        """
        canopy_radius_m = (6 * self.tr_d) / 100.0
        self.shade_r = 3.14 * canopy_radius_m**2
        print(
            f"{self.name} provides about "
            f"{self.shade_r:.2f} square meters of shade\n"
        )


class Vegetable(Plant):
    """Vegetableクラス/Plantを継承し、harvest_seasonとnutrition情報を追加する."""
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        harvest_season: str,
        nutritional_value: str,
    ) -> None:
        """親クラスを初期化し、harves_seasonとnutritionを追加 """
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
    print("=== Garden Plant Types===\n")
    # Flower
    rose = Flower("Rose", 25, 30, "red")
    rose.get_info()
    rose.bloom()
    # Tree
    oak = Tree("Oak", 500, 1825, 50)
    oak.get_info()
    oak.produce_shade()
    # Vegetable
    tomate = Vegetable("Tomate", 80, 90, "summer", "C")
    tomate.get_info()
    tomate.vegetable_output()


if __name__ == '__main__':
    ft_plant_types()

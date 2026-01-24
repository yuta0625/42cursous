class Plants:
    def __init__(self, name: str, height: int, day: int) -> None:
        self.name = name
        self.height = height
        self.day = day
        self.grow_count = 0

    def grow(self, grow_cm: int) -> None:
        self.height += grow_cm
        self.grow_count += grow_cm

    def age(self, days: int) -> None:
        self.day += days

    def get_info(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.day} days ago")

    def get_grow_count(self) -> None:
        print(f"Growth this week: +{self.grow_count}cm")


def ft_plant_growth() -> None:
    rose = Plants("Rose", 25, 30)
    print("=== Day1 ===")
    rose.get_info()
    rose.grow(6)
    rose.age(6)
    print("=== Day7 ===")
    rose.get_info()
    rose.get_grow_count()


if __name__ == '__main__':
    ft_plant_growth()

class Plants:
    def __init__(self, name: str, height: int, day: int) -> None:
        self.name = name
        self.height = height
        self.day = day

    def get_info(self) -> None:
        print(f"{self.name}: {self.height} cm, {self.day} days old")


def ft_garden_data() -> None:
    plant_dataset = [
        Plants("Rose", 25, 30),
        Plants("Sunflower", 80, 45),
        Plants("Cactus", 15, 120),
    ]
    print("=== Garden Plant Registry ===")
    for plant in plant_dataset:
        plant.get_info()


if __name__ == '__main__':
    ft_garden_data()

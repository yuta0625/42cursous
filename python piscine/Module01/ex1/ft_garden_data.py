class Plants:
    """Plantの基本データを保持し、infoを表示するためのクラス"""
    def __init__(self, name: str, height: int, day: int) -> None:
        self.name = name
        self.height = height
        self.day = day

    def get_info(self) -> None:
        """植物のinfoを表示させるための関数"""
        print(f"{self.name}: {self.height} cm, {self.day} days old")


def ft_garden_data() -> None:
    """サンプル植物データを使って一覧表示する"""
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


# def ft_garden_data() -> None:
#     plant_data = []
#     platnt_rose = Plants("Rose", 25, 30)
#     platnt_sunflower = Plants("Sunflower", 80, 45)
#     platnt_cactus = Plants("Cactus", 15, 120)
#     plant_data.append(platnt_rose)
#     plant_data.append(platnt_sunflower)
#     plant_data.append(platnt_cactus)
#     for r in plant_data:
#         print(f"plant_name is {r.name}")
#         print(f"plant_height is {r.height}")
#         print(f"plant_day is {r.day}")

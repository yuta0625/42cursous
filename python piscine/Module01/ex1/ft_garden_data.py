class Plant:
    """Plantの基本データを保持し、infoを表示するためのクラス"""
    def __init__(self, name: str, height: int, day: int) -> None:
        self.name = name
        self.height = height
        self.day = day

    def get_info(self) -> None:
        """植物のinfoを表示させるための関数"""
        print(f"{self.name}: {self.height}cm, {self.day} days old")


def main() -> None:
    """サンプル植物データを使って一覧表示する"""
    plant_dataset = [
        Plant("Rose", 25, 30),
        Plant("Sunflower", 80, 45),
        Plant("Cactus", 15, 120),
    ]
    print("=== Garden Plant Registry ===")
    for plant in plant_dataset:
        plant.get_info()


if __name__ == '__main__':
    main()

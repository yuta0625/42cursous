class Plant:
    """植物の基本データを保持し、作成し出力を行うクラス"""
    def __init__(self, name: str, height: int, day: int) -> None:
        self.name = name
        self.height = height
        self.day = day

    def get_info(self) -> None:
        print(f"Created: {self.name} ({self.height}cm, {self.day} days)")


def main() -> None:
    """複数のPlantsを生成して一覧表示し、作成数(total count)を表示する"""
    plants_data = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120),
    ]
    print("=== Plant Factory Output ===")
    count = 0
    for plant in plants_data:
        plant.get_info()
        count += 1
    print()
    print(f"Total plants created: {count}")


if __name__ == '__main__':
    main()

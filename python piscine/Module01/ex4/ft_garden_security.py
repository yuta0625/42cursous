class SecurePlant:
    """安全に植物データを管理するクラス"""
    def __init__(self, name: str, height: int, age: int) -> None:
        self.__name = name
        self.__height = height
        self.__age = age

    def get_name(self) -> str:
        """naemを取得"""
        return self.__name

    def get_height(self) -> int:
        """heightを取得"""
        return self.__height

    def get_age(self) -> int:
        """ageを取得"""
        return self.__age

    def set_name(self, name: str) -> None:
        """nameを更新"""
        self.__name = name
        print(f"Plant created: {name}")

    def set_height(self, height: int) -> None:
        """heightを更新, neagativeはreject"""
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")
            return
        self.__height = height
        print(f"Height update: {height}cm [OK]")

    def set_age(self, age: int) -> None:
        if age < 0:
            """ageを更新, neagativeはreject"""
            print(f"Invalid operation attempted: age {age}days [REJECTED]")
            print("Security: Negative age rejected")
            return
        self.__age = age
        print(f"Height update: {age}days [OK]")

    def get_info(self) -> str:
        return (
            f"Current plant: {self.__name} "
            f"({self.__height}cm, {self.__age} days)"
        )


def ft_garden_security() -> None:
    """SecurePlantを使って安全な更新(validation)を検証"""
    print("=== Garden Security System ===")
    rose = SecurePlant("Rose", 25, 30)
    rose.set_name("Rose")
    rose.set_height(40)
    rose.set_age(40)
    print(rose.get_info())


if __name__ == "__main__":
    ft_garden_security()

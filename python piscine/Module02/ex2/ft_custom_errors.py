class GardenError(Exception):
    """Garden関連エラーをまとめるための基底例外クラス"""
    pass


class PlantError(GardenError):
    """plantに関する例外をまとめる"""
    pass


class WaterError(GardenError):
    """waterに関する例外をまとめる"""
    pass


def check_wilting(name: str, wilting: int) -> None:
    """wiltingをチェックし,条件にあわなかったらPlantErrorをraiseする"""
    if wilting <= 20:
        raise PlantError(f"The {name} plant is wilting!")


def check_tank(tank: int) -> None:
    """tankをチャックし,条件に合わなければ,waterErrorをraiseする"""
    if tank <= 20:
        raise WaterError("Not enough water in the tank!")


def main() -> None:
    """
    GardenError / PlantError / WaterErrorの確認を行う
    - PlantError / WaterErrorをそれぞれ個別にキャッチする
    - GardenErrorをcatchすると両方まとめてキャッチできる
    """
    print("=== Custom Garden Errors Demo ===\n")
    print("Testing PlantError...")
    try:
        check_wilting("tomato", 10)
    except PlantError as e:
        print(f"Caught PlantErro: {e}\n")

    print("Testing WaterError")
    try:
        check_tank(10)
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")

    print("Testing catching all garden errors...")
    try:
        check_wilting("tomato", 15)
    except GardenError as e:
        print(f"Caught a garden error: {e}")

    try:
        check_tank(6)
    except GardenError as e:
        print(f"Caught a garden error: {e}\n")
    print("All custom error types work correctly!")


if __name__ == "__main__":
    main()

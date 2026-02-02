class GardenError(Exception):
    """Garden関連エラーをまとめるための基底例外クラス"""
    pass


class InvalidPlantError(GardenError):
    """無効なデータが渡されたときに行う例外"""
    pass


def water_plants(plant_list: list) -> None:
    """
    - "watering system"を開いたと仮定して処理を開始し,各plantを表示する
    - plantがNoneの場合はInvalidPlantErrorをraiseする
    - finallyにより、成功・失敗に関わらず必ずcleaupを行う
    """
    try:
        print("Opening watering system")
        for plant in plant_list:
            if plant is None:
                raise InvalidPlantError("Cannot water None - invalid plant!")
            print(f"Watering {plant}")
    except GardenError as e:
        print(f"Error: {e}")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():
    print("=== Garden Watering System ===\n")
    print("Testing normal watering...")
    water_plants(["tomato", "lettuce", "carrots"])
    print("Watering completed successfully!\n")
    print("Testing with error...")
    water_plants(["tomato", None, "carrots"])
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()

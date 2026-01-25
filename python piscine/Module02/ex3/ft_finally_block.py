class GardenError(Exception):
    pass


class InvalidPlantError(GardenError):
    pass


def water_plants(plant_list: list) -> None:
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
    print()
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()

def check_plant_health(
    plant_name: str,
    water_level: int,
    sunlight_hours: int,
) -> str:
    """
    - plant_name, water_level, sunlight_hoursを確認
    - 問題があればValueError
    """
    if not plant_name:
        raise ValueError("Error: Plant name cannot be empty!\n")
    if water_level < 1:
        raise ValueError(
            f"Error: Water level {water_level} is too high (min 1)\n"
        )
    if water_level > 10:
        raise ValueError(
            f"Error: Water level {water_level} is too high (max 10)\n"
        )
    if sunlight_hours < 2:
        raise ValueError(
            f"Error: Sunlight hours {sunlight_hours} is too low (min 2)\n"
        )
    if sunlight_hours > 12:
        raise ValueError(
            f"Error: Sunlight hours {sunlight_hours} is too low (max 12)\n"
        )
    return f"Plant '{plant_name}' is healthy!\n"


def test_plant_checks() -> None:
    """
    check_plant_health()をいくつかの入力でチェックをおこなう
    """
    print("=== Garden Plant Health Checker ===\n")
    print("Testing good values")
    try:
        print(check_plant_health("tomato", 3, 4))
    except ValueError as e:
        print(e)

    print("Testing empty plant name...")
    try:
        print(check_plant_health("", 2, 4))
    except ValueError as e:
        print(e)

    print("Testing bad water level...")
    try:
        print(check_plant_health("tomato", 15, 4))
    except ValueError as e:
        print(e)

    print("Testing bad sunlight hours...")
    try:
        print(check_plant_health("tomato", 3, 0))
    except ValueError as e:
        print(e)

    print("All error raising tests completed!")


if __name__ == "__main__":
    test_plant_checks()

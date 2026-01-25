class GardenError(Exception):
    """basic error for garden problems"""
    pass


class PlantError(GardenError):
    """For problems with plants"""
    pass


class WaterError(GardenError):
    """For problems with plants"""
    pass


def check_wilting(name: str, wilting: int) -> None:
    if wilting <= 20:
        raise PlantError(f"The {name} plant is wilting!")


def check_tank(tank: int) -> None:
    if tank <= 20:
        raise WaterError("Not enough water in the tank!")


def ft_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===\n")
    print("Testing PlantError...")
    try:
        check_wilting("tomato", 10)
    except GardenError as e:
        print(f"Caught PlantErro: {e}\n")
    print("Testing WaterError")
    try:
        check_tank(10)
    except GardenError as e:
        print(f"Caught WaterError: {e}\n")
    print("Testing catching all garden errors...")
    try:
        check_wilting("tomato", 15)
    except GardenError as e:
        print(f"Caught PlantError: {e}")
    try:
        check_tank(6)
    except GardenError as e:
        print(f"Caught WaterError: {e}\n")
    print("All custom error types work correctly!")


if __name__ == "__main__":
    ft_custom_errors()

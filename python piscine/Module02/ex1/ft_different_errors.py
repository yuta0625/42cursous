def garden_operations() -> None:
    """ValueError example."""
    try:
        print("Testing ValueError...")
        x = int("abc")
        print(x)
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")
    """ZeroDivisionError"""
    try:
        print("Testing ZeroDivisionError...")
        x = 10 / 0
        print(x)
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")
    """FileNotFoundError"""
    try:
        print("Testing FileNotFoundError...")
        f = open("missing.txt", "r")
        content = f.read()
        print(content)
        f.close
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'\n")
    """KeyError"""
    try:
        print("Testing KeyError...")
        plant = {"Rose": 25}
        print(plant["Tuple"])
    except KeyError:
        print("Caught KeyError: 'missing_plant'\n")
    """Multi errors together"""
    try:
        print("Testing multiple errors together...")
        x = int("10")
        print(x/0)
    except (ValueError, ZeroDivisionError):
        print("Caught an error, but program continues!\n")


def test_error_types():
    print("=== Garden Error Types Demo===\n")
    garden_operations()
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()

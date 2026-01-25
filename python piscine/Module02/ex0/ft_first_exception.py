def ft_first_exception():
    print("=== Garden Temperature Checker ===")
    print()
    number = input("Testing temperture: ")
    try:
        temputer = int(number)
        if 0 <= temputer <= 40:
            print(f"Temperature {temputer}°C is perfect for plants!")
        elif temputer < 0:
            print(f"{temputer}°C is too hot for plants (max 40°C)")
        elif temputer > 40:
            print(f"{temputer}°C is too cold for plants (min 0°C)")
    except ValueError:
        print(f"Error: '{number}' is not a valid number")
    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    ft_first_exception()

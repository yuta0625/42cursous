def check_temperature() -> None:
    """
    標準入力から受け取った値を整数に変換し、次の条件で判定して表示を行う
    - 0-40
    - 0未満
    - 40より大きい
    整数に変換をすることができない入力の場合は、エラーメッセージを表示する
    """
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


def main():
    print("=== Garden Temperature Checker ===\n")
    check_temperature()
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    main()

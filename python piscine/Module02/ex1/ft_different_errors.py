def garden_operations() -> None:
    """
    エラーをわざと発生させて、try/exceptで捕捉できることをデモする関数。
    この関数は次の例外をテストする
    - ValueError: int("abc") のように数値に変換できない文字列を変換しようとする
    - ZeroDivisionError: 0 で割り算をする
    - FileNotFoundError: 存在しないファイルを開こうとする（例: "missing.txt"）
    - KeyError: 辞書に存在しないキーへアクセスする
    - (ValueError, ZeroDivisionError): 複数例外をまとめて捕捉する例
    """
    try:
        print("Testing ValueError...")
        x = int("abc")
        print(x)
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")

    try:
        print("Testing ZeroDivisionError...")
        x = 10 / 0
        print(x)
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}\n")

    try:
        print("Testing FileNotFoundError...")
        f = open("missing.txt", "r")
        content = f.read()
        print(content)
        f.close
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'\n")

    try:
        print("Testing KeyError...")
        plant = {"Rose": 25}
        print(plant["Tuple"])
    except KeyError:
        print("Caught KeyError: 'missing_plant'\n")

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

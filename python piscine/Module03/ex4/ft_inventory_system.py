import sys


def parse_argv(argv: list[str]) -> dict:
    inventory: dict[str, int] = {}
    for token in argv:
        parts = token.split(":")
        if len(parts) != 2:
            continue
        name = parts[0]
        if parts[1] == "":
            continue
        try:
            qty = int(parts[1])
        except ValueError:
            continue
        inventory[name] = inventory.get(name, 0) + qty
    return inventory


def main() -> None:
    inv = parse_argv(sys.argv[1:])
    print(inv)


if __name__ == "__main__":
    main()

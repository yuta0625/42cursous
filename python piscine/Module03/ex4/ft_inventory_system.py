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
    print("=== Inventory System Analysis ===")
    total_items = 0
    for _, v in inv.items():
        total_items += v
    print(f"Total items in inventory: {total_items}")
    print(f"Unique item types: {len(inv)}\n")
    print("=== Current Inventory ===")
    for name, qty in inv.items():
        percent = (qty/total_items) * 100
        print(f"{name}: {qty} units ({percent:.1f}%)")
    print("\n=== Inventory Statistics ===")
    most_name = ""
    most_qty = -1
    least_name = ""
    least_qty = -1
    for name, qty in inv.items():
        """most abundant"""
        if qty > most_qty:
            most_qty = qty
            most_name = name
        """least abundant"""
        if least_qty == -1 or qty < least_qty:
            least_qty = qty
            least_name = name
    print(f"Most abundant: {most_name} ({most_qty} units)")
    print(f"Least abundant: {least_name} ({least_qty} unit)\n")
    print("=== Item Categories ===")
    Moderate: dict[str, int] = {}
    Scarce: dict[str, int] = {}
    for name, qty in inv.items():
        if qty >= 5:
            Moderate[name] = Moderate.get(name, 0) + qty
        else:
            Scarce[name] = Scarce.get(name, 0) + qty
    print(f"Moderate: {Moderate}")
    print(f"Scarce: {Scarce}\n")
    print("=== Management Suggestions ===")
    restock = []
    for name, qty in inv.items():
        if qty == 1:
            restock += [name]
    print(f"Restock needed: {restock}\n")
    print("=== Dictionary Properties Demo ===")
    print(f"Dictionary keys: {list(inv.keys())}")
    print(f"Dictionary values: {list(inv.values())}")
    print(f"Sample lookup - 'sword' in inventory: {'sword' in inv}")


if __name__ == "__main__":
    main()

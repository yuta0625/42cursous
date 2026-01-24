def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    type_name = seed_type.capitalize()
    if unit == "packets":
        print(f"{type_name} seeds: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{type_name} seeds: {quantity} {unit} total")
    elif unit == "area":
        print(f"{type_name} seeds: covers {quantity} square meters")
    else:
        print("Unknown unit type")

import sys
import math


def distance(tuple1: int, tuple2: int) -> int:
    x1, y1, z1 = tuple1
    x2, y2, z2 = tuple2

    return math.sqrt(
        (x2 - x1) ** 2 +
        (y2 - y1) ** 2 +
        (z2 - z1) ** 2
    )


def parse_coordinates(s: str) -> tuple:
    parts = s.split(",")
    if len(parts) != 3:
        return
    return (int(parts[0]), int(parts[1]), int(parts[2]))


def main() -> None:
    print("=== Game Coordinate System ===\n")
    origin = (0, 0, 0)
    arg = len(sys.argv)
    if arg <= 1:
        pos1 = 10, 20, 5
        print(f"Position created: {pos1}")
        d1 = distance(origin, pos1)
        print(f"Distance between {origin} and {pos1}: {d1:.2f}\n")
        tup_str = "3,4,0"
        print(f'Parsing coordinates: "{tup_str}"')
        pos2 = parse_coordinates(tup_str)
        print(f"Parsed position: {pos2}")
        d2 = distance(origin, pos2)
        print(f"Distance between {origin} and {pos2}: {d2:.1f}\n")
        bad_str = "abc,def,ghi"
        print(f"Parsing invalid coordinates: {bad_str}")
        try:
            _ = parse_coordinates(bad_str)
        except ValueError as e:
            print(f"Error parsing coordinates: {e}")
            print(f'Error details - Type: ValueError, Args: {e.args}\n')

        print("Unpacking demonstration:")
        x, y, z = pos2
        print(f"Player at x={x}, y={y}, z={z}")
        print(f"Coordinates x={x}, y={y}, z={z}")
    else:
        origin = 0, 0, 0
        tup_str = sys.argv[1]
        print(f'Parsing coordinates: "{tup_str}"')
        try:
            pos = parse_coordinates(tup_str)
            print(f"Parsed position: {pos}")
            d = distance(origin, pos)
            print(f"Distance between {origin} and {pos}: {d:.2f}")
        except ValueError as e:
            print(f"Error parsing coordinates: {e}")
            print(f'Error details - Type: ValueError, Args: {e.args}\n')


if __name__ == "__main__":
    main()

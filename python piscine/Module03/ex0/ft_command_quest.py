import sys


def main() -> None:
    print("=== Command Quest ===")

    print(f"Program name: {sys.argv[0]}")
    args = sys.argv[1:]
    arg_count = len(args)
    if arg_count == 0:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {arg_count}")
    i = 1
    for arg in args:
        print(f"Arguments {i}: {arg}")
        i += 1
    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    main()

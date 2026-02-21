def ft_ancient_text(file_path: str) -> None:
    try:
        f = open(file_path, "r", encoding="utf-8")
        content = f.read()
        print(f"Accessing Storage Vault: {file_path}")
        print("Connection established...\n")
        print("RECOVERED DATA")
        print(content)
        f.close()
    except FileExistsError:
        print("ERROR:Storage vault not found. Run data generator first")
    finally:
        if f is not None:
            f.close()
            print("\nData recovery complete. Storage unit disconnected.")


def main():
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===\n")
    ft_ancient_text("ancient_fragment.txt")


if __name__ == "__main__":
    main()

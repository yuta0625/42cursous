def ft_archive_creation() -> None:
    new_file = open("new_discovery.txt", "w", encoding="utf-8")
    new_file.write("[ENTRY 001] New quantum algorithm discovered\n")
    new_file.write("[ENTRY 002] Efficiency increased by 347%\n")
    new_file.write("[ENTRY 003] Archived by Data Archivist trainee")


def main():
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n")
    ft_archive_creation()
    try:
        f = open("new_discovery.txt", "r", encoding="utf-8")
        content = f.read()
        print("Initializing new storage unit: new_discovery.txt")
        print("Storage unit created successfully...\n")
        print("Inscribing preservation data...")
        print(content)
    except FileNotFoundError:
        print("ERROR:Storage vault not found. Run data generator first")
    finally:
        if f is not None:
            f.close()
            print("\nData inscription complete. Storage unit sealed.")
            print(
                "Archive 'new_discovery.txt' ready for long-term preservation."
            )


if __name__ == "__main__":
    main()

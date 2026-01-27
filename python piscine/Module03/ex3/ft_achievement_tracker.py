def main() -> None:
    alice = {"first_kill", "level_10", "speed_demon", "treasure_hunter"}
    bob = {"first_kill", "level_10", "boss_slayer", "collector"}
    charlie = {
        "level_10",
        "treasure_hunter",
        "boss_slayer",
        "speed_demon",
        "perfectionist",
    }
    print("=== Achievement Tracker System ===\n")
    print(f"Player alice achievements: {alice}")
    print(f"Player bob achievements: {bob}")
    print(f"Player charlie achievements: {charlie}\n")

    print("=== Achievement Analytics ===")
    all_unique = alice | bob | charlie
    total_unique = len(all_unique)
    common_all_players = alice & bob & charlie

    """
    A unique item that one player has that is not common across the three
    """
    unique_alice_only = alice - (bob | charlie)
    unique_bob_only = bob - (alice | charlie)
    unique_charlie_only = charlie - (alice | bob)
    rare_achievement = (
        unique_alice_only | unique_bob_only | unique_charlie_only
    )

    common_two_player = alice & bob
    unique_alice = alice - bob
    unique_bob = bob - alice
    print(f"All unique achievements: {all_unique}")
    print(f"Total unique achievements: {total_unique}\n")
    print(f"Common to all players: {common_all_players}")
    print(f"Rare achievements (1 player): {rare_achievement}\n")
    print(f"Alice vs Bob common: {common_two_player}")
    print(f"Alice unique: {unique_alice}")
    print(f"Bob unique: {unique_bob}")


if __name__ == "__main__":
    main()

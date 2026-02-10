from typing import Any


def generater():
    players: list[dict[str, Any]] = [
        {"name": "alice", "score": 2300, "active": True, "region": "north",
         "achievements": {
             "pacifist",
             "level_10",
             "level_50",
             "treasure_hunter",
             "completionist",
            }},
        {"name": "bob", "score": 1800, "active": True, "region": "east",
         "achievements": {
             "first_kill",
             "berserker",
             "level_50"
            }},
        {"name": "charlie", "score": 2150, "active": True, "region": "central",
         "achievements": {
             "pacifist",
             "berserker",
             "level_50",
             "explorer",
             "treasure_hunter",
             "boss_slayer",
             "collector",
            }},
        {"name": "diana", "score": 2050, "active": False, "region": "north",
         "achievements": {
             "pacifist",
             "berserker",
             "level_50"
            }},
    ]
    for p in players:
        yield p


def category(players: list) -> tuple[int, int, int]:
    high = 0
    medium = 0
    low = 0
    for p in players["socre"]:
        if p > 2000:
            high += 1
        elif 1000 < p <= 2000:
            medium += 1
        else:
            low += 1
    return high, medium, low


def main():
    """generatorの情報を一度で展開"""
    players = list(generater())

    print("=== Game Analytics Dashboard ===\n")
    """list_comprehensions"""
    high_scores = [p["name"] for p in players if p["score"] > 2000]
    score_doubled = [p["score"] * 2 for p in players]
    active_players = [p["name"] for p in players if p["active"]]

    """dict_comprehensions"""
    players_score = {p["name"]: p["score"] for p in players}

    print(f"High scores (>2000): {high_scores}")
    print(f"Scores doubled: {score_doubled}")
    print(f"Active players: {active_players}\n")
    print("=== Dict Comprehension Examples ===")
    print(f"Player scores: {players_score}")


if __name__ == "__main__":
    main()

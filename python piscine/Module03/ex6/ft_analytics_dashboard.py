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


def main():
    """一度ですべてを展開している"""
    print("=== Game Analytics Dashboard ===\n")


if __name__ == "__main__":
    main()


# elf.player_names = [
#             "Alice",
#             "Bob",
#             "Charlie",
#             "Diana",
#             "Eve",
#             "Frank",
#             "Grace",
#             "Henry",
#             "Ivy",
#             "Jack",
#             "Kate",
#             "Liam",
#             "Maya",
#             "Noah",
#             "Olivia",
#             "Paul"]

#         self.achievements = [
#             "first_kill", "level_10", "level_50", "level_100", "speedrun",
#             "explorer", "treasure_hunter", "boss_slayer", "collector",
#             "perfectionist", "social_butterfly", "lone_wolf", "strategist",
#             "berserker", "pacifist", "completionist"
#         ]

#         self.item_types = [
#             "sword", "shield", "potion", "bow", "arrow", "armor", "helmet",
#             "boots", "ring", "amulet", "scroll", "gem", "key", "map"
#         ]

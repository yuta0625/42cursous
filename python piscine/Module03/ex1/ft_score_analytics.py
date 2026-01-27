import sys

def main():
    print("=== Player Score Analytics ===")
    if len(sys.argv) == 1:
        print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")
        return
    scores = []
    arg_count = len(sys.argv)
    for i in range(1, arg_count):
        try:
            scores = scores + [int(sys.argv[i])]
        except ValueError:
            print(f"Invalid score: {sys.argv[i]}")
            return
    total_players = len(scores)
    total_score = sum(scores)
    average = total_score / total_players
    high = max(scores)
    low = min(scores)
    
    print(f"Scores processed: {scores}")
    print(f"Total players: {total_players}")
    print(f"Total scores: {total_score}")
    print(f"Average score: {average}")
    print(f"High score: {high}")
    print(f"Low score: {low}")
    print(f"Score range: {high - low}")


if __name__ == "__main__":
    main()
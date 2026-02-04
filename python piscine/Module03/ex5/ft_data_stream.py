import time

def generators():
    """game_eventsのsteramを生成(name, level, action)"""
    players: tuple[tuple[str, int], ...] = (
        ("alice", 5),
        ("bob", 12),
        ("charlie", 8),
        ("hana", 15),
        ("rose", 3),
        ("flower", 2),
        ("tom", 32)
    )
    
    actions: tuple[str, ...] = (
        "killed monster",
        "found treasure",
        "leveled up",
        "found treasure",
        "killed monster",
        "killed monster"
    )
    
    i = 0
    while True:
        name, level = players[i % len(players)]
        action = actions[i % len(actions)]
        yield name, level, action
        i += 1

def fibonacci():
    """fibonacciを計算する"""
    a = 0
    b = 1
    while True:
        yield a
        a, b = b, a + b

def primes_number():
    """prime numbersの判断を行う"""
    n = 2
    while True:
        is_prime = True
        for i in range(2, n):
            if n % i == 0:
                is_prime = False
                break
        if is_prime:
            yield n
        n += 1

def main():
    """
    generatorを使ってdemoを実行する
    - ALL_PROCESS: 実行を行う回数
    - DISPLAY: 出力を行う処理の回数
    """
    ALL_PROCESS = 1000
    DISPLAY = 3
    
    high_level = 0
    treasure = 0
    level_up = 0
    
    answer = generators()
    stream = iter(answer)
    
    start = time.time()
    
    print(f"Processing {ALL_PROCESS} game events...\n")
    
    for i in range(ALL_PROCESS):
        name, level, action = next(stream)
        
        """displayする部分の処理"""
        if i < DISPLAY:
            print(f"Event {i + 1}: Player {name} (level {level}) {action}")
        if i == DISPLAY - 1:
            print("...\n")
    
        if level >= 10:
            high_level += 1
        if action == "found treasure":
            treasure += 1
        if action == "leveled up":
            level_up += 1
    
    end = time.time()
    print("=== Stream Analytics ===")
    print(f"Total events processed: {ALL_PROCESS}")
    print(f"High-level players (10+): {high_level}")
    print(f"Treasure events: {treasure}")
    print(f"Level-up events: {level_up}\n")
    
    print("Memory usage: Constant (streaming)")
    print(f"Processing time: {end - start:.6f} seconds")
    
    fib = fibonacci()
    prime = primes_number()
    print("=== Generator Demonstration ===")
    print("Fibonacci sequence (first 10):", end=" ")
    for _ in range(10):
        value = next(fib)
        print(value, end=" ")
    
    print("\nPrime numbers (first 5):", end=" ")
    for _ in range(5):
        value = next(prime)
        print(value, end=" ")
        

if __name__ == "__main__":
    main()

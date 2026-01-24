def ft_count_harvest_recurisive(day=None, days=None):
    if days is None:
        days = int(input("Days until harvest: "))
        day = 1
    if day > days:
        print("Harvest time!")
        return
    print(f"Day {day}")
    ft_count_harvest_recurisive(day + 1, days)

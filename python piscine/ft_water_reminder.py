def ft_water_reminder(n):
	if (n >= 2):
		return ("Water the plants!")
	else:
		return ("Plants are fine")

n = int(input())

print(ft_water_reminder(n))

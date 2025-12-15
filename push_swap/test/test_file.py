import random

nums = random.sample(range(-2147483647, 2147483646), 500)
print(" ".join(map(str, nums)))

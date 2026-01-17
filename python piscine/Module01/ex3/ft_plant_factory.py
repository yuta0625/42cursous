# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_factory.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 18:56:03 by yohya             #+#    #+#              #
#    Updated: 2026/01/17 17:08:56 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class	Plants:
	def __init__(self, name: str, height: int, day: int):
		self.name = name
		self.height = height
		self.day = day
	def	get_info(self):
		print(f"Created: {self.name} ({self.height}cm, {self.day} days)")

def	ft_plant_facotory():
	plants_data = [
		Plants("Rose", 25, 30),
		Plants("Oak", 200, 365),
		Plants("Cactus", 5, 90),
		Plants("Sunflower", 80, 45),
		Plants("Fern", 15, 120),
	]
	print("=== Plant Factory Output ===")
	count = 0
	for plant in plants_data:
		plant.get_info()
		count += 1
	print(f"Total plants created: {count}")

if __name__ == '__main__':
	ft_plant_facotory()

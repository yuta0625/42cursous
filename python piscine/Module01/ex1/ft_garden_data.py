# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_data.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 17:47:31 by yohya             #+#    #+#              #
#    Updated: 2026/01/17 17:05:02 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class	Plants:
	def __init__(self, name: str, height: int, day: int):
		self.name = name
		self.height = height
		self.day = day
	def get_info(self):
		print(f"{self.name}: {self.height} cm, {self.day} days old")

def	ft_gardem_data():
	plant_dataset = []
	rose = Plants("Rose", 25, 30)
	sunflower = Plants("Sunflower", 80, 45)
	cactus = Plants("Cactus", 15, 120)
	print("=== Garden Plant Registry ===")
	plant_dataset.append(rose)
	plant_dataset.append(sunflower)
	plant_dataset.append(cactus)
	for plant in plant_dataset:
		plant.get_info()

if __name__ == '__main__':
	ft_gardem_data()

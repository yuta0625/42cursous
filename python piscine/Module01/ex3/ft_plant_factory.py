# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_factory.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 18:56:03 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 19:41:27 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class	Plants:
	def __init__(self, name, height, day):
		self.name = name
		self.height = height
		self.day = day
	def	get_info(self):
		print(f"Created: {self.name} ({self.height}cm, {self.day} days)")

def	ft_plant_facotory():
	plants_data = [
		("Rose", 25, 30),
		("Oak", 200, 365),
		("Cactus", 5, 90),
		("Sunflower", 80, 45),
		("Fern", 15, 120),
	]
	print("=== Plant Factory Output ===")
	count = 0
	for data in plants_data:
		new_plant = Plants(data[0], data[1], data[2])
		new_plant.get_info()
		count += 1
	print(f"Total plants created: {count}")

if __name__ == '__main__':
	ft_plant_facotory()

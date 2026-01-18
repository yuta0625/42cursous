# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_gardenanalytics.py                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 16:01:50 by yohya             #+#    #+#              #
#    Updated: 2026/01/17 19:54:30 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Plant:
	def __init__(self, name: str, height: int):
		self.name = name
		self.height = height
	def grow(self, grow_height: int):
		self.height += grow_height
		print(f"{self.name} grew {grow_height}cm")
	def get_info(self):
		return f"{self.name}: {self.height}cm"

class FloweringPlant(Plant):
	def __init__(self, name: str, height: int, color: str, blooming: bool):
		super().__init__(name, height)
		self.color = color
		self.blooming = blooming

	def get_info(self):
		base_info = super().get_info()
		if self.blooming:
			status = "blooming"
		return f"{base_info}, {self.color} flowers ({status})"

class PrizeFlower(FloweringPlant):
	def __init__(self, name: str, height: int, color: str, blooming: bool, points: int):
		super().__init__(name, height, color, blooming, points)
		self.points = points

	def get_info(self):
		base_info = super().get_info()
		return f"{base_info}, Prize points{self.points}"

class GardenManager:

	total_gardens_managed = 0

	class GardenStatas:
		def __init__(self, plants, total_growth):
			self.plants = plants
			self.total_growth = total_growth

		def get_count(self):
			reg_count = 0
			flowering_count = 0
			prize_count = 0


	def __init__(self, owner):
		self.owner = owner
		self.plants = []
		self.total_growth = 0
		#呼び出さるたびにgardenを追加しないといけない
		GardenManager.total_gardens_managed += 1

	def add_plant(self, plant):
		self.plants.append(plant)
		print(f"Added {plant.name} to {self.owner} graden")

	def grow_all(self, amount):
		self.amount = amount
		for plant in self.plants:
			plant.grow(amount)
			self.total_grows += amount
   




def ft_gardenanalytics():
	print("=== Garden Management System Demo ===")
	alice_garden = GardenManager("Alice")
	oak = Plant("Oak Tree", 101)
	rose = FloweringPlant("Rose", 26, "red", True)
	sunflower = PrizeFlower("Sunflower", 51, "yellow", True, 10)
	alice_garden.add_plant(oak)
	alice_garden.add_plant(rose)
	alice_garden.add_plant(sunflower)

	alice_garden.grow_all(1)

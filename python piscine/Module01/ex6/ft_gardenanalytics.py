# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_gardenanalytics.py                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 16:01:50 by yohya             #+#    #+#              #
#    Updated: 2026/01/18 17:05:18 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Plant:
	def __init__(self, name: str, height: int):
		self.name = name
		self.height = height
		self.plant_type = "regular"
	def grow(self, grow_height: int):
		self.height += grow_height
		print(f"{self.name} grew {grow_height}cm")

class FloweringPlant(Plant):
	def __init__(self, name: str, height: int, color: str, blooming: bool):
		super().__init__(name, height)
		self.color = color
		self.blooming = blooming
		self.plant_type = "flowering"

class PrizeFlower(FloweringPlant):
	def __init__(self, name: str, height: int, color: str, blooming: bool, points: int):
		super().__init__(name, height, color, blooming)
		self.points = points
		self.plant_type = "prize"

class GardenManager:
	class GardenStats:
		@staticmethod
		def height_validation(height: int) -> bool:
				return height >= 0
		@staticmethod
		def	count_types(plants: list) -> tuple[int, int, int]:
			regular = 0
			flowering = 0
			prize_flowers = 0
			for p in plants:
				if p.plant_type == "prize":
					prize_flowers += 1
				elif p.plant_type == "flowering":
					flowering += 1
				else:
					regular += 1
			return regular, flowering, prize_flowers
		@staticmethod
		def format_plant_line(p) -> str:
				if p.plant_type == "prize":
					bloom = "(blooming)" if p.blooming else ""
					return f"- {p.name}: {p.height}cm, {p.color} flowers ({bloom}), Prize points: {p.points}"
				elif p.plant_type == "flowering":
					bloom = "(blooming)" if p.blooming else ""
					return f"- {p.name}: {p.height}cm, {p.color} flowers ({bloom})"
				else:
					return f"- {p.name}: {p.height}cm"
		@staticmethod
		def garden_scores(plants: list) -> int:
			"""scores = height total + prize point"""
			scores = 0
			for p in plants:
				scores += p.height
				if p.plant_type == "prize":
					scores += p.points
			return scores


	def __init__(self):
		self.gardens: dict[str: list] = {}
		self.total_growth: dict[str: int] = {}

	@classmethod
	def create_garden_network(cls):
		mgr = cls()
		mgr.add_plant("Alice", Plant("Oak Tree", 101))
		mgr.add_plant("Alice", FloweringPlant("Rose", 26, "red", True))
		mgr.add_plant("Alice", PrizeFlower("Sunflower", 51, "yellow", True, 10))
		return mgr

	def add_plant(self, owner: str, plant):
		if owner not in self.gardens:
			self.gardens[owner] = []
		self.gardens[owner].append(plant)
		print(f"Added {plant.name} to {owner} graden")

	def grow_all(self, owner: str, amount: int):
		if owner not in self.gardens:
			print(f"{owner} is helping all plants grow...")
			return
		if owner not in self.total_growth:
			self.total_growth[owner] = 0
		print(f"{owner} is helping all plants grow...")
		for i in self.gardens.get(owner, []):
			i.grow(amount)
			self.total_growth[owner] += amount

	def report(self,owner: str):
		if owner in self.gardens:
			plants = self.gardens[owner]
		else:
			plants = []
		print(f"=== {owner}'s Garden Report ===")
		print("Plants in garden:")
		for p in plants:
			print(self.GardenStats.format_plant_line(p))
		regular, flowering, prize = self.GardenStats.count_types(plants)
		print(f"Plants added: {len(plants)}, Total growth: {self.total_growth.get(owner, 0)}")
		print(f"Plant types: {regular} regular. {flowering} flowering, {prize} prize flowers")

	def total_gardens(self) -> int:
		count = 0
		for _ in self.gardens:
			count += 1
		return count

	def print_scores(self):
		line = "Garden socres"
		first = True
		for owner in self.gardens:
			scores = self.GardenStats.garden_scores(self.gardens[owner])
			if first:
				line += f" - {owner} : {scores}"
				first = False
			else:
				line += f" - {owner} : {scores}"
		print(line)


def ft_gardenanalytics():
	print("=== Garden Management System Demo ===")
	print()
	mgr = GardenManager.create_garden_network()
	print()
	mgr.grow_all("Alice", 1)
	print()
	mgr.report("Alice")
	print()
	print(f"Height validation test: {GardenManager.GardenStats.height_validation(10)}")
	mgr.print_scores()
	print(f"Total gardens managed: {mgr.total_gardens()}")

if __name__ == '__main__':
	ft_gardenanalytics()

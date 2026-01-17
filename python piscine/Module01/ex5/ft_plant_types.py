# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_types.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 15:03:32 by yohya             #+#    #+#              #
#    Updated: 2026/01/17 17:16:12 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Plant:
	def __init__(self, name: str, height: int, age: int):
		self.name = name
		self.height = height
		self.age = age
	def get_info(self):
		print(f"{self.name} (Flower): {self.height}cm, {self.age} days")

class Flower(Plant):
	def __init__(self, name: str, height: int, age: int, color: str):
		super().__init__(name, height, age)
		self.color = color
	def get_info(self):
		print(f"{self.name} (Flower): {self.height}cm, {self.age} days, {self.color} color")
	def bloom(self):
		print(f"{self.name} is blooming beautifully!")

class Tree(Plant):
	def __init__(self, name, height, age, trunk_diameter):
		super().__init__(name, height, age)
		self.trunk_diameter = trunk_diameter
	def get_info(self):
		print(f"{self.name} (Tree): {self.height}cm, {self.age} days, {self.trunk_diameter}cm diameter")
	#計算logicを考えるほうがいいかも
	def produce_shade(self, shade_range):
		self.shade_range = shade_range
		print(f"{self.name} provides {self.shade_range} square meters of shade")

class Vegetable(Plant):
	def __init__(self, name, height, age, harvest_season, nutritional_value):
		super().__init__(name, height, age)
		self.harvest_season = harvest_season
		self.nutritional_value = nutritional_value
	def get_info(self):
		print(f"{self.name} (Vegetable): {self.height}cm, {self.age} days, {self.harvest_season} harvest")
	def vegetable_output(self):
		print(f"{self.name} is rich in vitamin {self.nutritional_value}")

def ft_plant_types():
	print("=== Garden Plant Types===")
	"""Flowerの呼び出し"""
	rose = Flower("Rose", 25, 30, "red")
	rose.get_info()
	rose.bloom()
	"""Treeの呼び出し"""
	oak = Tree("Oak", 500, 1825, 50)
	oak.get_info()
	oak.produce_shade(78)
	"""Vegetableの呼び出し"""
	tomate = Vegetable("Tomate", 80, 90, "summer", "C")
	tomate.get_info()
	tomate.vegetable_output()

if __name__ == '__main__':
	ft_plant_types()

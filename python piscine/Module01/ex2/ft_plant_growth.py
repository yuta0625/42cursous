# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_growth.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 18:19:39 by yohya             #+#    #+#              #
#    Updated: 2026/01/17 17:46:51 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class	Plants:
	def __init__(self, name: str, height: int, day: int):
		self.name = name
		self.height = height
		self.day = day

	def	grow(self, grow_cm):
		self.height += grow_cm
	def age(self, days):
		self.day += days
	def	get_info(self):
		print(f"{self.name}: {self.height}cm, {self.day} days ago")

def	ft_plant_growth():
	rose = Plants("Rose", 25, 30)
	print("=== Day1 ===")
	rose.get_info()
	rose.grow(6)
	rose.age(6)
	print("=== Day 7 ===")
	rose.get_info()
	print("Growth this week: +6cm")

if __name__ == '__main__':
	ft_plant_growth()

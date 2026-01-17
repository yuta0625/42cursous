# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_security.py                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:27:26 by yohya             #+#    #+#              #
#    Updated: 2026/01/17 17:09:40 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class SecurePlant:
	def __init__(self, name: str, height: int, age: int):
		self.__name = name
		self.__height = height
		self.__age = age
	def get_name(self):
		return self.__name
	def get_height(self):
		return self.__height
	def get_age(self):
		return self.__age
	def set_name(self, name: str):
		self.__name = name
		print(f"Plant created: {name}")
	def set_height(self, height: int):
		if height < 0:
			print(f"Invalid operation attempted: height {height}cm [REJECTED]")
			print("Security: Negatice height rejected")
			return
		self.__height = height
		print(f"Heigh update: {height}cm [OK]")
	def set_age(self, age: int):
		if age < 0:
			print(f"Invalid operation attempted: height {age}days [REJECTED]")
			print("Security: Negatice age rejected")
			return
		self.__age = age
		print(f"Heigh update: {age}days[OK]")

def ft_garden_security():
	print("=== Garden Security System ===")
	rose = SecurePlant("Rose", 25, 30)
	rose.set_name("Rose")
	rose.set_height(-5)
	rose.set_age(30)
	print(f"Current plant: {rose.get_name()} ({rose.get_height()}cm, {rose.get_age()} days)")

if __name__ == "__main__":
	ft_garden_security()

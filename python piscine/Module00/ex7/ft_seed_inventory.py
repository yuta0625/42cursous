# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 16:44:27 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 17:06:00 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
	name = seed_type.capitalize()
	if (unit == "packets"):
		print(f"{name} seeds: {quantity} packets available")
	elif (unit == "grams"):
		print(f"{name} seeds: {quantity} grams total")
	elif (unit == "area"):
		print(f"{name} seeds: {quantity} square meters")
	else:
		print("UnKnown unit type")

if __name__ == "__main__":
	ft_seed_inventory()

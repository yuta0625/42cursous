# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_first_exception.py                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 18:35:44 by yohya             #+#    #+#              #
#    Updated: 2026/01/18 19:12:50 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_first_exception():
	print("=== Garden Temperature Checker ===")
	print()
	number = (input("Testing temperture: "))
	try:
		temputer = int(number)
		if (temputer >= 0) and (temputer <= 40):
			print(f"Temperature {temputer}°C is perfect for plants!")
		elif temputer < 0:
			print(f"{temputer}°C is too hot for plants (max 40°C)")
		elif temputer > 40:
			print(f"{temputer}°C is too cold for plants (min 0°C)")
	except ValueError:
		print(f"Error: '{number}' is not a valid number")
	print()
	print("All tests completed - program didn't crash!")

if __name__ == '__main__':
	ft_first_exception()

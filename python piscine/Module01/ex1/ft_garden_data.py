# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_data.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 17:47:31 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 18:52:01 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class	Plants:
	def __init__(self, name, height, day):
		self.name = name
		self.height = height
		self.day = day

def	ft_gardem_data():
	rose = Plants("Rose", "25cm", "30 days old")
	sunflower = Plants("Sunflower", "80cm", "45 days old")
	cactus = Plants("Cactus", "15cm", "120 days old")
	print("=== Garden Plant Registry ===")
	print(f"{rose.name}: {rose.height}, {rose.day}")
	print(f"{sunflower.name}: {sunflower.height}, {sunflower.day}")
	print(f"{cactus.name}: {cactus.height}, {cactus.day}")

if __name__ == '__main__':
	ft_gardem_data()

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:48:39 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 16:58:17 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_plant_age():
	n = int(input("Enter plant age in days: "))
	if (n >= 60):
		print("Plant is ready to harvest!")
	else:
		print("Plant needs more time to grow.")

if __name__ == '__main__':
	ft_plant_age()

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_summary.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 16:34:17 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 16:42:16 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_garden_summary():
	Garden = input("Enter garden name: ")
	Plants = int(input("Enter number of plants: "))
	print(f"Garden:",Garden)
	print(f"Plants:",Plants)
	print("Status: Growing well")

if __name__ == '__main__':
	ft_garden_summary()

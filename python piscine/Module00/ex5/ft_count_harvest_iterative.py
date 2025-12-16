# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:58:57 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 16:18:29 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_iterative():
	n = int(input("Days until harvest: "))
	for i in range(1, n + 1):
		print(f"Day {i}")
	print("Harvest time!")

if __name__ == '__main__':
	ft_count_harvest_iterative()

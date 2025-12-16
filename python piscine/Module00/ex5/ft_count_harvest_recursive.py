# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 16:18:16 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 16:58:35 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_count_harvest_recursive():
	days = int(input("Days until harvest: "))
	def	recursive_loap(current_day):
		if (current_day > days):
			print("Harvest time")
			return
		print(f"Day {current_day}")
		recursive_loap(current_day + 1)
	recursive_loap(1)

if __name__ == '__main__':
	ft_count_harvest_recursive()

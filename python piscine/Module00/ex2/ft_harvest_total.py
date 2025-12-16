# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:47:25 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 15:47:26 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def add_total(a, b, c):
	return a + b + c

def	ft_harvest_total():
	Day1 = int(input("Day 1 harvest: "))
	Day2 = int(input("Day 2 harvest: "))
	Day3 = int(input("Day 3 harvest: "))
	print("Total harvest: ", add_total(Day1, Day2, Day3))

if __name__ == '__main__':
	ft_harvest_total()

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:57:56 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 15:57:59 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
	n = int(input("Days sinece last watering: "))
	if (n >= 2):
		print("Water the plants!")
	else:
		print("Plants are fine")

if __name__ == '__main__':
	ft_water_reminder()

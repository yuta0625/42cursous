# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plot_area.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 15:25:57 by yohya             #+#    #+#              #
#    Updated: 2025/12/16 15:37:24 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_plot_area():
	length = int(input("Enter length: "))
	width = int(input("Eneter width: "))
	print(f"Plot area: {length * width}")

if __name__ == '__main__':
	ft_plot_area()

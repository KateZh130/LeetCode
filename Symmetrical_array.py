'''
Задача: дан массив точек с целочисленными координатами (x, y).
Определить, существует ли вертикальная прямая, делящая все точки,
не лежащие на ней, на 2 симметричных относительно этой прямой набора точек.
Наборы симметричны когда каждая точка исходного массива имеет пару из другого набора.
'''


def find_axis(list):
    sum = 0
    for i in range(len(list)):
        sum += list[i][0]
    axis = sum/len(list)
    return axis


def is_symmetrical(list):
    axis = find_axis(list)
    count = 0
    for point in list:
        x = point[0]
        y = point[1]
        if x == axis:
            count += 1
        elif [2*axis-x, y] in list:
            count += 1
    if count == len(list):
        return True
    return False


if __name__ == '__main__':
    list1 = [[1, 3], [3, 3], [2, 2], [2, 10], [0, 4], [4, 4]]
    list2 = [[1, 4], [3, 3], [6, 2]]
    print('1)', is_symmetrical(list1))
    print('2)', is_symmetrical(list2))


'''
Задача: дан список неотрицательных целых чисел, повторяющихся элементов в списке нет.
Нужно преобразовать его в строку, сворачивая соседние по числовому ряду числа в диапазоны.
Примеры:
[1,4,5,2,3,9,8,11,0] => "0-5,8-9,11"
[1,4,3,2] => "1-4"
[1,4] => "1,4"
[1,2] => "1-2"
'''

def range_list(list):
    string=''
    list.sort()
    first=-1
    last=first
    for index in range(len(list)):
        if first==-1:
            first=list[index]
            last=first
            continue
        elif list[index]==list[index-1]+1:
            last=list[index]
        else:
            if last==first:
                string+=str(first)+','
            else:
                string+=str(first)+'-'+str(last)+','
            first=list[index]
            last=first

    if first==last:
        string+=str(first)
    else:
         string+=str(first)+'-'+str(last)
    return string


if __name__ == '__main__':
    list = [1, 4, 5, 2, 3, 9, 8, 11, 0]
    #list=[1,4,3,2]
    #list=[1,4]
    #list=[1,2]
    print(range_list(list))

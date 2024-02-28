'''
Задача: дана строка (возможно, пустая), содержащая буквы A-Z:
AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB
Нужно написать функцию RLE, которая вернет строку вида: A4B3C2XYZD4E3F3A6B28
Функция должна выдавать ошибку, если на вход приходит недопустимая строка.
Примечания:
Если символ встречается один раз, он остается неизменным;
Если символ встречается более одного раза, к нему добавляется число повторений.
'''
def RLE(string):
    count = 1
    new_string = ''
    if string == '':
        return 'Error: empty string'

    for index in range(1, len(string)):
        letter = string[index]
        prev_letter = string[index - 1]
        if letter.isdigit():
            return 'Error: string contains a digit'
        if letter.islower():
            return 'Error: string must not contain lowercase letters'
        if letter == prev_letter:
            count += 1
        else:
            new_string += prev_letter
            if count != 1:
                new_string += str(count)
                count = 1
    new_string += prev_letter
    if count != 1:
        new_string += str(count)

    return new_string


if __name__ == '__main__':
    string = 'AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB'
    print(RLE(string))

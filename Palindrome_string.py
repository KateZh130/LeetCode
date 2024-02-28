'''
Задача: нужно написать функцию, которая определяет, является ли переданная строка палиндромом.
Примеры палиндромов:
* Казак
* А роза упала на лапу Азора
* Do geese see God?
* Madam, I’m Adam
'''

import string


def is_palindrome(my_string):
    my_string=formatting(my_string)
    for i in range(int(len(my_string)/2)):
        if my_string[i]!=my_string[len(my_string)-1-i]:
            return False
    return True


def formatting(my_string):
    my_string=my_string.translate(str.maketrans('', '', string.punctuation))
    my_string=my_string.lower()
    my_string=my_string.strip(' ')
    my_string="".join(my_string.split())
    my_string=my_string.replace("’","")
    return my_string


if __name__ == '__main__':
    print('1.', is_palindrome("  This &is [an] example? {of} string. with.? punctuation!!!!  "))
    print('2.', is_palindrome('Казак'))
    print('3.', is_palindrome('А роза упала на лапу Азора'))
    print('4.', is_palindrome('Do geese see God?'))
    print('5.', is_palindrome('Madam, I’m Adam'))

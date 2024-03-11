'''
Написать функцию, которая принимает на вход строку – номер билета (состоящий из 6 цифр) и
возвращает строку "Счастливый билет", если билет счастливый (сумма первых трех цифр равна сумме последних
трёх) или "Несчастливый билет", если билет оказался несчастливым
'''
def is_lucky_ticket(number):
    if len(number) != 6:
        return 'Номер билета должен быть шестизначным!'
    result = 0
    for i in range(int(len(number)/2)):
        result += int(number[i])-int(number[len(number)-1-i])
    if result != 0:
        return "Несчастливый билет"
    return "Счастливый билет"


if __name__ == '__main__':
    number = int(input("Введите номер билета: "))
    print(f"Билет {number};")
    print(f"Результат: {is_lucky_ticket(str(number))}")

'''
Задача: нужно реализовать функцию OneEditApart ,
проверяющую, можно ли одну строку получить из другой не более,
чем за одно исправление (удаление, добавление, изменение символа):
OneEditApart("cat", "dog") -> false
OneEditApart("cat", "cats") -> true
OneEditApart("cat", "cut") -> true
OneEditApart("cat", "cast") -> true
OneEditApart("cat", "at") -> true
OneEditApart("cat", "acts") -> false
'''


def one_edit_apart(word1, word2):
    dif_counter = 0
    if len(word1) == len(word2):
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                dif_counter += 1
        if dif_counter == 1:
            return True
    elif len(word1)+1 == len(word2):
        for i in range(len(word1)):
            if word1[i] != word2[i+dif_counter]:
                dif_counter += 1
                if dif_counter > 1:
                    return False
                i -= 1
        return True
    elif len(word1)-1 == len(word2):
        for i in range(len(word2)):
            if word1[i+dif_counter] != word2[i]:
                dif_counter += 1
                if dif_counter > 1:
                    return False
                i -= 1
        return True
    return False


if __name__ == '__main__':
    word = 'cat'
    print('1)', one_edit_apart(word, 'dog'))
    print('2)', one_edit_apart(word, 'cats'))
    print('3)', one_edit_apart(word, 'cut'))
    print('4)', one_edit_apart(word, 'cast'))
    print('5)', one_edit_apart(word, 'at'))
    print('6)', one_edit_apart(word, 'acts'))


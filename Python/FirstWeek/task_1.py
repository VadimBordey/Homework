def ProcessLetters(InputString):
    VowelLetters = 'aeiouAEIOU'
    ConsonantLetters = 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ'

    VowelChars = []
    ConsonantChars = []

    for Character in InputString:
        if Character in VowelLetters:
            VowelChars.append(Character)
        elif Character in ConsonantLetters:
            ConsonantChars.append(Character)

    VowelChars.sort(reverse=True)
    ConsonantChars.sort(reverse=True)

    VowelStr = ''
    for Character in VowelChars:
        VowelStr += Character

    ConsonantStr = ''
    for Character in ConsonantChars:
        ConsonantStr += Character

    HasEnoughConsonants = len(ConsonantChars) >= 4

    return (VowelStr, HasEnoughConsonants, ConsonantStr)


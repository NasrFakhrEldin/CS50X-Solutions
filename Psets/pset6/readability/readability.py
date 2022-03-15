from cs50 import get_string


def main():

    # initialization the functions
    Text = get_string("Enter The Tex: ")
    x = get_letter(Text)
    y = get_word(Text)
    z = get_sentences(Text)
    G = Grade_level(x, y, z)

    Print(G)

# function for counting letters


def get_letter(Text):

    number_of_letter = 0
    for i in Text:
        # the condition for counting the letters
        if i.isalpha():
            number_of_letter += 1
    return number_of_letter

# function for counting words


def get_word(Text):

    number_of_word = 0
    # the condition for counting the words
    for j in Text:
        if j == " ":
            number_of_word += 1

    return number_of_word + 1

# function for counting sentences


def get_sentences(Text):

    number_of_sentences = 0
    for k in Text:
        # the condition for counting the sentences
        if k == '.' or k == '!' or k == '?':
            number_of_sentences += 1
    return number_of_sentences

# function for select the right grade


def Grade_level(number_of_letter, number_of_word, number_of_sentences):

    L = (number_of_letter / float(number_of_word) * 100)
    S = (number_of_sentences / float(number_of_word) * 100)

    return round(0.0588 * L - 0.296 * S - 15.8)

# function for printing the grade


def Print(Grade_level):

    if Grade_level <= 1:
        print("Before Grade 1")
    elif Grade_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {Grade_level}")


if __name__ == "__main__":
    main()


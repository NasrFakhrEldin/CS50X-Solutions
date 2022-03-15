from cs50 import get_int


def main():

    # initialization function
    x = Print()
# for loops specifying number of spaces and hashes per line
    for i in range(0, x, +1):
        for j in range(0, x, +1):
            if (i + j) < (x - 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()


def Print():
    # print function
    while True:
        H = get_int("Enter the Height: ")
        if H > 0 and H <= 8:
            return H


main()

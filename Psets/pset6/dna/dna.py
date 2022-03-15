import csv
from sys import argv


def main():

    # check for correct number of arguments
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # open files
    database = open(argv[1])
    dna = open(argv[2])

    database_r = csv.DictReader(database)
    STRs = database_r.fieldnames[1:]

    # copy contents and close the file
    DNA = dna.read()
    dna.close()

    # count num of each STRs and put it on Dic
    Dic = {}
    for STR in STRs:
        Dic[STR] = repeats(STR, DNA)

    # search to find match
    for row in database_r:

        # print if there is match
        if match(STRs, Dic, row):
            print(f"{row['name']}")
            database.close()
            return

    # print if no match
    print("No match")
    database.close()


def repeats(STR, DNA):
    i = 0
    while STR*(i + 1) in DNA:
        i += 1
    return i


def match(STRs, Dic, row):
    for STR in STRs:
        if Dic[STR] != int(row[STR]):
            return False
    return True


main()
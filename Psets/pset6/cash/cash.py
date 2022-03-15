from cs50 import get_float

while True:
    # Get Dollars from user
    Dollars = get_float("Change owed: ")
    # Make Dollars Positive
    if Dollars >= 0:
        break

cents = round(Dollars * 100)

coins = 0
while cents != 0:
    # 25
    coins = coins + (cents // 25)
    cents = cents % 25
    # 10
    coins = coins + (cents // 10)
    cents = cents % 10
    # 5
    coins = coins + (cents // 5)
    cents = cents % 5
    # 1
    coins = coins + (cents // 1)
    cents = cents % 1

print("you need at least : ", int(coins))

-- Keep a log of any SQL queries you execute as you solve the mystery.

-- the theft took place on July 28, 2020 and that it took place on Chamberlin Street

SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2020 AND street = "Chamberlin Street"

-- description
SELECT transcript FROM interviews
WHERE day = 28 AND MONTH = 7 AND year = 2020
-- transcript 1:
-- "Sometime within ten minutes of the theft,
-- I saw the thief get into a car in the courthouse parking lot and drive away.
-- If you have security footage from the courthouse parking lot,
-- you might want to look for cars that left the parking lot in that time frame."
SELECT name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = "exit"

-- names 1: Patrick, Ernest, Amber, Danielle, Roger, Elizabeth, Russell, Evelyn



-- transcript 2:
-- "I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at the courthouse,
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money."
SELECT DISTINCT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2020 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Fifer Street"

-- names 2: Danielle, Bobby, Madison, Ernest, Roy, Elizabeth, Victoria, Russell
-- compare names 1 with names 2: result 1 = Ernest, Daniellle, Elizabeth, Russell


-- transcript 3:
-- "As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket."
-- Frist check the passengers for the flight on day 29
SELECT name FROM people
JOIN passengers On people.passport_number = passengers.passport_number
WHERE flight_id IN (
SELECT id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)

-- names 3: Doris, Roger, Ernest, Edward, Evelyn, Madison, Bobby, Danielle
-- compare result 1 with names 3: result 2 = Ernest, Danielle


-- check phone calls:
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60

-- names 4: Roger, Evelyn, Ernest, Evelyn, Madison, Russell, Kimberly, Bobby, Victoria
-- compare result 2 with names 4: result 3 = Ernest

-- The THIEF is: Ernest
SELECT city FROM airports
WHERE id IN (
SELECT destination_airport_id FROM flights
WHERE year = 2020  AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)


-- The thief ESCAPED TO: London
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60 AND caller IN (
SELECT phone_number FROM people
WHERE name = "Ernest");

-- The ACCOMPLICE is: Berthold

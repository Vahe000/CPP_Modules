# Exercise 00: Bitcoin Exchange

## Objective

Create a program that outputs the value of a certain amount of bitcoin on a certain date.

## Instructions

1. Create a CSV file named `bitcoin_prices.csv` containing bitcoin prices over time.
2. Create a CSV file named `input.txt` containing dates and values to evaluate.
3. Write a program named `btc.cpp` that reads the `bitcoin_prices.csv` and `input.txt` files, calculates the value of each bitcoin amount on each date, and outputs the results to the standard output.
4. Handle errors with appropriate error messages.
5. Use at least one container in your code.

## Example Usage

``bash
./btc
Error: could not open file.
./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.

# Exercise 01: Reverse Polish Notation

## Objective

Create a program that evaluates reverse Polish notation mathematical expressions.

## Instructions

1. Write a program named `rpn.cpp` that takes an inverted Polish mathematical expression as an argument and evaluates it.
2. Support operations with tokens "+", "-", "*", "/".
3. Handle errors with appropriate error messages.
4. Use at least one container in your code.

## Example Usage

``bash
./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
./rpn "7 7 * 7 -"
42
./rpn "1 2 * 2 / 2 * 2 4 - +"
0
./rpn "(1 + 1)"
Error: malformed expression

# Exercise 02: PmergeMe

## Objective

Create a program that sorts a positive integer sequence using the merge-insert sort algorithm.

## Instructions

1. Write a program named `pmergeme.cpp` that takes a positive integer sequence as an argument and sorts it using the merge-insert sort algorithm.
2. Use two different containers in your code.
3. Display the unsorted and sorted sequences, along with the time taken to sort with each container.
4. Handle errors with appropriate error messages.

## Example Usage

``bash
./pmergeme 3 5 9 7 4
Before: 3 5 9 7 4
After (std::vector): 3 4 5 7 9
Time to process: 0 us
After (std::list): 3 4 5 7 9
Time to process: 0 us

./pmergeme `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After (std::vector): 79 141 321 526 [...]
Time to process: 62.14389 us
After (std::list): 79 141 321 526 [...]
Time to process: 69.27212 us

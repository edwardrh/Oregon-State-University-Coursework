# Program: mypython.py
# Author: Rhea Mae Edwards
# Date: 11/24/2016
#
# Overview:
# - Create 3 files in the same directory of script
#   - Different Names (up to you!)
#   - Remains in directory even after execution
#   - Contain exactly 10 random characters,
#     from lowercase alphabet, no spaces (e.g. "howhdgwkdq")
#   - The eleventh character should be a newline character
# - Print out the contents of the 3 files
# - Print out the two random integers (range: 1-42)
#   - Then print out their product

# importing the string library

import string

# importing the random library

import random 

# printing out a blank line

print("");

# creating first file in the current directroy

file1 = open('firstfile.txt', 'w');

# generating a 10 random characters, from lowercase alphabet, no spaces

file1word = ''.join(random.choice(string.lowercase) for i in range(10));

# writing the generated string in the file

file1.writelines(file1word);

# closing the file

file1.close();

# reading and printing out the contents of the first file

print("Contents of 1st File:");
read1 = open('firstfile.txt', 'r');
print read1.read();

# creating second file in the current directroy

file2 = open('secondfile.txt', 'w');

# generating a 10 random characters, from lowercase alphabet, no spaces

file2word = ''.join(random.choice(string.lowercase) for i in range(10));

# writing the generated string in the file

file2.writelines(file2word);

# closing the file

file2.close();

# reading and printing out the contents of the first file

print("Contents of 2nd File:");
read2 = open('secondfile.txt', 'r');
print read2.read();

# creating third file in the current directroy

file3 = open('thirdfile.txt', 'w');

# generating a 10 random characters, from lowercase alphabet, no spaces

file3word = ''.join(random.choice(string.lowercase) for i in range(10));

# writing the generated string in the file

file3.writelines(file3word);

# closing the file

file3.close();

# reading and printing out the contents of the first file

print("Contents of 3rd File:");
read3 = open('thirdfile.txt', 'r');
print read3.read();

# printing out a blank line

print("");

# generating first random number

num1 = random.randint(1, 42);

# printing out first random number within the range of 1-42

print("Random Number 1: " + str(num1));

# generating second random number

num2 = random.randint(1, 42);

# printing out second random number within the range of 1-42

print("Random Number 2: " + str(num2));

# product of the two random numbers

print("Product of the two randomly generated numbers:");
print(num1 * num2);

# printing out a blank line

print("");

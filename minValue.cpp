// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: May 24, 2025
/* This program generates and displays
ten random numbers from 0 to 100 with
arrays and then displays the minimum number. */

/* Include the time header to access
time functions. */
#include <time.h>
/* Include the array library for
special arrays. */
#include <array>
/* Include the iostream library for
input and output functionalities. */
#include <iostream>
/* Include the random library
for random generators. */
#include <random>

/* Set the constant maximum random
number to 100. Set it outside of the
main function so that it can be used
in both functions. */
const int MAX_NUM = 100;

/* Declare a template for the size of
any array to use it in the parameter. */
template<size_t N>
/* Define a function to get the minimum
number out of a number array. */
int findMinValue(std::array<int, N> numArray) {
    /* Initialize the current minimum
    number as one greater than the
    maximum number so that it always
    gets reinitialized. */
    int currentMinValue = MAX_NUM + 1;

    /* Use a for..each loop to loop
    over every number in the array. */
    for (int number : numArray) {
        /* Check if the number is lesser
        than the current minimum number. */
        if (number < currentMinValue) {
            /* Set the current minimum
            value to the number. */
            currentMinValue = number;
        }
    }
    // Return the resulting minimum value.
    return currentMinValue;
}

// Runs the main function.
int main() {
    // Display an empty space to format text.
    std::cout << "\n";
    // Set the constant maximum array size to 10.
    const int MAX_ARRAY_SIZE = 10;
    // Set the constant minimum random number to 0.
    const int MIN_NUM = 0;

    /* Initialize an array of
    integers to be used later. */
    std::array<int, MAX_ARRAY_SIZE> arrayOfInt;

    /* Use a for loop to loop over the maximum array
    size to generate the ten random numbers. */
    for (int index = 0; index < MAX_ARRAY_SIZE; index++) {
        // Set a random device to construct the engine.
        std::random_device randomDevice;
        /* Use the mersenne twister
        for high-quality randomizing. */
        std::mt19937 randomGen(randomDevice());
        /* Uniformly distribute the possible integers
        over a distance of the minimum number possible, 0,
        to the maximum number possible, 100. */
        std::uniform_int_distribution<int> intDist(MIN_NUM, MAX_NUM);

        // Set the random number to the generated integer.
        int randomNumber = intDist(randomGen);
        // Populate the array by inserting the random number.
        arrayOfInt[index] = randomNumber;

        /* Display information about the random
        number and its current position. */
        std::cout << randomNumber
        << " added to the array at position "
        << index << ".\n";
    }

    /* Determine the minimum number by assigning
    it to the find minimum value function. */
    int minNumber = findMinValue(arrayOfInt);
    // Display the minimum number.
    std::cout << "\nThe min value is: "
    << minNumber << ".\n\n";
}

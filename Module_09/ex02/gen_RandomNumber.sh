#!/bin/bash

# Number of random numbers to generate
num_random_numbers=3000

# Define the range
min_range=1
max_range=100

# Generate and display random numbers
for ((i = 0; i < num_random_numbers; i++)); do
    random_number=$((RANDOM % (max_range - min_range + 1) + min_range))
    echo -n "$random_number "
done

# Two's Complement Arithmetic Simulator

## Overview
This program simulates how computers store and process signed integers using two's complement representation. It performs fixed-width addition and subtraction, converts decimal to binary, and detects signed overflow conditions.

## Features
- Supports 4, 8, 16, and 32-bit word sizes
- Addition and subtraction operations
- Decimal to binary conversion with leading zeros
- Signed overflow detection (positive + positive = negative, etc.)
- Interactive mode for custom values
- Comparison between signed and unsigned overflow

## How It Works
- Negative numbers are automatically handled in two's complement by masking with `(1 << bit_width) - 1`
- Fixed-width arithmetic simulates an n-bit CPU register
- Overflow detection checks if result is outside valid range: `-(2^(n-1))` to `2^(n-1)-1`

## Sample Output

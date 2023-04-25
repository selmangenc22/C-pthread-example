# Parallel Prime Number Search

This is a C program that searches for prime numbers in parallel using multiple threads. The program allows the user to specify the number of threads to use and searches for prime numbers between 0 and a predefined maximum range. It then prints the time taken for the sequential/parallel search to complete. The program uses the [pthread](https://man7.org/linux/man-pages/man7/pthreads.7.html) library for creating and managing threads.

## Program Structure

### Functions

- `void taskManager()`: Creates multiple threads to search for prime numbers in parallel.
- `void* searchPrime(void *args)`: Searches for prime numbers in a given range using a single thread.
- `void searchPrimeSerial()`: Searches for prime numbers sequentially.
- `bool isPrime(int number)`: Determines whether a given number is prime or not.

### Variables

- `threadCount`: The number of threads to use for searching prime numbers.
- `NUMBER_RANGE_MAX`: The maximum range for searching prime numbers.
- `pthread_t threads[]`: An array of pthread structures for managing threads.
- `int threadArgs[]`: An array of integers used to pass thread IDs to the `searchPrime` function.

## License

This program is released under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute the code as you wish.

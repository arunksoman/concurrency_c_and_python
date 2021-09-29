import time
import random
from typing import List

def calculate_prime_factors(n) -> List:
    prime_fac = []
    d = 2

    while d*d < n:
        while n % d == 0:
            prime_fac.append(d)
            n //= d
        d += 1
        if n > 1:
            prime_fac.append(n)
        return prime_fac

def main() -> None:
    print("Starting number crunching")
    t0 = time.time()
    for i in range(100000):
        rand = random.randint(20000, 100000000)
        print(f"Prime factors of {rand}:  {calculate_prime_factors(rand)}\n", file=open('a.txt', 'a'))
    t1 = time.time()
    totalTime = t1 - t0
    print(f"Execution Time: {totalTime}")

if __name__ == '__main__':
    main()

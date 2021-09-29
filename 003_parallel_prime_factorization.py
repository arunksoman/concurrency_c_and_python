import time
import random
from typing import List
from multiprocessing import Process
from threading import Thread
import sys


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

# We split our workload from one batch of 10,000 calculations
# into 10 batches of 1,000 calculations
def executeProc():
    for i in range(25000):
        rand = random.randint(20000, 100000000)
        with open('b.txt', 'a') as f:
            f.write(f"Prime factors of {rand}: {calculate_prime_factors(rand)}\n")
            if not f.buffer:
                f.flush()

def main() -> None:
    sys.setswitchinterval(0.005)
    print("Starting number crunching")
    t0 = time.time()
    num_of_process = 4
    procs = [0] * num_of_process
    for i in range(0, num_of_process):
        proc = Process(target=executeProc, args=())
        # proc =Thread(target=executeProc)
        procs[i] = proc
    # execution to finish for all of our processes
    for i in range(0, num_of_process):
        procs[i].start()
    for i in range(0, num_of_process):
        procs[i].join()
    t1 = time.time()
    totalTime = t1 - t0
    print(f"Execution Time: {totalTime}")

if __name__ == '__main__':
    main()

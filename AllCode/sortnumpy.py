import numpy as np
import time

for itest in range(1, 11) : 
    numTest = str(itest)
    numTest = "".join([numTest, ".inp"])

    with open(numTest, "r", encoding="utf-8") as file : 
        n = int(file.readline())
        a = list(map(float, file.readline().split()))

    start_time = time.perf_counter()
    a = np.array(a)
    a = np.sort(a)
    finish_time = time.perf_counter()

    print(f"Time {numTest} : {(finish_time - start_time):.5f}")
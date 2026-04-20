import time

def light():
    for i in range(100):
        time.sleep(0.003)

def medium():
    for i in range(10):
        time.sleep(0.03)

def heavy():
    time.sleep(0.3)


def main():
    light()
    medium()
    heavy()

import cProfile
import pstats


cProfile.run('main()','macro_profiling.stats')

stats = pstats.Stats('macro_profiling.stats')

stats.sort_stats('time').print_stats(3)


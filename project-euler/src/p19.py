import pandas as pd

dates = pd.date_range(start="01/01/1901", end="12/31/2000", freq="1D")

pred = lambda d: d.day == 1 and d.weekday() == 6

print(len([d for d in dates if pred(d)]))

from math import floor
def gps(s, x):
    if len(x) > 1:
        return floor(max([((x[i[0] + 1] - x[i[0]])/(s/3600)) for i in enumerate(x, 1) if not i[0] >= len(x) -1]))
    else:
        return 0

fl = gps(20, [0.0, 0.23, 0.46, 0.69, 0.92, 1.15, 1.38, 1.61])
print(fl)

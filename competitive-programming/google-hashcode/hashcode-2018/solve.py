import sys
from functools import reduce

import numpy as np

with open(sys.argv[1]) as file:
    R, C, F, N, B, T = list(map(int, file.readline().strip().split(" ")))

    RIDES = {}
    for i in range(N):
        a, b, x, y, s, f = list(map(int, file.readline().strip().split(" ")))
        RIDES[i] = {
            "start": (a, b),
            "finish": (x, y),
            "estart": s,
            "lfinish": f,
            "taken": False,
        }

    CARS = {
        i: {"pos": [0, 0], "time": 0, "done": False, "rides": [], "ignoring": []}
        for i in range(F)
    }

#######################################


# consider that each ride must be taken
def is_done():
    for r in range(N):
        if not RIDES[r]["taken"]:
            return False

    return True


# closest and not taken ride
def get_ride(car_idx, oot):
    closest = None
    dist = np.infty

    car = CARS[car_idx]

    for ride_idx, ride_info in RIDES.items():
        if ride_info["taken"]:
            continue

        if oot[(car_idx, ride_idx)]:
            continue

        cx, cy = car["pos"]
        rx, ry = ride_info["start"]

        d = abs(cx - rx) + abs(cy - ry)
        if d < dist:
            dist = d
            closest = ride_idx

    return [closest, dist]


def dist_to_dest(car, ride):
    cx, cy = car["pos"]
    rx, ry = ride["finish"]

    return abs(cx - rx) + abs(cy - ry)


def solve(solution):
    car = -1

    # oot(car, ride) = True <=> this car - ride assignment is not good
    oot = {(car, ride): False for car in range(F) for ride in range(N)}
    penalty = {car: 0 for car in range(F)}
    ignore = []

    while not is_done() or all(oot.values()) or len(ignore) == F:
        car = (car + 1) % F

        print(car)

        if car in ignore:
            continue

        # get_ride is the heuristic-based function
        # to select the next ride for this car
        ride, dist = get_ride(car, oot)

        # no other ride found
        if ride == None:
            oot[(car, ride)] = True
            ignore.append(car)
            continue

        # OPTIMIZABLE!!!
        if oot[(car, ride)]:
            ignore.append(car)
            continue

        # original params
        orig_ts = CARS[car]["time"]
        orig_pos = CARS[car]["pos"]

        # go to car
        CARS[car]["time"] += max(0, (dist - 1))
        CARS[car]["pos"] = RIDES[ride]["start"]

        estart = RIDES[ride]["estart"]
        lfinish = RIDES[ride]["lfinish"]  # OPTIMIZABLE!!!

        # if arrived early, wait
        if CARS[car]["time"] < estart:
            CARS[car]["time"] += estart - CARS[car]["time"]

        # go to destination
        dtd = dist_to_dest(CARS[car], RIDES[ride])
        CARS[car]["time"] += max(0, (dtd - 1))
        CARS[car]["pos"] = RIDES[ride]["finish"]

        if CARS[car]["time"] >= T:
            oot[(car, ride)] = True

            # restore
            CARS[car]["time"] = orig_ts
            CARS[car]["pos"] = orig_pos
        else:
            # assign ride
            CARS[car]["rides"].append(ride)
            RIDES[ride]["taken"] = True


def test():
    times = [CARS[car]["time"] for car in range(F)]

    rides = list(
        reduce(lambda a, b: a + b, [CARS[car]["rides"] for car in range(F)], [])
    )
    rides.sort()

    taken = [ride for ride in range(N) if RIDES[ride]["taken"]]

    print("exceeded T (must be []):", list(filter(lambda x: x > T, times)))

    if len(taken) == len(rides) == len(set(rides)) == N:
        print("No duplicate rides, all rides have been served")
    else:
        print("Duplicate rides found")

    print("#" * 50)


def write_output():
    with open(sys.argv[2], "wt") as file:
        for car in range(F):
            n = str(len(CARS[car]["rides"]))
            r = " ".join(list(map(str, CARS[car]["rides"])))

            file.write(n + " " + r + "\n")


if __name__ == "__main__":
    print("rides {}, cars {}, ts {}, grid {}x{}, bonus {}".format(N, F, T, R, C, B))

    out = solve(None)
    if out == {}:
        print("Something happened")

    # test()
    write_output()

    # for i in range(F):
    # 	print("car {}".format(i))
    # 	print("\t", CARS[i]['pos'])
    # 	print("\t", CARS[i]['time'])
    # 	#print("\t", CARS[i]['done'])
    # 	print("\t", CARS[i]['rides'])


"""
- consider rides that might give bonuses
- ignore rides that finish after lfinish
"""

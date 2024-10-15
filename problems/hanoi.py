def hanoi(n, from_rod, to_rod, via_rod):
    if n == 1:
        print(f"Move disk {n} from {from_rod} to {to_rod}")
    else:
        hanoi(n - 1, from_rod, via_rod, to_rod)
        print(f"Move disk {n} from {from_rod} to {to_rod}")
        hanoi(n - 1, via_rod, to_rod, from_rod)

# Main function
n = 3 # Number of disks (larger number represents a larger disk)
from_rod = 1  # Start rod
to_rod = 3    # Destination rod
via_rod = 2   # Auxiliary rod

# Calling hanoi() function
hanoi(n, from_rod, to_rod, via_rod)

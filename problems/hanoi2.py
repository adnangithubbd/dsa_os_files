def hanoi(n, from_rod, to_rod, via_rod):
    if n == 1:
        print(f"Move disk 1 from {from_rod} to {to_rod}")
    else:
        hanoi(n - 1, via_rod, to_rod, from_rod)
        print(f"Move disk {n} from {from_rod} to {to_rod}")
        hanoi(n - 1, from_rod, via_rod, to_rod)

# Main function
n = 3
from_rod = 'A'
to_rod = 'B'
via_rod = 'C'

# Calling hanoi() function
hanoi(n, from_rod, to_rod, via_rod)

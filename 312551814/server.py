import time

# Pause execution for 5 seconds
time.sleep(5)

# Open the 'server.txt' file
with open('server.txt') as f:
    lines = f.readlines()

# Iterate through each line in the file
for line in lines:
    l = line.strip()
    if not l:
        continue
    print(l)
    
    # Pause execution for 1 second
    time.sleep(1)

# Print two empty lines
print()
print()


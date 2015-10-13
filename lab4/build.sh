#!/bin/bash

echo "Building project..."

	g++ lab4.cpp wine.cpp -o lab4.out

	while true; do
		read -p "Execute the program now? " yn
		case $yn in
			[Yy]* ) ./lab4.out; break;;
			[Nn]* ) exit;;
			* ) exit;;
		esac
	done

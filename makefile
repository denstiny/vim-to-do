cc:
	g++ -g -w ./main/main.cpp -o todolist
	echo "Compile the complete"
install:
	sudo cp -f ./todolist /usr/bin/todolist
	echo "Install the complete"

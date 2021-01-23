cc:
	g++ -v -g -w ./main/main.cpp -o todolist
install:
	sudo cp -f ./todolist /usr/bin/todolist

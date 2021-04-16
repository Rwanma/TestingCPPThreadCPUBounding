GPP=/usr/bin/g++



debug:
	${GPP} test_thread.cpp DataStructure/*.cpp -o test_thread -pthread

clean:
	rm -rf test_thread

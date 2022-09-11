#include"my_queue.h"
#include<iostream>

struct point {
	int x = 3;
	int y = 5;
	int z = 4;
};

int main() {
	point p;
	my_queue<std::string> q;
	std::string a;
	try {
		 a = q.deque();
	}
	catch (MyException& e) {
		std::cerr << e.get();
	}
	q.enque("wef");
	q.enque("wegfweg");
	q.enque("ewg");
	q.enque("qqq");

	my_queue<point> pq;
	pq.enque(p);
	


	
	cout << q;
	return 0;
}
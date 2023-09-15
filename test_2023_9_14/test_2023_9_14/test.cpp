#include <vector>
#include <memory>
#include <iostream>
#include <mutex>
using namespace std;
template<typename T>
class CircularQueue{
public:
	CircularQueue(size_t capcity) : capcity(capcity), queue(capcity) {}

	bool push(T val) {
		std::lock_guard<std::mutex> lock(_mutex);
		if (count != capcity) {
			queue[tail] = std::make_unique<int>(val);
			tail++;
			if (tail == capcity)
				tail = 0;
			count++;
			return true;
		}
		return false;
	}

	bool pop() {
		std::lock_guard<std::mutex> lock(_mutex);
		if (count != 0) {
			head++;
			if (head == capcity)
				head = 0;
			count--;
			return true;
		}
		return false;
	}

	bool is_empty() {
		return count == 0;
	}

	bool is_full() {
		return count != 0;
	}

	std::unique_ptr<T> back() {
		T num = 0;
		if (count != 0) {
			int index = tail - 1;
			if (index == -1)
				index = capcity - 1;
			num = *(queue[index]);
		}
		return std::make_unique<T>(num);
	}

	std::unique_ptr<T> front() {
		T num = 0;
		if (count != 0) {
			num = *(queue[head]);
		}
		return std::make_unique<T>(num);
	}

private:
	std::mutex _mutex;
	size_t capcity = 0;
	std::vector<std::unique_ptr<T>> queue;
	size_t count = 0;
	size_t head = 0;
	size_t tail = 0;
};
int main() {

	CircularQueue<int> queue(3);

	//std::cout << queue.push(1) << std::endl; // 返回true
	//std::cout << queue.push(2) << std::endl; // 返回true
	//std::cout << queue.push(3) << std::endl; // 返回true
	//std::cout << queue.push(4) << std::endl; // 返回 false，队列已满
	//std::cout << *(queue.back()) << std::endl; // 返回 3
	//std::cout << queue.is_full() << std::endl; // 返回 true
	//std::cout << queue.pop() << std::endl; // 返回 true
	//std::cout << queue.push(4) << std::endl; // 返回 true
	//std::cout << *(queue.back()) << std::endl; // 返回 4

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	std::cout << *(queue.front()) << std::endl;
	queue.pop();
	std::cout << *(queue.front()) << std::endl;
	queue.pop();
	std::cout << *(queue.front()) << std::endl;
	queue.pop();
	std::cout << *(queue.front()) << std::endl;
	queue.pop();
	return 0;
}
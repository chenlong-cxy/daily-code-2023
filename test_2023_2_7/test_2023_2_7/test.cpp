#include <iostream>
#include <queue>
using namespace std;
class MovingAverage {
public:
	MovingAverage(int size)
		:_size(size)
		, _total(0)
	{}

	double next(int val) {
		if (_q.size() == _size)
		{
			_total -= _q.front();
			_q.pop();
		}
		_total += val;
		_q.push(val);
		return _total / _q.size();
	}
private:
	int _size;
	double _total;
	queue<int> _q;
};
int main()
{
	MovingAverage obj(3);
	cout << obj.next(1) << endl;
	cout << obj.next(10) << endl;
	cout << obj.next(3) << endl;
	cout << obj.next(5) << endl;
	return 0;
}

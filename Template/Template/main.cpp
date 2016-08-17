/*
템플릿(Template)이란, 말 그대로 "형틀"이라는 의미를 지니고 있습니다.
무엇을 찍어내는 틀, 비유하자면 붕어빵 틀에 비유할 수 있습니다.
템플릿은 모양, 틀을 본을 떠 놓은것이고, 집어 넣는 재료에 따라 결과가 조금씩 달라집니다.
붕어빵 역시도, 재료만 가지고 똑같은 모양으로 찍어낼 수 있으며, 넣는 재료에 따라 내용물은 조금씩 달라집니다.
이 템플릿은, 기능은 이미 결정되어 있으나 자료형이 정해지지 않는다는 특징을 지니고 있습니다.
*/

#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
	T data;
public:
	Data(T data) : data(data) { }
	void ShowInfo() {
		cout << data << endl;
	}
};

int main()
{
	Data<int> data1(50);
	data1.ShowInfo();

	Data<char> data2('A');
	data2.ShowInfo();

	Data<double> data3(24.377);
	data3.ShowInfo();
}
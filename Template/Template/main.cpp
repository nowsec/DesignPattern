/*
���ø�(Template)�̶�, �� �״�� "��Ʋ"�̶�� �ǹ̸� ���ϰ� �ֽ��ϴ�.
������ ���� Ʋ, �������ڸ� �ؾ Ʋ�� ������ �� �ֽ��ϴ�.
���ø��� ���, Ʋ�� ���� �� �������̰�, ���� �ִ� ��ῡ ���� ����� ���ݾ� �޶����ϴ�.
�ؾ ���õ�, ��Ḹ ������ �Ȱ��� ������� �� �� ������, �ִ� ��ῡ ���� ���빰�� ���ݾ� �޶����ϴ�.
�� ���ø���, ����� �̹� �����Ǿ� ������ �ڷ����� �������� �ʴ´ٴ� Ư¡�� ���ϰ� �ֽ��ϴ�.
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
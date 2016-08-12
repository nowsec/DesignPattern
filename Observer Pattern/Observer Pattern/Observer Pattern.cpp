///�ɼ��� ����(observer pattern)�� ��ü�� ���� ��ȭ�� �����ϴ� �����ڵ�, �� ���������� ����� ��ü�� ����Ͽ� ���� ��ȭ�� ���� ������
///�޼��� ���� ���� ��ü�� ���� ����� �� ���������� �����ϵ��� �ϴ� ������ �����̴�.
///�ַ� �л� �̺�Ʈ �ڵ鸵 �ý����� �����ϴ� �� ���ȴ�. ����/���� �𵨷� �˷��� �ֱ⵵ �ϴ�.

#include <iostream>

using namespace std;

class Observer{
	public :
		virtual void update(double s1, double s2, int s3) = 0;
};

class Subject{
	public :
		virtual void attach(Observer *o) = 0;
		virtual void detach(Observer *o) = 0;
		virtual void notify() = 0;
};

class ConcreteSubject : public Subject{
	private :
		double s1;
		double s2;
		int s3;
		Observer *objs[100];
		int index;

	public :
		ConcreteSubject() {
			index = 0;
		}

		virtual void attach(Observer *o){
			objs[index++] = o;
		}
		virtual void detach(Observer *o){
			for (int i = 0; i < index; i++){
				if (objs[i] == o){
					memmove(objs + i, objs + i + 1, sizeof(Observer)* (100 - i));
				}
			}
		}
		virtual void notify(){
			for (int i = 0; i < index; i++){
				objs[i]->update(s1, s2, s3);
			}
		}

		void setStatus(double s1, double s2, int s3)
		{
			this->s1 = s1;
			this->s2 = s2;
			this->s3 = s3;
		}
};

class ConcreteObserverA : public Observer{
	private :
		double s1;
		double s2;
		int s3;
		Subject *info;
	
	public :
		ConcreteObserverA(Subject *info){
			this->info = info;
			info->attach(this);
		}

		virtual void update(double s1, double s2, int s3){
			this->s1 = s1;
			this->s2 = s2;
			this->s3 = s3;
			cout << s1 << " & " << s2 << endl;
		}
};

class ConcreteObserverB : public Observer{
	private :
		double s1;
		double s2;
		int s3;
		Subject *info;
	public:
		ConcreteObserverB(Subject *info){
			this->info = info;
			info->attach(this);
		}
		
		virtual void update(double s1, double s2, int s3){
			this->s1 = s1;
			this->s2 = s2;
			this->s3 = s3;
			cout << s2 << " & " << s3 << endl;
		}
};

int main()
{
	ConcreteSubject * CS = new ConcreteSubject();
	Observer *o1 = new ConcreteObserverA(CS);
	Observer *o2 = new ConcreteObserverB(CS);
	CS->setStatus(400.5, 39.3, 9);
	CS->notify();
}

/*
1. ���� new�� �̿��ؼ� �����Ҵ��� �޾� ��ü�� �����ϴ� ������ �����ϱ�?
->  �� ����� ���̴� �޸��� ��� �ö󰡳��� �����̴�.
�����Ҵ��� ���� �ʰ� ��ü�� ������ ��� ���ÿ����� �ö󰡰� �ȴ�.
���ÿ����� �Ϲ����� ������ �ö󰡴� �������� ������ ��� ��� �޸𸮰� �ڵ����� �����ȴ�.
������ �����Ҵ��� �� ��� �������� �Ҵ�ް� delete�� �̿��Ͽ� ���� ������ ������ �ʱ� �������� �޸𸮿� �����ȴ�.
��, �Լ����� ��� ���� �ڵ����� ������Ű�� ���ؼ��� ���� �޸𸮸� �̿��Ͽ� ����ϵ��� �ϰ� ��� ����ϱ� ���ؼ��� ���޸𸮸� �̿��ؾ� �Ѵ�.
�� �޸𸮸� �̿��� ��� �޸� ������ �߻��� �� �����Ƿ� delete�� �̿��Ͽ� ������ ���־�� �Ѵ�.

2. �����Լ��� �� ����ϴ°�?
->	������ ����Լ��� �ڽ� Ŭ�������� �������̵��� �ϴ��� �θ� ��ü�� �����Ϳ��� ȣ���ϸ� �θ�Ŭ������ �Լ��� ȣ��ȴ�.
������ �����Լ��� ���� �Ǹ� �ڽ�Ŭ������ �Լ��� ȣ���� �ȴٴ� ���̴�.

*/
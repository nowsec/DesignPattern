///옵서버 패턴(observer pattern)은 객체의 상태 변화를 관찰하는 관찰자들, 즉 옵저버들의 목록을 객체에 등록하여 상태 변화가 있을 때마다
///메서드 등을 통해 객체가 직접 목록의 각 옵저버에게 통지하도록 하는 디자인 패턴이다.
///주로 분산 이벤트 핸들링 시스템을 구현하는 데 사용된다. 발행/구독 모델로 알려져 있기도 하다.

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
1. 굳이 new를 이용해서 동적할당을 받아 객체를 생성하는 이유는 무엇일까?
->  두 방법의 차이는 메모리의 어디에 올라가냐의 차이이다.
동적할당을 받지 않고 객체를 생성할 경우 스택영역에 올라가게 된다.
스택영역은 일반적인 변수가 올라가는 영역으로 범위를 벗어날 경우 메모리가 자동으로 해제된다.
하지만 동적할당을 할 경우 힙영역을 할당받고 delete를 이용하여 직접 해제를 해주지 않기 전까지는 메모리에 유지된다.
즉, 함수에서 잠깐 쓰고 자동으로 해제시키기 위해서는 스택 메모리를 이용하여 사용하도록 하고 계속 사용하기 위해서는 힙메모리를 이용해야 한다.
힙 메모리를 이용할 경우 메모리 누수가 발생할 수 있으므로 delete를 이용하여 해제를 해주어야 한다.

2. 가상함수를 왜 사용하는가?
->	보통의 멤버함수는 자식 클래스에서 오버라이딩을 하더라도 부모 객체의 포인터에서 호출하면 부모클래스의 함수가 호출된다.
하지만 가상함수를 쓰게 되면 자식클래스의 함수가 호출이 된다는 것이다.

*/
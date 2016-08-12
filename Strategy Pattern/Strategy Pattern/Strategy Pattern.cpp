/*
스트래티지 패턴 (strategy pattern)

스트래티지 패턴(Strategy pattern)에서는 알고리즘군을 정의하고 각각을 캡슐화하여 교환해서 사용할 수 있도록 만든다.
스트래티지를 활용하면 알고리즘을 사용하는 클라이언트와는 독립적으로 알고리즘을 변경할 수 있다.
상속을 이용한 간단한 동물의 행동을 호출하는 시스템에서 스트래티지 패턴(Strategy pattern)을 적용하여 보겠습니다.
*/

#include <iostream>

using namespace std;


class Strategy{
	public:
		virtual void execute() = 0;
};

class ConcreteStrategyA : public Strategy{
	public :
		virtual void execute(){
			cout << "ConcreteStrategyA's behavior" << endl;
		}
};

class ConcreteStrategyB : public Strategy{
	public :
		virtual void execute(){
			cout << "ConcreteStrategyB's behavior" << endl;
		}
};

class Context{
	private :
		Strategy * stg;
	public :
		void setStrategy(Strategy * stg){
			this->stg = stg;
		}
		void perForm(){
			stg->execute();
		}
};

int main()
{
	Context *S = new Context();
	Strategy *A = new ConcreteStrategyA();
	S->setStrategy(A);
	S->perForm();

	Strategy *B = new ConcreteStrategyB();
	S->setStrategy(B);
	S->perForm();
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
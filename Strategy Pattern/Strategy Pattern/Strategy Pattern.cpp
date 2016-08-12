/*
��Ʈ��Ƽ�� ���� (strategy pattern)

��Ʈ��Ƽ�� ����(Strategy pattern)������ �˰����� �����ϰ� ������ ĸ��ȭ�Ͽ� ��ȯ�ؼ� ����� �� �ֵ��� �����.
��Ʈ��Ƽ���� Ȱ���ϸ� �˰����� ����ϴ� Ŭ���̾�Ʈ�ʹ� ���������� �˰����� ������ �� �ִ�.
����� �̿��� ������ ������ �ൿ�� ȣ���ϴ� �ý��ۿ��� ��Ʈ��Ƽ�� ����(Strategy pattern)�� �����Ͽ� ���ڽ��ϴ�.
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
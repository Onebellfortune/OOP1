#include <iostream>
#include <cstring>
#define ARR_SIZE 100

using namespace std;

class Account {
private:
	int account;
	char* name;
	int balance;
public:
	Account(int aname, char* pname, int money)
	: account(aname),balance(money){
		int len = strlen(pname) + 1;
		name = new char[len];
		strcpy(name, pname);
	}

	void Deposit(int money) {
		balance += money;
	}
	
	void Withdraw(int money) {
		balance -= money;
	}

	void showAccountInfo() const {
		cout << "���¹�ȣ: " << account << endl;
		cout << "�̸�: " << name << endl;
		cout << "�ܾ�: " << balance << endl;
	}

	~Account() {
		delete[]name;
	}
};


/*typedef struct _accList {
	int numOfData;
	Account accArr[ARR_SIZE];
}accList;

typedef accList List;

void InitAcc(List* accList) {
	accList->numOfData = 0;
}
void MakeAccount(List* accList, int account, char* name, int balance) {
	Account tmp;
	tmp.account = account;
	strcpy(tmp.name, name);
	tmp.balance = balance;
	accList->accArr[accList->numOfData] = tmp;
	(accList->numOfData)++;
}

void Deposit(List* accList, int money , int idx) {
	int num = accList->numOfData;
	for (int i = 0; i < num; i++) {
		if (accList->accArr[i].account == idx) {
			(accList->accArr[i].balance) += money;
			break;
		}
	}
}
void Withdraw(List* accList, int money, int idx) {
	int num = accList->numOfData;
	for (int i = 0; i < num; i++) {
		if (accList->accArr[i].account == idx) {
			(accList->accArr[i].balance) -= money;
			break;
		}
	}
}
void SearchBalance(List* accList) {
	int num = accList->numOfData;
	for (int i = 0; i < num; i++) {
		cout << accList->accArr[i].name << " �� �ܾ�: " << accList->accArr[i].balance << endl;
	}
}*/

int main(void) {
	//List newAccount;
	//InitAcc(&newAccount);
	Account* accList[20];
	int input = -1;
	int i = 0;
	while (1) {
		cout << "1: ����  ����" << endl;
		cout << "2: �Ա�" << endl;
		cout << "3: ���" << endl;
		cout << "4: �������� ��ȸ" << endl;
		cout << "5: ���α׷� ����" << endl;
		cout << "�޴� �Է�: ";
		cin >> input;
		if (1 == input) {
			int num;
			char name[20];
			int money;
			cout << "���¹�ȣ: ";
			cin >> num;
			cout << "�̸�: ";
			cin >> name;
			cout << "�ݾ�: ";
			cin >> money;
			accList[i] =new Account(num, name, money);
			i++;
			//MakeAccount(&newAccount, num, name, money);
		}
		else if (2 == input) {
			int num;
			int money;
			cout << "�Ա��� ���¹�ȣ: ";
			cin >> num;
			cout << "�ݾ�: ";
			cin >> money;
			accList[num]->Deposit(money);
		}
		else if (3 == input) {
			int num;
			int money;
			cout << "����� ���¹�ȣ: ";
			cin >> num;
			cout << "�ݾ�: ";
			cin >> money;
			accList[num]->Withdraw(money);
		}
		else if (4 == input) {
			cout << "--���� ����--" << endl;
			for (int j = 0; j < i; j++) {
				accList[j]->showAccountInfo();
			}
			//SearchBalance(&newAccount);
		
		}else if(5==input){
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
	}
	return 0;
}


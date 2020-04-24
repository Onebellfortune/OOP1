#include <iostream>
#include <cstring>
#define ARR_SIZE 100

using namespace std;

typedef struct _account {
	int account;
	char name[20];
	int balance;
}Account;

typedef struct _accList {
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
}

int main(void) {
	List newAccount;
	InitAcc(&newAccount);
	int input = -1;
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
			MakeAccount(&newAccount, num, name, money);
		}
		else if (2 == input) {
			int num;
			int money;
			cout << "�Ա��� ���¹�ȣ: ";
			cin >> num;
			cout << "�ݾ�: ";
			cin >> money;
			Deposit(&newAccount, money, num);
		}
		else if (3 == input) {
			int num;
			int money;
			cout << "����� ���¹�ȣ: ";
			cin >> num;
			cout << "�ݾ�: ";
			cin >> money;
			Withdraw(&newAccount, money, num);
		}
		else if (4 == input) {
			cout << "--���� ����--" << endl;
			SearchBalance(&newAccount);
		
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


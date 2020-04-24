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
		cout << accList->accArr[i].name << " 의 잔액: " << accList->accArr[i].balance << endl;
	}
}

int main(void) {
	List newAccount;
	InitAcc(&newAccount);
	int input = -1;
	while (1) {
		cout << "1: 계좌  개설" << endl;
		cout << "2: 입금" << endl;
		cout << "3: 출금" << endl;
		cout << "4: 계좌정보 조회" << endl;
		cout << "5: 프로그램 종료" << endl;
		cout << "메뉴 입력: ";
		cin >> input;
		if (1 == input) {
			int num;
			char name[20];
			int money;
			cout << "계좌번호: ";
			cin >> num;
			cout << "이름: ";
			cin >> name;
			cout << "금액: ";
			cin >> money;
			MakeAccount(&newAccount, num, name, money);
		}
		else if (2 == input) {
			int num;
			int money;
			cout << "입금할 계좌번호: ";
			cin >> num;
			cout << "금액: ";
			cin >> money;
			Deposit(&newAccount, money, num);
		}
		else if (3 == input) {
			int num;
			int money;
			cout << "출금할 계좌번호: ";
			cin >> num;
			cout << "금액: ";
			cin >> money;
			Withdraw(&newAccount, money, num);
		}
		else if (4 == input) {
			cout << "--계좌 정보--" << endl;
			SearchBalance(&newAccount);
		
		}else if(5==input){
			break;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
	}
	return 0;
}


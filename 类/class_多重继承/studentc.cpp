#include"worker.h"
using std::cin;
using std::cout;
using std::endl;


Worker::~Worker() { cout << "I of Worker,do nothing.\n"; }

void Worker::Data()const {
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}
void Worker::Get() {
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
void Worker::Set() {
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
void Worker::Show()const {
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}

void Waiter::Data()const {
	cout << "Panache rating: " << panache << endl;
}
void Waiter::Get() {
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
void Waiter::Set() {
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}
void Waiter::Show()const {
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}

const char *Singer::pv[] = { "other","alto","contralto","soprano","bass","baritone","tenor" };
void Singer::Data()const {
	cout << "Vocal range: " << pv[voice] << endl;
}
void Singer::Get() {
	cout << "Enter number for singer's vocal range: \n";
	int i;
	for (i = 0; i < Vtypes; i++) {
		cout << i << ": " << pv[i] << "    ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Please enter a value>=0 and< " << Vtypes << endl;
	while (cin.get() != '\n')
		continue;
}
void Singer::Set() {
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
	
}
void Singer::Show()const {
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}

void SingingWaiter::Data()const {
	Waiter::Data();
	Singer::Data();
}
void SingingWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set() {
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show()const {
	cout << "Category:: singing waiter\n";
	Worker::Data();
	Data();
}
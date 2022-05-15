#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Connector {
public:
	// Конструктор. Получает параметром адрес, куда требуется подключиться.
	// Выполняет необходимую инициализацию соединения.
	// После завершения работы конструктора соединение установлено и готово к работе.
	// Если возникают какие-либо проблемы - выбрасывает exception с описанием проблемы.
	Connector(const string& address) {
	}

	// Отправить по установленному соединению сообщение, текст сообщения передаётся в параметре data.
	// Если возникают какие-либо проблемы - выбрасывает exception с описанием проблемы.
	void sendRequest(const string& data) {
	}
};

int main(){
	unsigned int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string adress;
		cin >> adress;

		try {
			Connector s(adress);
		}

		catch(const std::exception& ex){
			cout << ex.what() << endl;
		}

		try {
			s.sendRequest("Hello");
		}

		catch(const std::exception& ex){
			cout << ex.what() << endl;
		}

	}

	return 0;
}

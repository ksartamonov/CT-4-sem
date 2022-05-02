#include <iostream>
#include <set>

using namespace std;

class SessionManager
{
private:
    set <string> _users;
public:
// Вход пользователя.
// Один пользователь может войти несколько раз подряд, // считать его при этом нужно один раз.
    void login(const string& username) {
        _users.insert(username);
    }
    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд,
    // падать при этом не нужно.
    void logout(const string& username) {
        _users.erase(username);
    }
    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers() const {
        return _users.size();
    }
};

int main() {
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;
}

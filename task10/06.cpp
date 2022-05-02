#include <iostream>
#include <map>
#include <set>

using namespace std;

class Tracker
{
private:
    map<string, set<unsigned long long> > _users; // каждому пользователю в соответствие сет из времен
public:
// При любом действии пользователя вызывается этот метод.
// Методу передаётся:
// - какой пользователь совершил действие (username);
// - когда (timestamp - для простоты условные секунды от начала времён).
// Внимание: не гарантируется, что timestamp расположены строго по
// возрастанию, в них может быть любой бардак.
    void click(const string& username, unsigned long long timestamp) {
        _users[username].insert(timestamp);
    }
// По имени пользователя нужно вернуть, сколько всего было кликов
    unsigned long long getClickCount(const string& username) const {
        return _users.at(username).size();
    }
    // Когда был первый клик
    unsigned long long getFirstClick(const string& username) const {
        auto it = _users.at(username).begin();
        return *it;
    }
// Когда был последний клик
    unsigned long long getLastClick(const string& username) const {
        auto it = _users.at(username).rbegin();
        return *it;
    }
};

int main() {
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);
    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;
}

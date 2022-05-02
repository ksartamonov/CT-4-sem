// Артамонов Кирилл
#include <iostream>
#include <vector>

using namespace std;

bool comp(int x, int y) {
    return x > y;
}

class ResultsTable
{
private:
    vector <uint> _scores;
public:
    ResultsTable() {}
// Зарегистрировать новый результат,
// нас волнуют только баллы, имена пользователей не важны
    void addResult(unsigned int score) {
        _scores.push_back(score);
        sort(_scores.begin(), _scores.begin() + _scores.size(), comp);
}
    // Получить минимальный балл из всех результатов за всё время
    unsigned int getMinScore() const {
        return _scores[_scores.size() - 1];
    }
    // Получить, сколько баллов у игрока на заданном месте.
    // Внимание: места нумеруются так, как это принято на турнирах, то есть // лучший результат - 1-ое место, за ним 2-ое место и т.д.
    unsigned int getScoreForPosition(unsigned int positionNumber) const {
        return _scores[positionNumber - 1];
    }

};

int main() {
    ResultsTable t;
    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);

    cout << "1st place score: " << t.getScoreForPosition(1) << endl;
    cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
    cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
    cout << "Min score during the tournament: " << t.getMinScore() << endl;

    return 0;
}

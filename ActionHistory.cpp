#include "ActionHistory.h"
#include <iostream>

using namespace std; // Добавляем эту строку

void ActionHistory::addAction(ActionType type, const std::string& itemData) {
    actions.push({ type, itemData });
}

bool ActionHistory::undoLastAction() {
    if (actions.empty()) {
        cout << "Нет действий для отмены.\n"; 
        return false;
    }

    Action lastAction = actions.top();
    actions.pop();

    switch (lastAction.type) {
    case ADD_ITEM:
        cout << "Отмена добавления предмета: " << lastAction.itemData << "\n";
        // Логика для удаления предмета
        break;
    case REMOVE_ITEM:
        cout << "Отмена удаления предмета: " << lastAction.itemData << "\n"; 
        // Логика для восстановления предмета
        break;
    case EDIT_ITEM:
        cout << "Отмена редактирования предмета: " << lastAction.itemData << "\n";
        // Логика для восстановления состояния предмета
        break;
    }
    return true;
}

// Метод для проверки наличия действий для отмены
bool ActionHistory::canUndo() const {
    return !actions.empty();
}
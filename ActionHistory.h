#pragma once
#include <stack>
#include <string>

// Определяем возможные действия
enum ActionType {
    ADD_ITEM,
    REMOVE_ITEM,
    EDIT_ITEM
};

// Структура для хранения информации об действии
struct Action {
    ActionType type;
    std::string itemData; // Данные предмета (например, строка, представляющая предмет)
};

class ActionHistory {
private:
    std::stack<Action> actions; // Стек для хранения действий

public:
    // Метод для добавления действия
    void addAction(ActionType type, const std::string& itemData);

    // Метод для отмены последнего действия
    bool undoLastAction();

    // Метод для проверки наличия действий для отмены
    bool canUndo() const;
};
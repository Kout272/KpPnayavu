#include "ActionHistory.h"
#include <iostream>

using namespace std; // ��������� ��� ������

void ActionHistory::addAction(ActionType type, const std::string& itemData) {
    actions.push({ type, itemData });
}

bool ActionHistory::undoLastAction() {
    if (actions.empty()) {
        cout << "��� �������� ��� ������.\n"; 
        return false;
    }

    Action lastAction = actions.top();
    actions.pop();

    switch (lastAction.type) {
    case ADD_ITEM:
        cout << "������ ���������� ��������: " << lastAction.itemData << "\n";
        // ������ ��� �������� ��������
        break;
    case REMOVE_ITEM:
        cout << "������ �������� ��������: " << lastAction.itemData << "\n"; 
        // ������ ��� �������������� ��������
        break;
    case EDIT_ITEM:
        cout << "������ �������������� ��������: " << lastAction.itemData << "\n";
        // ������ ��� �������������� ��������� ��������
        break;
    }
    return true;
}

// ����� ��� �������� ������� �������� ��� ������
bool ActionHistory::canUndo() const {
    return !actions.empty();
}
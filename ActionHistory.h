#pragma once
#include <stack>
#include <string>

// ���������� ��������� ��������
enum ActionType {
    ADD_ITEM,
    REMOVE_ITEM,
    EDIT_ITEM
};

// ��������� ��� �������� ���������� �� ��������
struct Action {
    ActionType type;
    std::string itemData; // ������ �������� (��������, ������, �������������� �������)
};

class ActionHistory {
private:
    std::stack<Action> actions; // ���� ��� �������� ��������

public:
    // ����� ��� ���������� ��������
    void addAction(ActionType type, const std::string& itemData);

    // ����� ��� ������ ���������� ��������
    bool undoLastAction();

    // ����� ��� �������� ������� �������� ��� ������
    bool canUndo() const;
};
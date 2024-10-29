#include <iostream>
#include <format>
using namespace std;

struct node { // Структура для создания списка 
    int value;
    node* p_next;

    node(int x) {
        value = x;
        p_next = nullptr;
    }
};

void ListAppend(node** head, int x) { // Функция добавления в наш список
    node* new_elem = new node(x); // Инициализация нового элемента, которого мы хотим добавить
    // Проверку на пустотту списка
    if (*head == nullptr) { // Если список пуст
        *head = new_elem;
    }
    else { // Если что-то есть
        node* p_last = *head;
        while (p_last->p_next != nullptr) { // Перебор значений нашего списка
            p_last = p_last->p_next;
        } // Дошли до конца
        p_last->p_next = new_elem; // Добавили элемент в конец 
    }
}

void ListPrint(node* head) {
    node* p_last = head;
    while (p_last != nullptr) { // Перебор значений нашего списка
        std::cout << p_last->value << " -> ";
        p_last = p_last->p_next;
    } // Дошли до конца
    std::cout << "nullptr\n";
}

node* ListIntersection(node* L1, node* L2) { // Поиск пересечения L1 и L2
    node* L3 = nullptr; // Корень списка
    node** next = &L3; // Последующий эл

    for (node* l1 = L1; l1 != nullptr; l1 = l1->p_next) { // Пробегаемся по всем значениям L1
        for (node* l2 = L2; l2 != nullptr; l2 = l2->p_next) { // Пробегаемся по всем значениям L2
            if (l1->value == l2->value) {
                *next = new node(l1->value);
                next = &(*next)->p_next;
                break;
            }
        }
    }
    return L3; // Возврат адреса на начало списка с пересечением двух списков L1 и L2
}

void ListInsert(node** L2, node* L1, int anchor) { // Вставка одного списка в дргугой
    node* inserted_list = *L2;
    while (inserted_list != nullptr && inserted_list->value != anchor) {
        inserted_list = inserted_list->p_next;
    }

    if (inserted_list != nullptr) {
        node* l1 = nullptr;
        node** next = &l1;
        for (node* n = L1; n != nullptr; n = n->p_next) {
            *next = new node(n->value);
            next = &(*next)->p_next;
        }

        *next = inserted_list->p_next;
        inserted_list->p_next = l1;
    }
}

void ListRemoveEvenNumbers(node** L) { // Удаление чётных чисел из списка
    node* current = *L;
    node* p_prev = nullptr;

    while (current != nullptr) {
        if (current->value % 2 == 0) {
            if (p_prev == nullptr) {
                *L = current->p_next;
            }
            else {
                p_prev->p_next = current->p_next;
            }
            node* del = current;
            current = current->p_next;
            delete del;
        }
        else {
            p_prev = current;
            current = current->p_next;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    node* L1 = nullptr;
    node* L2 = nullptr;

    // Инициализация L1
    ListAppend(&L1, 1);
    ListAppend(&L1, 2);
    ListAppend(&L1, 3);
    ListAppend(&L1, 4);
    ListAppend(&L1, 5);
    ListAppend(&L1, 6);

    // инициализация L2
    ListAppend(&L2, 1);
    ListAppend(&L2, 2);
    ListAppend(&L2, 2);
    ListAppend(&L2, 3);
    ListAppend(&L2, 3);
    ListAppend(&L2, 4);
    ListAppend(&L2, 4);
    ListAppend(&L2, 5);

    std::cout << "L1:\n";
    ListPrint(L1);

    std::cout << "\nL2:\n";
    ListPrint(L2);

    node* L3 = ListIntersection(L1, L2);
    std::cout << "\nL3:\n";
    ListPrint(L3);

    ListInsert(&L2, L1, 2);
    std::cout << "\nВставим L1 в L2 после элемента со значением 2:\n";
    ListPrint(L2);

    ListRemoveEvenNumbers(&L1);
    std::cout << "\nУдаление всех чётных чисел из L1:\n";
    ListPrint(L1);

    return 0;
}
#include <iostream>

struct LinearList
{
    int data;
    LinearList* Next;
};

LinearList* head = new LinearList();
LinearList* stackTop = NULL;
int count = 0;

void ListInit()
{
    head->data = 0;
    head->Next = NULL;
    stackTop->data = 0;
    stackTop->Next = NULL;
}
bool IsEmpty()
{
    if (head->Next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool stackIsEmpty()
{
    if (stackTop == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void AddElement(int index)
{
    LinearList* Node = new LinearList();
    Node->data = rand() % 101;

    if (IsEmpty())
    {
        std::cout << "Ваш список пуст! Но сейчас мы это исправим!\n";
        head->Next = Node;        
        Node->Next = NULL;
        count++;
    }
    else if(index>count)
    {
        std::cout << "Ваш индекс больше, чем ко-во элементов списка. Добавил в конец\n";
        LinearList* ptr = head; 
        do
        {
            ptr->data;
            ptr = ptr->Next;
        } while (ptr->Next != NULL);

        ptr->Next = Node;
        Node->Next = NULL;
        count++;
    }
    else
    {
        int counter = 0;
        LinearList* ptr = head;
        while (counter < index)
        {
            ptr = ptr->Next;
            counter++;
        }
        Node->Next = ptr->Next;
        ptr -> Next = Node;
        count++;
    }
}
void ShowList()
{
    if (IsEmpty())
    {
        std::cout << "Список пуст\n";
        return;
    }
    LinearList* ptr = head->Next; // создаем копию, чтобы не портить текущую вершину
    std::cout << "Ваш список:\n";
    do
    {
        std::cout << ptr->data << " ";
        ptr = ptr->Next;
    } while (ptr != NULL);
    std::cout << std::endl << std::endl;
}
void ShowStack()
{
    if (stackIsEmpty())
    {
        std::cout << "Стек пуст" << std::endl;
    }
    else
    {
        LinearList* ptr = stackTop; // создаем копию, чтобы не портить текущую вершину
        std::cout << "Ваш стек:\n";
        do
        {
            std::cout << ptr->data << std::endl;
            ptr = ptr->Next;
        } while (ptr != NULL);

    }
}

void pop(int index)
{
    
    if (IsEmpty())
    {
        std::cout << "Ваш список пуст!\n";
        return;
    }
    int counter = 0;
    LinearList* Node = head;

    while (counter < index)
    {
        Node = Node->Next;
        counter++;
    }
    LinearList* ptr = Node->Next;
    Node->Next = (Node->Next)->Next;    
    (ptr)->Next = stackTop;
    stackTop = ptr;
    
    
    
}

char chariput()
{
    char iput;
    while ((!(std::cin >> iput) || (std::cin.peek() != '\n')))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "ошибка!" << std::endl;
    }
    return iput;
}
int intiput()
{
    int iput;
    while ((!(std::cin >> iput) || (std::cin.peek() != '\n')))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "ошибка!" << std::endl;
    }
    return iput;
}



int main()
{    
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    char choice;
    int index;
    bool working = true;

    while (working)
    {
        std::cout
            << "Введите, что вы хотите сделать:\n"
            << "1)Добавить элемент\n"
            << "2)Удалить элемент\n";

        choice = chariput();

        switch (choice)
        {
        case '1':
            std::cout << "Введите индекс\n";
            index = intiput();
            AddElement(index);
            ShowList();
            break;
        case '2':
            std::cout << "Введите индекс\n";
            index = intiput();
            pop(index);
            ShowList();
            ShowStack();
            break;

        default:
            std::cout << "Работа цикла завершена!\n";
            working = false;
            break;
        }
    }
    return 0;
}



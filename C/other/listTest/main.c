#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/*
Создайте структуру односвязного списка для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами:
* addElemHead – добавление элемента в голову;
* addElemTail – добавление элемента в хвост;
* delElemHead – удаление элемента из головы;
* delElemTail – удаление элемента из хвоста;
* delAll – удаление всех элементов;
* listOutput – отображение всех элементов списка на экран
*/

struct LIST
{
    int fieldData;
    struct LIST* ptrNextElem;
};

struct LIST* initialization(const int value);
struct LIST* addElemHead(struct LIST* list, const int value);
struct LIST* addElemTail(struct LIST* list, const int value);
struct LIST* delElemHead(struct LIST* list);
struct LIST* delElemTail(struct LIST* list);
struct LIST* delALL(struct LIST* list);
void listOutput(struct LIST* list);

int main()
{
    struct LIST* list = NULL;

    list = initialization(5);
    list = addElemHead(list, 7);
    list = addElemHead(list, 9);
    list = addElemHead(list, 11);
    list = addElemHead(list, 13);
    list = addElemTail(list, 3);
    list = addElemTail(list, 1);
    list = addElemTail(list, -1);
    list = addElemTail(list, -3);
    listOutput(list);
    list = delElemTail(list);

    list = delElemHead(list);
    listOutput(list);
    list = delALL(list);
    listOutput(list);
    _getch();
    return 0;
}
// инициализация списка
struct LIST* initialization(const int value)
{
    struct LIST* ptrRootList;

    ptrRootList = (struct LIST*)malloc(sizeof (struct LIST));
    ptrRootList->fieldData = value;
    ptrRootList->ptrNextElem = NULL;

    return (ptrRootList);
}
// добавление элемента в начало списка
struct LIST* addElemHead(struct LIST* list, const int value)
{
    struct LIST *nodeCreated;

    nodeCreated = (struct LIST*)malloc(sizeof(struct LIST));
    nodeCreated->fieldData = value;
    nodeCreated->ptrNextElem = list;

    return (nodeCreated);
}
// удаление элемента из начала списка
struct LIST* delElemHead(struct LIST* list)
{
    struct LIST* ptrRootList;

    ptrRootList = list->ptrNextElem;
    free(list);
    list = ptrRootList;

    return list;
}
// добавление элемента в конец списка
struct LIST* addElemTail(struct LIST* list, const int value)
{
    struct LIST* ptrList;
    struct LIST* ptrLastElemList;
    struct LIST* nodeCreated;

    ptrList = list;

    do
    {
        ptrLastElemList = ptrList;
        ptrList = ptrList->ptrNextElem;
    }while(ptrList != NULL);

    nodeCreated = (struct LIST*)malloc(sizeof(struct LIST));
    nodeCreated->fieldData = value;
    nodeCreated->ptrNextElem = NULL;
    ptrLastElemList->ptrNextElem = nodeCreated;

    return list;
}
// удаление элемента из конца списка
struct LIST* delElemTail(struct LIST* list)
{
    struct LIST* ptrList;
    struct LIST* ptrLastElemList;

    ptrList = list;
    do
    {
        ptrLastElemList = ptrList;
        ptrList = ptrList->ptrNextElem;
    }while(ptrList->ptrNextElem != NULL);

    free(ptrLastElemList->ptrNextElem);
    ptrLastElemList->ptrNextElem = NULL;

    return list;
}
// вывод элементов списка
void listOutput(struct LIST* list)
{
    struct LIST* ptrList = NULL;
    int index = 0;

    if(list == NULL)
        printf_s("%s\n", "list is empty");
    else
    {
        ptrList = list;

        do
        {
            ++index;
            printf_s("%s%i%s%i\n", "value ", index, " list element: ", ptrList->fieldData);
            ptrList = ptrList->ptrNextElem;
        }while(ptrList != NULL);
    }
    printf_s("%s\n", "list output complete");
}
// удаление всех элементов списка
struct LIST* delALL(struct LIST* list)
{
    struct LIST* ptrRoot;

    while(list != NULL)
    {
        ptrRoot = list;
        list = list->ptrNextElem;
        free(ptrRoot);
    }

    return list;
}

/*
    //printf_s("%p\n", ptrLastElemList); _getch();
    //ptrLastElemList->ptrNextElem = NULL;
    //free(ptrLastElemList);
    //ptrList = ptrLastElemList - sizeof (struct LIST);
    printf_s("\nENTER: ""%p\n", ptrLastElemList); _getch();
    printf_s("\nENTER: ""%i\n", ptrLastElemList->fieldData); _getch();
*/
/*
if(index == 8)
{
    printf_s("BEGIN\n");
    printf_s("%p\n", ptrList);
    _getch();
    printf_s("%i\n", ptrList->fieldData);
    _getch();
    printf_s("END\n");
}
*/

/*
void delALL(struct LIST* list)
{
    struct LIST* ptrRoot;
    int index = 0;
    ptrRoot = list->ptrNextElem;

    while(list != NULL)
    {
        ++index;
        free(list);
        printf_s("%i\n", index);
        list = ptrRoot;
        ptrRoot = list->ptrNextElem;
    }

    printf_s("%p\n", list); _getch();
    list = NULL;
}
*/

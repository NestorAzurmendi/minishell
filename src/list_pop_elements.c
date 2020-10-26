#include "minishell.h"

void    pop_front(List *list) // eliminar el primer elemento de la lista
{
    Node *pop = list->first; // guardamos la primera posicion a borrar
    if (list->first != NULL)
    {
        list->first = list->first->next; // le damos la siguiente posicion a la lista
        destructor_node(pop); // borramos la primera
        list->size--;
    }
}

void    pop_back(List *list) // eliminar ultimo elemento de la lista
{
    Node *pop = list->first;
    Node *previous_position = NULL;

    if (list->first != NULL)
    {
        if (list->size > 1)
        {
            while (pop->next != NULL) // recorre la lista
            {
                previous_position = pop; // le da el valor de pop
                pop = pop->next; // en pop le da el siguiente valor
            }
            previous_position->next = NULL; // cuando llega al final, pop tendra la ultima posicion y previous_position la anterior.
            destructor_node(pop); // borramos la ultima posicion, asi que previous pasa a ser la ultima y previous->next apunta a null pq no hay nada despues
            list->size--;
        }
        else // si el size es 1
        {
            list->first = NULL; // igualamos a null la primera posicion
            destructor_node(pop); // borramos pop, que estaba igualado a list->first al principio
            list->size--;
        }
    }
}

void    pop_n_element(List *list, int n) // borrar el n elemento de la lista
{
    Node    *pop = list->first;
    Node    *previous_position = NULL;
    int     i;
    if (list->first != NULL)
    {
        if (n == 0) // si n es la primera posicion hacemos pop_front
            pop_front(list);
        else if (n < list->size) // si n es menor que el tamaño de la lista
        {
            i = 0;
            while (i < n) // recorremos la lista
            {
                previous_position = pop;
                pop = pop->next;
                i++;
            }
            if (i == n)
            {
                previous_position->next = pop->next; // le decimos que la siguiente posicion va a ser la siguiente de la borrada
                destructor_node(pop); // borramos la posicion
                list->size--;
            }
        }
    }
}

int     compare_element_c(char * s, char c)
{
    while (*s)
    {
        if (*s == c)
        {
            return (1);
        }
        s++;
    }
    return (0);
}

List    *copy_list(List *list)
{
    List *copy;
    Node *iterator;

    copy = new_list();;
    iterator = list->first;
    while (iterator != NULL)
    {
        push_back(copy, iterator->element);
        iterator = iterator->next;
    }
    return (copy);
}
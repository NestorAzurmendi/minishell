#include "minishell.h"

void    push_front(List *list, char *s)
{
    Node *new = new_node(s);
    new->next = list->first;
    list->first = new;
    list->size++;
}

void    push_back(List *list, char *s)
{
    Node *new = new_node(s);
    Node *iterator = NULL;


    if (list->first == NULL) // si la lista esta vacía colocamos el nuevo nodo al principio
        list->first = new;
    else
    {
        iterator = list->first; // si no esta vacía, colocamos el iterador al principio de la lista
        while (iterator->next != NULL) // recorremos la lista hasta que iterator->next sea igual a null, por tanto, la ultima posicion
            iterator = iterator->next;
        iterator->next = new; // igualamos la ultima posicion con nuestro nuevo nodo
    }
    list->size++;
	//no se si liberar nodes aqui.
}

void    push_after_n(List *list, char *s, int n)
{
    Node    *new = new_node(s);
    Node    *iterator = NULL;
    int     i;

    if (list->first == NULL)
        list->first = new;
    else
    {
        iterator = list->first;
        i = 0;
        while (iterator->next != NULL && i < n) // recorremos la lista
        {
            iterator = iterator->next;
            i++;
        }
        new->next = iterator->next; // le decimos que la siguiente posicion va a ser la actual de la lista
        iterator->next = new; // y en la actual colocamos el nodo
    }
    list->size++;
}

char    *get_element(List *list, int n) // devuelve el char * del nodo
{
    Node    *iterator = NULL;
    int     i;

    if (list->first == NULL) // si la lista esta vacia, devuelve null
        return (NULL);
    else
    {
        i = 0;
        iterator = list->first;
        while (iterator->next != NULL && i < n) // recorre la lista
        {
            iterator = iterator->next;
            i++;
        }
        if (i != n)
            return (NULL); // si al acabar el while, i es diferente a n, quiere decir que no existe el nodo, por tanto devuelve null
        else
            return (iterator->element); // si ha encontrado el nodo, devuelve la palabra
    }
}

/*void    modify_element(List *list, char *s, int n) // modifica la palabra del nodo en la lista
{
    Node    *iterator = NULL;
    int     i;
    int     sign;

    sign = compare_element_c(s, '=');
    if (sign == 1)
    {
        if (n < list->size && list->first != NULL)
        {
            iterator = list->first;
            i = 0;
            while (i < n)
            {
                iterator = iterator->next;
                i++;
            }
            free(iterator->element);
            iterator->element = ft_strdup(s);
        }
    }
}*/


/**
* description: delete the first node
* Return: head's data(n)
*/
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int data;
    if (!*head)
        return 0;
    
    temp = *head;
    *head = (*head).next;
    data = temp.n;
    free(temp);

    return (data);
}

int pop_listint(listint_t **head)
{
    listint_t *current = *head;

    if (!current)
        return (0);

    while (current->next->next)
        current = current->next;

    
    free(current->next);
    current->next = NULL;
}

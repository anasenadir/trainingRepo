

void free_listint(listint_t **head)
{
    listint_t *temp = *head;

    while (temp)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
}

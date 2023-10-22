

size_t print_listint(const listint_t *head)
{
    const listint_t *current = head;
    int len = 0;

    while (current)
    {
        _putchar(current->n);
        current = current->next;
        len++;
    }

    return (len);
}


listint_t *add_nodeint(listint_t **h, const int n)
{
    listint_t * new_node = malloc(sizeof(listint_t));
    listint_t *current = (*h);

    if (!new_node || !h)
        return (NULL);

    new_node->n = n;


    if (!current)
        *h = new_node;
    else
    {
        while (current->next)
            current = current->next;

        current->next = new_node;
    }

    return (new_node);
}

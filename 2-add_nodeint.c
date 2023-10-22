/**
* add a new node at the begining of the list
*/


listint_t *add_nodeint(listint_t **h, const int n)
{
    listint_t * new_node = malloc(sizeof(listint_t));

    if (!new_node || !h)
        return (NULL);

    new_node->next = NULL;
    new_node->n = n;

    if (*h)
        new_node->next = *h;

    *h = new_node;
    return (new_node);
}


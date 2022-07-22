    for (int i; i < n - 2; i++)
    {
        printf("%d\n", head->num);
        head = head->next;
    }
    for (int i; i < n - 2; i++)
    {
        printf("%d\n", tail->num);
        tail = tail->prev;
    }
}
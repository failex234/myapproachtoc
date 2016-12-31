    if (!strcmp(action, "a")) goto add;
    else
    if (!strcmp(action, "s")) goto sub;
    else
    if (!strcmp(action, "d")) goto div;
    else
    if (!strcmp(action, "m")) goto mul;
    else goto question;
    add:
	    mul:
        return;
    div:
        return;
    sub:
        return;
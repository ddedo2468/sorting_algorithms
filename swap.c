/**
 * swap - swaping 2 elements of an array
 * @a: an element to swap with b
 * @b: an element to swap with a
 */

void swap(int *a, int *b)
{       
        int tmp;
        
        
        tmp = *a;
        *a = *b;
        *b = tmp;
}

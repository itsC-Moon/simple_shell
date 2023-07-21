#include "shell.h"
/**
 * _realloc - reallocate a new size memory and its return a new pointer
 * @oldptr: old pointer
 * @oldsize: old pointer size
 * @newsize: new pointer size
 * Return: new alloacte space
 */
void *_realloc(void *oldptr, int oldsize, int newsize)
{
	char *newPtr;
	int i;

	if (!oldptr)
		return (malloc(newsize));
	if (oldsize >= newsize)
		return (oldptr);
	newPtr = malloc(newsize);
	if (!newPtr)
		return (NULL);
	for (i = 0; i < oldsize; i++)
		newPtr[i] = ((char *)oldptr)[i];
	free(oldptr);
	return (newPtr);
}

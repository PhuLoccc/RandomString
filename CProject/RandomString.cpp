#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MIN 48
#define MAX 122
/// random string for the given length


//check the genterated character is a character or not 
bool isChar(char character)
{
	if (character >= 48 && character <= 57 || character >= 65 && character <= 90 || character >= 97 && character <= 122)
	{
		return true;
	}
	return false;
}
//random a character
char randomChar() 
{
	return (char) MIN + rand() % (MAX - MIN + 1);
}

//random string
char* randomString(int length)
{
	char* string = new char[length + 1]; //should use length + 1 to assign '\0' at the end of string
	for (int i = 0; i < length; i++)
	{
		char character = 0;
		do
		{
			character = randomChar();
		} while (!isChar(character)); // if the chacracter is false, we have to generate again until it's true
		string[i] = character;
	}
	string[length] = '\0';
	return string;
}

void main()
{
	srand(time(0));
	char* string = NULL;
	int length = 0;
	printf("enter string's length: ");
	scanf("%d", &length);
	printf("starting creating random string\n");
	for (int i = 0; i < 100; i++)
	{
		string = randomString(length);
		printf("%d. %s\n", i+1, string);
		delete[] string;
		string = NULL;
	}
	system("pause");
}
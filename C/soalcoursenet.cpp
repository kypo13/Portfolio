#include <stdio.h>
int main()
{
	int b,c,d,n;
	char a;
	printf("Input an Alphabet :");
	scanf("%c",&a);
	if ((a>='A'&&a<='Z')&&(a>='a'&&a<='z')){
		
		if (a=='A'||a=='a'||a=='e'||a=='E'||a=='i'||a=='I'||a=='u'||a=='U'||a=='o'||a=='O') printf("%c is vocal Alphabet",a);
		else printf("%c is Alphabet",a);}
	else printf("%c is not Alphabet",a);
	return 0;
}

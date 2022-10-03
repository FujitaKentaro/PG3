#include <stdio.h>
template <typename Type1>
Type1 Min(Type1 a, Type1 b) {
	if (a >= b) {
		return static_cast<Type1>(a);
	}

	return static_cast<Type1>(b);
}
template <>
char Min<char>(char a, char b) {
	
	return printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n");
}

int main() {
	printf("%d\n", Min<int>(114, 51));
	printf("%f\n", Min<float>(11.4f, 51.4f));
	printf("%f\n", Min<double>(11.4, 51.4));
	printf("%c\n", Min<char>('ABC', 51.4));

	return 0;
}
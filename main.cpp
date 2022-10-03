#include <stdio.h>
template <typename Type1, typename Type2>
Type1 add(Type1 a, Type2 b) {
	return a + b;
}

template <>
float add<float>(float a, float b) {
	return a - b;
}

float add(float a, float b) {
	return a * b;
}

int main() {
	printf("%d\n", add<int>(114, 51.4f));
	printf("%f\n", add<float>(11.4f, 51.4f));
	printf("%f\n", add(11.4f, 51.4f));

	return 0;
}
#include<iostream>
using namespace std;
// variadic templates involve always some form of recursion
// they are used as last args of function, but at compile time
// very high amount of code can be generated due to this
// but still its very powerful feature in cpp
void print() {
    cout << endl;
}

template <typename T>
void print(const T& t) {
    cout << t << endl;
}

template <typename First, typename... Rest> // template parameter pack
void print(const First& first, const Rest&... rest) {
	// function parameter pack
	constexpr auto numargs{ sizeof...(Rest) };
	cout <<"\nhere "<< numargs << " args were given to function generated\n";
    cout << first << ", ";
    print(rest...); // recursive call using pack expansion syntax
}

int main()
{
    print(); // calls first overload, outputting only a newline
    print(1); // calls second overload

    // these call the third overload, the variadic template,
    // which uses recursion as needed.
    print(10, 20);
    print(100, 200, 300);
    print("first", 2, "third", 3.14159);
}
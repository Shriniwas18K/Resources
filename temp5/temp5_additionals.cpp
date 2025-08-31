#include<iostream>
#include "temp5_additionals.hpp"

int sum(int a,int b){
	std::cout<<"Summing up "<<a<<" and "<<b<<" gives ";
	return a+b;
};

UDT::UDT(){
	std::cout<<"\nConstructor invoked\n";
};

UDT::~UDT(){
	std::cout<<"\nObject lifetime completed\n";
};

void UDT::printInfo(){
	std::cout<<"\nInformation\n";
};

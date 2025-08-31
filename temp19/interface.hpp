#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include<iostream>
#include<memory>
// this file is given to client in raw form
// i.e. this code is seen by client hence
// we hide all private members and functions
// from client by using pointer to Impl file
class Entity{
	public:
		void printInfo();
		Entity();
		~Entity();
	private:
		class ImplEntity;
		std::unique_ptr<ImplEntity> p_impl;
};// also later if we need to add some
// data members then it would change
// class layout here like that of temp18
// hence we add all the members into the
// implementation file only.
#endif;
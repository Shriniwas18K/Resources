#include "interface.hpp"
#include <iostream>
#include <memory>
// this file is maintained by developer
// only and the obj binary of this file
// is given to client to dynamically
// load as a library
class Entity::ImplEntity{
	public:int m_x;int m_y;
};
Entity::Entity(){
	p_impl=std::make_unique<ImplEntity>();
	p_impl->m_x=18;
	p_impl->m_y=900;
}
void Entity::printInfo(){
	std::cout<<"x="<<p_impl->m_x<<" y="<<p_impl->m_y;
}
Entity::~Entity(){
}
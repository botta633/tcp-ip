#include "graph.h"
#include <iostream>
interface::interface (){
    this->name = "";
    this->attrNode = nullptr;
    this->link = nullptr;
}

interface::interface(std::string name, GNode &node, Link *link){
    this->name = name;
    this->attrNode = &node;
    this->link = link;
}

GNode::GNode(std::string name){
    this->name = name;
}

GNode *interface::get_nbr_node() const { return this->attrNode; }

std::string interface::getName() const{
    return (this)->name;
}

void GNode::set_interface(interface &intf)
{
    assert((this->interfaceMapper).size() == MAX_INTF_SIZE);
    this->interfaceMapper.insert(std::make_pair(intf.getName(), &intf));
}

std::string GNode::getName()const
{
    return this->name;
}

Link::Link(GNode &src, GNode &dst, std::string intf1Name, std::string intf2Name, unsigned int cost){
    this->cost = cost;
    this->intf1 = interface(intf1Name, src, this);
    this->intf2 = interface(intf2Name, dst, this);
    src.set_interface(this->intf1);
    dst.set_interface(this->intf2);
}

void graph::addNode(GNode &gnode)
{
    std::cout<<"Came here" << std::endl;
    auto x= this->node_list;
    x.removeNode(&gnode);
}

void GNode::setName(std::string name) {
    this->name = name;
}

const std::unordered_map<std::string, interface*>& GNode::getMapper(){ return this->interfaceMapper; }

interface* graph::getInterface(std::string nodeName, std::string interfaceName)const{
    GNode *temp = this->node_list.head;
    while(temp){
        if(temp->getName() == nodeName) {
            auto res = temp->getMapper();
            if(res.find(interfaceName) != res.end())
                return res[interfaceName];
           
            assert("Wrong interface name");
        }
    }
    return nullptr;
}

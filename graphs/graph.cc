#include "graph.h"
#include <iostream>


interface::interface()
{
    this->name = "";
    this->attrNode = nullptr;
    this->link = nullptr;
}

interface::interface(std::string name, GNode &node, Link *link)
{
    this->name = name;
    this->attrNode = &node;
    this->link = link;
}

GNode::GNode(std::string name)
{
    this->name = name;
}

GNode *interface::get_nbr_node() const { return this->attrNode; }

std::string interface::getName() const
{
    return (this)->name;
}

void GNode::set_interface(interface &intf)
{

    assert((this->interfaceMapper).size() <= MAX_INTF_SIZE);
    this->interfaceMapper.insert(std::make_pair(intf.getName(), &intf));
    std::cout << this->interfaceMapper.size() << std::endl;
}

std::string GNode::getName() const
{
    return this->name;
}

Link::Link(GNode &src, GNode &dst, std::string intf1Name, std::string intf2Name, unsigned int cost)
{
    this->cost = cost;
    this->intf1 = interface(intf1Name, src, this);
    this->intf2 = interface(intf2Name, dst, this);
    src.set_interface(this->intf1);
    dst.set_interface(this->intf2);
}

void graph::addNode(GNode &gnode)
{
    // assert the existance of a node with the same name
    assert((this->nodeMapper).find(gnode.getName()) == (this->nodeMapper).end());

    //  store the name as a key and a pointer to the node as the value
    GNode *nodeptr = &gnode;
    (this->nodeMapper)[gnode.getName()] = nodeptr;
}

void GNode::setName(std::string name)
{
    this->name = name;
}

const std::unordered_map<std::string, interface *> &GNode::getMapper() { return this->interfaceMapper; }

interface *graph::getInterface(std::string nodeName, std::string interfaceName)
{
    assert(this->nodeMapper.find(nodeName) != this->nodeMapper.end());
    GNode *nodeptr = this->nodeMapper[nodeName];
    auto mapper = nodeptr->getMapper();

    assert(mapper.find(interfaceName) != mapper.end());

    return mapper[interfaceName];
}
GNode *graph::getNode(std::string Name)
{
    assert(this->nodeMapper.find(Name) != this->nodeMapper.end());
    return this->nodeMapper[Name];
}

void graph::pretty_print()
{
    for (const auto &[key, val] : nodeMapper)
    {
        std::cout << key << std::endl;
    }
}

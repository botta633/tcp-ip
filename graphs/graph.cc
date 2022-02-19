#include "graph.h"
#include <assert.h>
GNode *interface::get_nbr_node() const { return this->attrNode; }

std::string interface::getName() const{
    return (this)->name;
}

void GNode::set_interface(interface &intf)
{
    assert((this->interfaceMapper).size() == MAX_INTF_SIZE);

    interfaceMapper.insert(std::make_pair(intf.getName(), &intf));
    
}

std::string GNode::getName()const
{
    return this->name;
}
void graph::addNode(GNode &gnode)
{
    this->node_list.addNode(&gnode);
}

void GNode::setName(std::string name) {
    this->name = name;
}


interface* graph::getInterface(std::string nodeName, std::string interfaceName)const{
    Node *temp = this->node_list.head;
    while(temp){
        if(temp->getName() == nodeName){
            

        }

    }

}
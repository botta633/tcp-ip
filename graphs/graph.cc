#include "graph.h"
#include <assert.h>
GNode *interface::get_nbr_node() { return this->attrNode; }

void GNode::set_interface(interface &intf)
{

    for (int i = 0; i < MAX_INTF_SIZE; i++)
        if (this->intf[i] == 0)
            this->intf[i] = &intf;

    assert("Node got maximum number of interfaces!");
}

std::string GNode::getname()
{
    return this->name;
}
void graph::addNode(GNode &gnode)
{
    this->node_list.addNode(&gnode);
}
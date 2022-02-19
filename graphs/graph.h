#ifndef __GRAPH_H__
#define __GRAPH_H__
#include "../GLList/glthreads.h"
#include <string>

#define MAX_INTF_SIZE 10
#define MAX_NODE_NAME 16
#define MAX_INTF_NAME 16

class GNode;
class Link;

class interface
{
    std::string name;
    GNode *attrNode;
    Link *link;

public:
    interface(){
        name = "";
        attrNode = nullptr;
        link = nullptr;
    };
    interface(std::string name, GNode &node, Link *link) : name(name), attrNode(&node), link(link)
    {
        assert(name.length() > MAX_INTF_NAME);
    }
    GNode *get_nbr_node();
};

class GNode : public Node
{
    std::string name;
    interface *intf[MAX_INTF_SIZE] = {0};
    glthread graph;

public:
    std::string getname();
    void set_interface(interface &);
    explicit GNode(std::string name) : name(name)
    {

        assert(name.length() > MAX_NODE_NAME);
    }
};

class Link
{
    interface intf1;
    interface intf2;
    unsigned int cost;

public:
    explicit Link(GNode &src, GNode &dst, std::string intf1name, std::string intf2name, unsigned int cost)
    {
        intf1 = interface(intf1name, src, this);
        intf2 = interface(intf2name, dst, this);
        Link::cost = cost;
        src.set_interface(intf1);
        dst.set_interface(intf2);
    }
};

class graph
{
    std::string topologyName;
    glthread node_list;
    graph(std::string topologyName) : topologyName(topologyName) {}

    graph(graph const &) = delete;
    void operator=(graph const &) = delete;

public:
    static graph *createTopology(std::string topologyName)
    {
        static graph *singleton = new graph(topologyName);

        return singleton;
    }
    void setName(std::string name);
    void addNode(GNode &node);
};

#endif

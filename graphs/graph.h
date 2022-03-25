#ifndef GRAPH_H__
#define GRAPH_H__
#include "../GLList/glthreads.h"
#include <string>
#include <unordered_map>
#include <cassert>

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
    interface();
    interface(std::string name, GNode &node, Link *link);   
    GNode *get_nbr_node() const;
    std::string getName() const;
};

class GNode : public Node<GNode>
{
    std::unordered_map<std::string, interface*>interfaceMapper;
    glthread<GNode> graph;
    std::string name;

public:
    std::string getName()const override ;
    void set_interface(interface &);
    explicit GNode(std::string name);
    void setName(std::string name) override;
    const std::unordered_map<std::string, interface*>& getMapper();

};

class Link
{
    interface intf1;
    interface intf2;
    unsigned int cost;

public:
    explicit Link(GNode &src, GNode &dst, std::string intf1name, 
    std::string intf2name, unsigned int cost);

   
};
class graph
{
    std::string topologyName;
    glthread<GNode> node_list;
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
    interface* getInterface(std::string nodeName, std::string interfaceName) const;
};

#endif

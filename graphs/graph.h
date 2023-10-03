#ifndef GRAPH_H__
#define GRAPH_H__
#include <string>
#include <unordered_map>
#include <cassert>
#include <time.h>
#define MAX_INTF_SIZE 10
#define MAX_NODE_NAME 16
#define MAX_INTF_NAME 16
#define IP_LENGTH 15
#define MAC_LENGTH 17

class Link;
class GNode;

class interface
{
    std::string name;
    GNode *attrNode;
    Link *link;
    std::string Mac_address;
    std::string mask;

public:
    interface();
    interface(std::string name, GNode &node, Link *link);
    GNode *get_nbr_node() const;
    std::string getName() const;
    std::string getMac() const;
    void setMac(std::string mac);
    std::string getMask() const;
    void setMask(std::string mask);
};

class GNode
{
    std::unordered_map<std::string, interface *> interfaceMapper;
    std::string name;
    std::string IP;
    bool IsLBConfigured;

public:
    std::string getName() const;
    void set_interface(interface &);
    explicit GNode(std::string name);
    void setName(std::string name);
    const std::unordered_map<std::string, interface *> &getMapper();
    std::string getIp();
    void setIP(std::string IP);
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
    std::unordered_map<std::string, GNode *> nodeMapper;
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
    void pretty_print();
    interface *getInterface(std::string nodeName, std::string interfaceName);
    GNode *getNode(std::string Name);
};

#endif

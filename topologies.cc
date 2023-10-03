#include <iostream>
#include "./graphs/graph.h"

int main()
{
    std::string x = "test topology";

    graph *Topology = graph::createTopology(x);
    GNode src("src");
    GNode dst("dst");
    Topology->addNode(src);
    Topology->addNode(dst);
    Link link(src, dst, "eth0/1", "eth1/1", 5);
    Topology->pretty_print();
    return 0;
}

#include <iostream>
#include "./graphs/graph.h"

int main()
{
    std::string x = "test topology";

    graph *Topology = graph::createTopology(x);
    GNode src(x);
    GNode dst(x);
    Link link(src, dst, "eth0/0", "eth1/0", 5);

}
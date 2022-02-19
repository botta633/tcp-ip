#include <iostream>
#include "graph.h"

int main()
{

    graph *Topology = graph::createTopology("Test Topology");
    GNode src("src node");
    GNode dst("dst node");

    Link link(src, dst, "eth0/0", "eth1/0", 5);

}
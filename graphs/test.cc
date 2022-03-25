#include "graph.h"
#include <iostream>
using namespace std;







int main(){

    graph *Topology = graph::createTopology("Test Topology");
    GNode src("src node");
    GNode dst("dst node");
    Link link(src, dst, "eth0/0", "eth1/0", 5);
    return 0;
}
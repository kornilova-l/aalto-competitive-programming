#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Connection {
public:
    Connection(short recipient, unsigned long long speed) {
        this->recipient = recipient;
        this->speed = speed;
    }

    short getRecipient() {
        return recipient;
    }

    unsigned long long getSpeed() {
        return speed;
    }

    void increaseSpeed(unsigned long long delta) {
        speed += delta;
    }

    void decreaseSpeed(unsigned long long delta) {
        speed -= delta;
    }

private:
    short recipient;
    unsigned long long speed;
};

bool isPathAvailable(Connection connection) ;


void assignFalse(bool array[], int n) ;

void decreaseFlow(std::vector<Connection> *nodes, std::pair<int, unsigned long long> previousNodes[], int N, unsigned long long maxFlow) ;

void readConnections(int m, std::vector<Connection> nodes[]) {
    for (int i = 0; i < m; i++) {
        short a; // computer a
        short b; // computer b
        unsigned long long c; // speed byte/s
        std::cin >> a >> b >> c;
        a -= 1; // indexes start from 1
        b -= 1;
        nodes[a].push_back(*(new Connection(b, c)));
        nodes[b].push_back(*(new Connection(a, 0)));
    }
}

void init(std::queue<int> &q, bool *visited, int N) {
    assignFalse(visited, N);
    visited[0] = true;
    q.push(0);
}

/**
 * Do breadth traverse and find shortest available path
 * find smallest num in path
 * decrease flow in path
 * return this smallest num
 * @param nodes
 * @param N
 * @return
 */
unsigned long long findNewPath(std::vector<Connection> *nodes, int N) {
    std::queue<int> q;
    bool visited[N];
    std::pair<int, unsigned long long> previousNodes[N]; // previous node in shortest path and min flow
    previousNodes[0].second = std::numeric_limits<int>::max(); // assign least flow to infinity
    init(q, visited, N);
    bool lastNodeFound = false;
    while (!q.empty() && !lastNodeFound) {
        int currentIndex = q.front();
        q.pop();
        for (auto connection : nodes[currentIndex]) {
            int nextIndex = connection.getRecipient();
            if (visited[nextIndex] || !isPathAvailable(connection)) {
                continue;
            }
            previousNodes[nextIndex].first = currentIndex;
            previousNodes[nextIndex].second = std::min(previousNodes[currentIndex].second, connection.getSpeed());
            visited[nextIndex] = true;
            if (nextIndex == N - 1) { // if last node
                lastNodeFound = true;
            }
            q.push(nextIndex);
        }
    }
    unsigned long long maxFlow = previousNodes[N - 1].second;
    if (maxFlow != 0) { // if flow is not 0 (path was found)
        decreaseFlow(nodes, previousNodes, N, maxFlow);
        return maxFlow;
    }
    return 0;
}

/**
 * @param nodes not empty array of nodes
 * @param N number of nodes
 * @return max flow
 */
unsigned long long calcMaximumFlow(std::vector<Connection> nodes[], int N) {
    unsigned long long maxFlow = 0;
    while (unsigned long long inc = findNewPath(nodes, N)) {
        maxFlow += inc;
    }
    return maxFlow;
}

int main() {
    int n; // number of computers
    int m; // number of connections
    std::cin >> n >> m;
    std::vector<Connection> nodes[n];
    readConnections(m, nodes);

    std::cout << calcMaximumFlow(nodes, n);

    return 0;
}

Connection *findConnection(std::vector<Connection> &connections, int toNode) {
    for (Connection &connection : connections) {
        if (connection.getRecipient() == toNode) {
            return &connection;
        }
    }
    return 0;
}

void decreaseFlow(std::vector<Connection> *nodes, std::pair<int, unsigned long long> previousNodes[], int N, unsigned long long maxFlow) {
    int currentNode = N - 1;
    while (currentNode > 0) {
        int previousNode = previousNodes[currentNode].first;
        findConnection(nodes[previousNode], currentNode)
                ->decreaseSpeed(maxFlow);
        findConnection(nodes[currentNode], previousNode)
                ->increaseSpeed(maxFlow);
        currentNode = previousNode;
    }
}

void assignFalse(bool array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = false;
    }
}

bool isPathAvailable(Connection connection) {
    return connection.getSpeed() != 0;
}


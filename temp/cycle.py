# 1,2,3
# [[1,2],[2,3]]
[0.5, 0.3]

def find_path(start, end, paths, probs):
    queue_nodes = [start]
    node_edges = {}
    # O(m)
    for i in range(len(paths)):
        first = paths[i][0]
        second = paths[i][1]
        if first in node_edges:
            node_edges[first].append(i)
        else:
            node_edges[first] = [i]
        if second in node_edges:
            node_edges[second].append(i)
        else:
            node_edges[second] = [i]

    res = []
    queue_edges = []
    # for node in queue_nodes:
    queue_edges = node_edges[start]
    while len(queue_nodes) != 0:
        vals = [probs[i] for i in queue_edges]
        min_val = max(vals)
        min_ind = vals.index(min_val)
        queue_edges.remove(queue_edges[min_ind])
        vals.remove(min_val)

        remove_path_ind = queue_edges[min_ind]
        remove_path = paths[remove_path_ind]
        
        res.append(remove_path)
        if remove_path[0] in queue_nodes:
            queue_nodes.remove(remove_path[0])
            queue_edges.append(node_edges[remove_path[1]])
        elif remove_path[1] in queue_nodes:
            queue_nodes.remove(remove_path[1])
            queue_edges.append(node_edges[remove_path[0]])

        if remove_path[1] == end or remove_path[0] == end:
            break
    return res

if __name__ == '__main__':

    paths = [[1,2],[1,3],[1,4],[2,4],[3,4]]
    probs = [0.2, 0.5,0.4,0.5,0.1]
    res = find_path(1,4,paths, probs)
    print(res)
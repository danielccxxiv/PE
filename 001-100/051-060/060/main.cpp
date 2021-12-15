
#include "main.hpp"

int main() {
    prime_node root(-1);
    size_t pos_iter = 0;
    int32_t max_depth = 0;
    while(max_depth < 5) {
        prime<int32_t>::list.push_back(prime<int32_t>::iter.next_prime());
        break;
    }
	return 0;
}

void prime_node_loop(prime_node& base_node, int32_t prime_pos_next, std::vector<prime_node*>& storage) {
    boost::heap::priority_queue<prime_node_pq_wrap, boost::heap::compare<prime_node_c>> queue;
    boost::heap::priority_queue<prime_node_pq_wrap, boost::heap::compare<prime_node_c>>::iterator queue_iter;
    queue.push(prime_node_pq_wrap(base_node));
    prime_node* node_create_ptr;
    prime_node* node_modify_ptr;
    std::stack<prime_node*> next_nodes;
    for(int32_t i = 0; i < prime_pos_next; i++) {
        while(queue.top().val < i) {
            node_modify_ptr = queue.top().node;
            queue.pop();
            node_create_ptr = new prime_node(prime_pos_next, node_modify_ptr);
            (node_modify_ptr->next).push_back(node_create_ptr);
            if((node_create_ptr->level == 5)) {
                storage.push_back(node_create_ptr);
            }
        }
        if(!(connected(i, prime_pos_next))) {
            continue;
        }
        for(queue_iter = queue.begin(); queue_iter != queue.end(); queue_iter++) {
            node_modify_ptr = (*iter).node;
            while(((node_modify_ptr->next)[node_modify_ptr->vec_iter]).prime_pos < i) {
                (node_modify_ptr->vec_iter)++;
            }
            if(((node_modify_ptr->next)[node_modify_ptr->vec_iter]).prime_pos == i) {
                next_nodes.push((node_modify_ptr->next)[node_modify_ptr->vec_iter]);
            }
        }
        while(next_nodes.size() > 0) {
            queue.push(prime_node_pq_wrap(next_nodes.top()));
        }
    }
}

























//

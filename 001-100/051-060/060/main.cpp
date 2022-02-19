
#include "main.hpp"

int main() {
    prime_node root(-1);
    int32_t pos_iter = 0;
    while(pos_iter >= static_cast<int32_t>(prime<int32_t>::list.size())) {
        prime<int32_t>::list.push_back(prime<int32_t>::iter.next_prime());
    }
    int32_t min_sum = -1;
    int32_t temp_sum = 0;
    prime_node* node_trace_ptr;
    std::vector<prime_node*> storage;
    while((min_sum == -1) || (prime<int32_t>::list[pos_iter] < min_sum)) {
        prime_node_loop(root, pos_iter, storage);
        if(storage.size() > 0) {
            for(size_t i = 0; i < storage.size(); i++) {
                node_trace_ptr = storage[i];
                temp_sum = 0;
                while((node_trace_ptr->level) > 0) {
                    temp_sum += prime<int32_t>::list[node_trace_ptr->prime_pos];
                    node_trace_ptr = node_trace_ptr->parent;
                }
                if(min_sum == -1) {
                    min_sum = temp_sum;
                } else {
                    min_sum = std::min(min_sum, temp_sum);
                }
            }
            storage.clear();
        }
        pos_iter++;
        while(pos_iter >= static_cast<int32_t>(prime<int32_t>::list.size())) {
            prime<int32_t>::list.push_back(prime<int32_t>::iter.next_prime());
        }
    }
    std::cout << min_sum << std::endl;
	return 0;
}

void prime_node_loop(prime_node& base_node, int32_t prime_pos_next, std::vector<prime_node*>& storage) {
    boost::heap::priority_queue<prime_node_pq_wrap, boost::heap::compare<prime_node_c>> queue;
    queue.push(prime_node_pq_wrap(&base_node));
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
        for(prime_node_pq_wrap queue_iter: queue) {
            node_modify_ptr = queue_iter.node;
            while((((node_modify_ptr->next)[node_modify_ptr->vec_iter])->prime_pos) < i) {
                (node_modify_ptr->vec_iter)++;
            }
            if((((node_modify_ptr->next)[node_modify_ptr->vec_iter])->prime_pos) == i) {
                next_nodes.push((node_modify_ptr->next)[node_modify_ptr->vec_iter]);
            }
        }
        while(next_nodes.size() > 0) {
            queue.push(prime_node_pq_wrap(next_nodes.top()));
            next_nodes.pop();
        }
    }
    while(!(queue.empty())) {
        node_modify_ptr = queue.top().node;
        queue.pop();
        node_create_ptr = new prime_node(prime_pos_next, node_modify_ptr);
        (node_modify_ptr->next).push_back(node_create_ptr);
        if((node_create_ptr->level == 5)) {
            storage.push_back(node_create_ptr);
        }
    }
    return;
}

bool connected(int32_t i, int32_t j) {
    if((i == -1) || (j == -1)) {
        return true;
    }
    int32_t prime_i = prime<int32_t>::list[i];
    int32_t prime_j = prime<int32_t>::list[j];
    int64_t sum = prime_i * pow_int<int64_t, int32_t>(10, digit_count<int32_t, int32_t>(prime_j)) + prime_j;
    if(!(mr_det(sum))) {
        return false;
    }
    sum = prime_j * pow_int<int64_t, int32_t>(10, digit_count<int32_t, int32_t>(prime_i)) + prime_i;
    return mr_det(sum);
}

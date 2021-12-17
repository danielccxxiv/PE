
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <algorithm>
#include <stack>
#include <vector>

#include <boost/heap/priority_queue.hpp>

#include "../../../Libs/Miller_Rabin_Deterministic/miller_rabin_deterministic.hpp"

#include "../../../Misc/pow_functions.hpp"
#include "../../../Misc/Digit_Manipulation/digit_count.hpp"
#include "../../../Misc/Sequences/prime_sequence.hpp"

typedef struct prime_node {
    int32_t prime_pos;
    int32_t level;
    int32_t vec_iter;
    std::vector<prime_node*> next;
    prime_node* parent;

    prime_node(int32_t prime_pos, prime_node* parent = NULL) {
        this->prime_pos = prime_pos;
        this->parent = parent;
        if(parent) {
            this->level = parent->level + 1;
        } else {
            this->level = 0;
        }
    }

    ~prime_node() {
        for(size_t i = 0; i < next.size(); i++) {
            delete next[i];
        }
        next.clear();
    }
} prime_node;

typedef struct prime_node_pq_wrap {
    prime_node* node;
    int32_t val;

    prime_node_pq_wrap(prime_node* node) {
        this->node = node;
        node->vec_iter = 0;
        if((node->next).size() > 0) {
            this->val = (node->next[(node->next).size() - 1])->prime_pos;
        } else {
            this->val = 0;
        }
    }
} prime_node_pq_wrap;

typedef struct prime_node_c {
    bool operator()(const prime_node_pq_wrap& pn0, const prime_node_pq_wrap& pn1) const {
        return (pn0.val > pn1.val);
    }
} prime_node_c;

void prime_node_loop(prime_node& base_node, int32_t prime_pos_next, std::vector<prime_node*>& storage);
bool connected(int32_t i, int32_t j);

#endif

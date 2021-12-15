
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <vector>

#include <boost/heap/priority_queue.hpp>

// #include "../../../Misc/Miller_Rabin/miller_rabin_deterministic.hpp"
#include "../../../Misc/Sequences/prime_sequence.hpp"

typedef struct prime_node {
    int32_t prime_pos;
    int32_t level;
    std::vector<prime_node*> next;
    int32_t vec_iter;
    prime_node* parent;

    prime_node(int32_t num, prime_node* parent = NULL) {
        this->num = num;
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
            this->val = node->next[(node->next).size() - 1].prime_pos;
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

#endif























//


#include "main.hpp"

int main(int argc, char** argv) {
	u_set s(u_set::bucket_traits(new u_set::bucket_type[hash_size], hash_size));
	u_set s_next(u_set::bucket_traits(new u_set::bucket_type[hash_size],
		hash_size));
	u_set::insert_commit_data s_commit;
	u_set::iterator it;
	std::pair <u_set::iterator, bool> ins;
	group* g = new group();
	s.insert(*g);

	int i, j, total;
	total = N / S2;
	std::memset(Comb, '\0', (N / S1) * S2 * sizeof (long));
	Comb[0] = 1;
	for (i = 1; i < (N / S1); i++) {
		Comb[S2 * i] = 1;
		for (j = 1; j < S2; j++) {
			Comb[S2 * i + j] = Comb[S2 * (i - 1) + (j - 1)] 
				+ Comb[S2 * (i - 1) + j];
		}
	}
	
//	g = new group();
	for(i = 0; i < (N / S2); i++){
		for(it = s.begin(); it != s.end(); it++) {
//			delete g;
//			g = &(*it);
			next_groups(&(*it), s_next, s_commit, ins);
		}
//		while(s.size() > 0) {
//			it = s.begin(); g = &(*it);
//			next_groups(&(*it), s_next, s_commit, ins);
//			s.erase(it);
//			delete g;
//		}
		s.clear();
		s.swap(s_next);
//		std::cout << (N / S2) - i << "\t" << s.size() << std::endl;
	}
	it = s.begin();
	cout << it->num << endl;
	return 0;
}

int next_groups(group* g, u_set& s, u_set::insert_commit_data& s_commit,
	std::pair<u_set::iterator, bool>& ins) {
	int min_size;
	int* k = new int[S1];
	std::memset(k, '\0', S1 * sizeof(int));
	for (min_size = 0; min_size < S1; min_size++) {
		if (g->count[min_size] > 0) {
			g->count[min_size]--;
			if (min_size > 0) {
				g->count[min_size - 1]++;
			}
			break;
		}
	}
	iter_next_group(g, 1, min_size, k, s, s_commit, ins);
	delete g->count;
	return 0;
}

int iter_next_group(group* g, int n, int ll, int* k, u_set& s,
	u_set::insert_commit_data& s_commit, std::pair<u_set::iterator,
	bool>& ins) {
//	std::cout << g->total << "\t" << n << "\t" << ll << std::endl;
	if (n == S2) {
		group* next_g = new group(g);
		next_g->total -= 1;
		int i;
		for (i = 0; i < S1; i++) {
			if (k[i] > 0) {
				next_g->num *= Comb[S2 * next_g->count[i] + k[i]];
//				std::cout << "Comb(" << next_g->count[i] << ", " << k[i] << "):\t" << Comb[S2 * next_g->count[i] + k[i]] << std::endl;
				next_g->num %= m;
				next_g->num *= (powm(i + 1, k[i], m));
				next_g->num %= m;
				next_g->count[i] -= k[i];
				if(i != 0) {
					next_g->count[i - 1] += k[i];
				}
			}
		}
		ins = s.insert_check(*next_g, s_commit);
		if (ins.second) {
			s.insert_commit(*next_g, s_commit);
		} else {
			(ins.first)->num += next_g->num;
			(ins.first)->num %= m;
		}
		return 0;
	}
	if (ll == S1) {
		return 0;
	}
	if (g->count[ll] > k[ll]) {
		k[ll]++;
		iter_next_group(g, n + 1, ll, k, s, s_commit, ins);
		k[ll]--;
	}
	iter_next_group(g, n, ll + 1, k, s, s_commit, ins);
	return 0;
}

int print_group(group* g) {
	int i;
	for(i = 0; i < S1; i++) {
		std::cout << g->count[i] << "\t";
	}
	std::cout << "\t" << g->num << std::endl;
	return 0;
}

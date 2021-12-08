
#include "main.hpp"

int main(int argc, char** argv) {
	set<wall, compare<wall_c> > s;
	set<wall, compare<wall_c> >::insert_commit_data s_commit;
	set<wall, compare<wall_c> >::iterator it;
	pair < set<wall, compare<wall_c> >::iterator, bool> ins;
	pair<wall*, int>* p = new pair<wall*, int>(NULL, 0);
	wall* w = new wall();
	s.insert(*w);

	while(not s.empty()) {
		it = s.begin();
		w = &(*it);
		s.erase(it);
		if(w->arr[H - 1] == N) {
			break;
		}
		UUU.push(make_pair(w, 0));
		next_walls();
		while(not FFF.empty()) {
			FFF.pop(*p);
			ins = s.insert_check(*(p->first), s_commit);
			if(ins.second) {
				s.insert_commit(*(p->first), s_commit);
			} else {
				(ins.first)->num += (p->first)->num;
				delete p->first;
			}
		}
	}
	cout << w->num << endl;
	return 0;
}

int next_walls() {
	pair<wall*, int>* p = new pair<wall*, int>(NULL, 0);
	wall* t;
	wall* x;
	int h;
	while(not UUU.empty()) {
		UUU.pop(*p);
		t = p->first;
		h = p->second;
		if(h == H) {
			FFF.push(make_pair(t, H));
		} else if(t->arr[h] < (N - 4)) {
			if(h == 0) {
				x = new wall(t->arr, t->num);
				if(t->arr[0] == (t->arr[1] + 1)) {
					t->arr[0] += 2;
					UUU.push(make_pair(t, 1));
					x->arr[0] += 3;
					UUU.push(make_pair(x, 1));
				} else if(t->arr[0] == (t->arr[1] + 2)) {
					t->arr[0] += 2;
					t->arr[1] += 3;
					UUU.push(make_pair(t, 2));
					x->arr[0] += 3;
					x->arr[1] += 3;
					UUU.push(make_pair(x, 2));
				} else {
					t->arr[0] = 2;
					UUU.push(make_pair(t, H));
					x->arr[0] = 3;
					x->arr[1] = 2;
					UUU.push(make_pair(x, H));
				}
			} else if(h < (H - 1)) {
				if((t->arr[h] + 4) == t->arr[h - 1]) {
					if(t->arr[h] == (t->arr[h + 1] + 1)) {
						x = new wall(t->arr, t->num);
						t->arr[h] += 2;
						UUU.push(make_pair(t, h + 1));
						x->arr[h] += 3;
						UUU.push(make_pair(x, h + 1));
					} else if(t->arr[h] == (t->arr[h + 1] + 2)) {
						x = new wall(t->arr, t->num);
						t->arr[h] += 2;
						t->arr[h + 1] += 3;
						UUU.push(make_pair(t, h + 2));
						x->arr[h] += 3;
						x->arr[h + 1] += 3;
						UUU.push(make_pair(x, h + 2));
					} else {
						t->arr[h] = 3;
						t->arr[h + 1] = 2;
						UUU.push(make_pair(t, H));
					}
				} else if((t->arr[h] + 3) == t->arr[h - 1]) {
					t->arr[h] += 2;
					if(t->arr[h] == (t->arr[h + 1] + 4)) {
						t->arr[h + 1] += 3;
						UUU.push(make_pair(t, h + 2));
					} else if(t->arr[h] == (t->arr[h + 1] + 3)) {
						UUU.push(make_pair(t, h + 1));
					} else {
						UUU.push(make_pair(t, H));
					}
				} else if((t->arr[h] + 5) == t->arr[h - 1]) {
					t->arr[h] += 3;
					if(t->arr[h] == (t->arr[h + 1] + 5)) {
						t->arr[h + 1] += 3;
						UUU.push(make_pair(t, h + 2));
					} else if(t->arr[h] == (t->arr[h + 1] + 4)) {
						UUU.push(make_pair(t, h + 1));
					} else {
						t->arr[h + 1] = 2;
						UUU.push(make_pair(t, H));
					}
				} else {
					UUU.push(make_pair(t, H));
				}
			} else {
				if((t->arr[h] + 4) == t->arr[h - 1]) {
					x = new wall(t->arr, t->num);
					t->arr[h] += 2;
					UUU.push(make_pair(t, H));
					x->arr[h] += 3;
					UUU.push(make_pair(x, H));
				} else if((t->arr[h] + 3) == t->arr[h - 1]) {
					t->arr[h] += 2;
					UUU.push(make_pair(t, H));
				} else if((t->arr[h] + 5) == t->arr[h - 1]) {
					t->arr[h] += 3;
					UUU.push(make_pair(t, H));
				} else {
					UUU.push(make_pair(t, H));
				}
			}
		} else if(t->arr[h] == (N - 4)) {
			if((h + 1) == H) {
				t->arr[h] = N;
				UUU.push(make_pair(t, H));
			} else if(t->arr[h + 1] == (N - 5)) {
				t->arr[h] = N - 2;
				UUU.push(make_pair(t, h + 1));
			} else {
				t->arr[h] = N;
				t->arr[h + 1] = N - 3;
				UUU.push(make_pair(t, h + 2));
			}
		} else if(t->arr[h] == (N - 3)) {
			t->arr[h] = N;
			if((h + 1) == H) {
				UUU.push(make_pair(t, H));
			} else if(t->arr[h + 1] == (N - 5)) {
				t->arr[h + 1] = N - 2;
				UUU.push(make_pair(t, h + 2));
			} else {
				UUU.push(make_pair(t, h + 1));
			}
		} else if(t->arr[h] == (N - 2)) {
			t->arr[h] = N;
			if((h + 1) == H) {
				UUU.push(make_pair(t, H));
			} else if(t->arr[h + 1] == (N - 3)) {
				t->arr[h + 1] = N;
				UUU.push(make_pair(t, h + 2));
			} else {
				delete t;
				continue;
			}
		} else if(t->arr[h] == (N - 1)) {
			delete t;
			continue;
		} else if(t->arr[h] == N) {
			UUU.push(make_pair(t, h + 1));
		}
	}
	delete p;
	return 0;
}

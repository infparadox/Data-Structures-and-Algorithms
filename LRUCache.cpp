#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    private :
    int cacheSize;
    unordered_map<int, list<int>::iterator> listAddressMap;
    list<int>cache;
    
    public :
    LRUCache(int si) {
        cacheSize = si;
    }
    
    bool findElement(int x) {
        bool fl = 1;
        if(listAddressMap.find(x) !=listAddressMap.end()) { //found
            cache.erase(listAddressMap[x]);
        } else {
            fl = 0;
            if(cache.size() == cacheSize) {
                int temp = cache.back();
                cache.pop_back();
                listAddressMap.erase(temp);
            }
        }
        cache.push_front(x);
        listAddressMap[x] = cache.begin();
        return fl;
    }
    
    void display() {
        for(int x : cache) {
            cout << x << " ";
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(0);
    int si;
    cin >> si;
    LRUCache cache(si);
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cache.findElement(x);
        cache.display();
    }
    return 0;
}

class BrowserHistory {
public:
    stack<string> browserSt, frwdSt;
    BrowserHistory(string homepage) { browserSt.push(homepage); }

    void visit(string url) {
        while (!frwdSt.empty()) {
            frwdSt.pop();
        }
        browserSt.push(url);
    }

    string back(int steps) {
        while (steps--) {
            if (browserSt.size() > 1) {
                frwdSt.push( browserSt.top());
                 browserSt.pop();
            } else break;   
        }
        return browserSt.top();
    }

    string forward(int steps) {
        while (steps--) {
            if (frwdSt.size() > 0) {
                browserSt.push(frwdSt.top());
                frwdSt.pop();
            }
        }
        return browserSt.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
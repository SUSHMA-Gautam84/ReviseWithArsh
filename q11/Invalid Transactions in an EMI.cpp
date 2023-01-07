lass Solution {
public:
    static vector<string> invalidTransactions(const vector<string>& transactions) {
        static const auto stoi = [] (string_view s) {
            int ret = 0;
            for (auto c : s)
                ret = 10 * ret + c - '0';
            return ret;
        };

        const int n = size(transactions);
		
        int flag = 0;
        vector<string_view> name;
        vector<int> time;
        vector<int> amount;
        vector<string_view> city;
        
		
        for (string_view str : transactions) {
            int pos = str.find(',');
            name.emplace_back(str.substr(0, pos));
            str = str.substr(pos + 1);
            pos = str.find(',');
            time.emplace_back(stoi(str.substr(0, pos)));
            str = str.substr(pos + 1);
            pos = str.find(',');
            amount.emplace_back(stoi(str.substr(0, pos)));
            city.emplace_back(str.substr(pos + 1));
        }

        vector<string> ret;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (amount[i] >= 1000 || name[i] == name[j] && city[i] != city[j] && abs(time[i] - time[j]) <= 60) {
                    ret.emplace_back(transactions[i]);
                    break;
                }
		
        return ret;
    }
};
